#include "musicplayer.h"
#include "volumebutton.h"

#include <QtWidgets>
#include <QtWinExtras>

MusicPlayer::MusicPlayer(QWidget *parent) : QWidget(parent)
{
    setFixedSize(1020,80);  //固定窗口大小

    createWidgets();
    createShortcuts();
    createJumpList();

    connect(&mediaPlayer, &QMediaPlayer::positionChanged, this, &MusicPlayer::updatePosition);
    connect(&mediaPlayer, &QMediaPlayer::durationChanged, this, &MusicPlayer::updateDuration);
    //connect(&mediaPlayer, &QMediaObject::metaDataAvailableChanged, this, &MusicPlayer::updateInfo);

    typedef void(QMediaPlayer::*ErrorSignal)(QMediaPlayer::Error);
    connect(&mediaPlayer, static_cast<ErrorSignal>(&QMediaPlayer::error),
          this, &MusicPlayer::handleError);
    connect(&mediaPlayer, &QMediaPlayer::stateChanged,
          this, &MusicPlayer::updateState);

    stylize();
    setAcceptDrops(true);
}

QStringList MusicPlayer::supportedMimeTypes()
{
  QStringList result = QMediaPlayer::supportedMimeTypes();
  if (result.isEmpty())
      result.append(QStringLiteral("audio/mpeg"));
  return result;
}

void MusicPlayer::openFile()
{
  QFileDialog fileDialog(this);
  fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
  fileDialog.setWindowTitle(tr("Open File"));
  fileDialog.setMimeTypeFilters(MusicPlayer::supportedMimeTypes());
  fileDialog.setDirectory(QStandardPaths::standardLocations(QStandardPaths::MusicLocation).value(0, QDir::homePath()));
  if (fileDialog.exec() == QDialog::Accepted)
      playUrl(fileDialog.selectedUrls().constFirst());
  Url = fileDialog.selectedUrls();
}

void MusicPlayer::playUrl(const QUrl &url)
{
  playButton->setEnabled(true);
  if (url.isLocalFile()) {
      const QString filePath = url.toLocalFile();
      setWindowFilePath(filePath);
      infoLabel->setText(QDir::toNativeSeparators(filePath));
      fileName = QFileInfo(filePath).fileName();
  } else {
      setWindowFilePath(QString());
      infoLabel->setText(url.toString());
      fileName.clear();
  }
  mediaPlayer.setMedia(url);
  mediaPlayer.play();
}

void MusicPlayer::togglePlayback()
{
  if (mediaPlayer.mediaStatus() == QMediaPlayer::NoMedia)
      openFile();
  else if (mediaPlayer.state() == QMediaPlayer::PlayingState)
      mediaPlayer.pause();
  else
      mediaPlayer.play();
}

void MusicPlayer::seekForward()
{
  positionSlider->triggerAction(QSlider::SliderPageStepAdd);
}

void MusicPlayer::seekBackward()
{
  positionSlider->triggerAction(QSlider::SliderPageStepSub);
}

bool MusicPlayer::event(QEvent *event)
{
  if (event->type() == QWinEvent::CompositionChange || event->type() == QWinEvent::ColorizationChange)
      stylize();
  return QWidget::event(event);
}

static bool canHandleDrop(const QDropEvent *event)
{
  const QList<QUrl> urls = event->mimeData()->urls();
  if (urls.size() != 1)
      return false;
  QMimeDatabase mimeDatabase;
  return MusicPlayer::supportedMimeTypes().
      contains(mimeDatabase.mimeTypeForUrl(urls.constFirst()).name());
}

void MusicPlayer::dragEnterEvent(QDragEnterEvent *event)
{
  event->setAccepted(canHandleDrop(event));
}

void MusicPlayer::dropEvent(QDropEvent *event)
{
  event->accept();
  playUrl(event->mimeData()->urls().constFirst());
}

void MusicPlayer::mousePressEvent(QMouseEvent *event)
{
  offset = event->globalPos() - pos();
  event->accept();
}

void MusicPlayer::mouseMoveEvent(QMouseEvent *event)
{
  move(event->globalPos() - offset);
  event->accept();
}

void MusicPlayer::mouseReleaseEvent(QMouseEvent *event)
{
  offset = QPoint();
  event->accept();
}

void MusicPlayer::stylize()
{
  if (QtWin::isCompositionEnabled()) {
      QtWin::extendFrameIntoClientArea(this, -1, -1, -1, -1);
      setAttribute(Qt::WA_TranslucentBackground, true);
      setAttribute(Qt::WA_NoSystemBackground, false);
      setStyleSheet(QStringLiteral("MusicPlayer { background: transparent; }"));
  } else {
      QtWin::resetExtendedFrame(this);
      setAttribute(Qt::WA_TranslucentBackground, false);
      setStyleSheet(QStringLiteral("MusicPlayer { background: %1; }").arg(QtWin::realColorizationColor().name()));
  }
  volumeButton->stylize();
}

void MusicPlayer::updateState(QMediaPlayer::State state)
{
  if (state == QMediaPlayer::PlayingState) {
      playButton->setToolTip(tr("Pause"));
      playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
  } else {
      playButton->setToolTip(tr("Play"));
      playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
  }
}

static QString formatTime(qint64 timeMilliSeconds)
{
  qint64 seconds = timeMilliSeconds / 1000;
  const qint64 minutes = seconds / 60;
  seconds -= minutes * 60;
  return QStringLiteral("%1:%2")
      .arg(minutes, 2, 10, QLatin1Char('0'))
      .arg(seconds, 2, 10, QLatin1Char('0'));
}

void MusicPlayer::updatePosition(qint64 position)
{
  positionSlider->setValue(position);
  positionLabel->setText(formatTime(position));
}

void MusicPlayer::updateDuration(qint64 duration)
{
  positionSlider->setRange(0, duration);
  positionSlider->setEnabled(duration > 0);
  positionSlider->setPageStep(duration / 10);
  updateInfo();
}

void MusicPlayer::setPosition(int position)
{
  // avoid seeking when the slider value change is triggered from updatePosition()
  if (qAbs(mediaPlayer.position() - position) > 99)
      mediaPlayer.setPosition(position);
}

void MusicPlayer::updateInfo()
{
  QStringList info;
  if (!fileName.isEmpty())
      info.append(fileName);
  if (mediaPlayer.isMetaDataAvailable()) {
      QString author = mediaPlayer.metaData(QStringLiteral("Author")).toString();
      if (!author.isEmpty())
          info.append(author);
      QString title = mediaPlayer.metaData(QStringLiteral("Title")).toString();
      if (!title.isEmpty())
          info.append(title);
  }
  times = formatTime(mediaPlayer.duration());
  info.append(formatTime(mediaPlayer.duration()));
  infoLabel->setText(info.join(tr(" - ")));
}

void MusicPlayer::handleError()
{
  playButton->setEnabled(false);
  const QString errorString = mediaPlayer.errorString();
  infoLabel->setText(errorString.isEmpty()
                     ? tr("Unknown error #%1").arg(int(mediaPlayer.error()))
                     : tr("Error: %1").arg(errorString));
}

void MusicPlayer::updateTaskbar()
{
  switch (mediaPlayer.state()) {
  case QMediaPlayer::PlayingState:
      taskbarButton->setOverlayIcon(style()->standardIcon(QStyle::SP_MediaPlay));
      taskbarProgress->show();
      taskbarProgress->resume();
      break;
  case QMediaPlayer::PausedState:
      taskbarButton->setOverlayIcon(style()->standardIcon(QStyle::SP_MediaPause));
      taskbarProgress->show();
      taskbarProgress->pause();
      break;
  case QMediaPlayer::StoppedState:
      taskbarButton->setOverlayIcon(style()->standardIcon(QStyle::SP_MediaStop));
      taskbarProgress->hide();
      break;
  }
}

void MusicPlayer::updateThumbnailToolBar()
{
  playToolButton->setEnabled(mediaPlayer.duration() > 0);
  backwardToolButton->setEnabled(mediaPlayer.position() > 0);
  forwardToolButton->setEnabled(mediaPlayer.position() < mediaPlayer.duration());

  if (mediaPlayer.state() == QMediaPlayer::PlayingState) {
      playToolButton->setToolTip(tr("Pause"));
      playToolButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
  } else {
      playToolButton->setToolTip(tr("Play"));
      playToolButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
  }
}

void MusicPlayer::createWidgets()
{
  playButton = new QToolButton(this);
  playButton->setEnabled(false);
  playButton->setToolTip(tr("Play"));
  playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
  connect(playButton, &QAbstractButton::clicked, this, &MusicPlayer::togglePlayback);

  QAbstractButton *openButton = new QToolButton(this);
  openButton->setText(tr("..."));
  openButton->setToolTip(tr("Open a file..."));
  openButton->setFixedSize(playButton->sizeHint());
  connect(openButton, &QAbstractButton::clicked, this, &MusicPlayer::openFile);

  volumeButton = new VolumeButton(this);
  volumeButton->setToolTip(tr("Adjust volume"));
  volumeButton->setVolume(mediaPlayer.volume());
  connect(volumeButton, &VolumeButton::volumeChanged, &mediaPlayer, &QMediaPlayer::setVolume);

  positionSlider = new QSlider(Qt::Horizontal, this);
  positionSlider->setEnabled(false);
  positionSlider->setToolTip(tr("Seek"));
  connect(positionSlider, &QAbstractSlider::valueChanged, this, &MusicPlayer::setPosition);

  infoLabel = new QLabel(this);
  positionLabel = new QLabel(tr("00:00"), this);
  positionLabel->setMinimumWidth(positionLabel->sizeHint().width());

  QBoxLayout *controlLayout = new QHBoxLayout;
  controlLayout->setMargin(0);
  controlLayout->addWidget(openButton);
  controlLayout->addWidget(playButton);
  controlLayout->addWidget(positionSlider);
  controlLayout->addWidget(positionLabel);
  controlLayout->addWidget(volumeButton);

  QBoxLayout *mainLayout = new QVBoxLayout(this);
  mainLayout->addWidget(infoLabel);
  mainLayout->addLayout(controlLayout);
}

void MusicPlayer::createShortcuts()
{
  QShortcut *quitShortcut = new QShortcut(QKeySequence::Quit, this);
  connect(quitShortcut, &QShortcut::activated, QCoreApplication::quit);

  QShortcut *openShortcut = new QShortcut(QKeySequence::Open, this);
  connect(openShortcut, &QShortcut::activated, this, &MusicPlayer::openFile);

  QShortcut *toggleShortcut = new QShortcut(Qt::Key_Space, this);
  connect(toggleShortcut, &QShortcut::activated, this, &MusicPlayer::togglePlayback);

  QShortcut *forwardShortcut = new QShortcut(Qt::Key_Right, this);
  connect(forwardShortcut, &QShortcut::activated, this, &MusicPlayer::seekForward);

  QShortcut *backwardShortcut = new QShortcut(Qt::Key_Left, this);
  connect(backwardShortcut, &QShortcut::activated, this, &MusicPlayer::seekBackward);

  QShortcut *increaseShortcut = new QShortcut(Qt::Key_Up, this);
  connect(increaseShortcut, &QShortcut::activated, volumeButton, &VolumeButton::increaseVolume);

  QShortcut *decreaseShortcut = new QShortcut(Qt::Key_Down, this);
  connect(decreaseShortcut, &QShortcut::activated, volumeButton, &VolumeButton::descreaseVolume);
}

void MusicPlayer::createJumpList()
{
  QWinJumpList jumplist;
  jumplist.recent()->setVisible(true);
}
