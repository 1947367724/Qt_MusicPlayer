#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QWidget>
#include <QtMultimedia/QMediaPlayer>

class VolumeButton;     //音量按钮

QT_FORWARD_DECLARE_CLASS(QLabel)    //提前声明QLabel
QT_FORWARD_DECLARE_CLASS(QSlider)   //提前声明QSlider
QT_FORWARD_DECLARE_CLASS(QAbstractButton)   //提前声明QAbstractButton
QT_FORWARD_DECLARE_CLASS(QWinTaskbarButton) //提前声明QWinTaskbarButton
QT_FORWARD_DECLARE_CLASS(QWinTaskbarProgress)   //提前声明QWinTaskbarProgress
QT_FORWARD_DECLARE_CLASS(QWinThumbnailToolBar)  //提前声明QWinThumbnailToolBar
QT_FORWARD_DECLARE_CLASS(QWinThumbnailToolButton)   //提前声明QWinThumbnailToolButton


class MusicPlayer : public QWidget       //创建QWidget对象MusicPlayer
{
  Q_OBJECT
public:         //公用成员
  explicit MusicPlayer(QWidget *parent = nullptr);  //MusicPlayer构造函数 创建MusicPlayer对象时自动执行

  static QStringList supportedMimeTypes();  //支持的文件类型
  static QStringList supportedSuffixes();   //支持的后缀
  QMediaPlayer mediaPlayer;     //播放源对象
  QString times;
  QList<QUrl> Url;

public slots:           //公用槽函数
  void openFile();      //打开文件
  void playUrl(const QUrl& url);    //播放链接
  void togglePlayback();    //  重新播放
  void seekForward();   //前进
  void seekBackward();  //后退

protected:  //保护成员  定义了一些事件来做信号
  bool event(QEvent *event) override;   //重写事件函数 override代表重写
  void dragEnterEvent(QDragEnterEvent *event) override; //重写拖动进入事件函数 将音乐文件拖入
  void dropEvent(QDropEvent *event) override;   //重写拖动函数
  void mousePressEvent(QMouseEvent *event) override;    //重写鼠标按压函数
  void mouseMoveEvent(QMouseEvent *event) override; //重写鼠标移动函数
  void mouseReleaseEvent(QMouseEvent *event) override;  //重写鼠标释放函数

private slots:      //私有槽函数
  void stylize();   //程序化
  void updateState(QMediaPlayer::State state);  //更新状态
  void updatePosition(qint64 position);     //更新位置
  void updateDuration(qint64 duration);     //更新持续时间
  void setPosition(int position);   //定位坐标
  void updateInfo();    //  更新信息
  void handleError();   // 处理错误

  void updateTaskbar(); //更新任务栏
  void updateThumbnailToolBar();   //更新缩略工具栏

private:        //私有成员
  void createWidgets(); //创建窗口
  void createShortcuts();   //创建捷径
  void createJumpList();    //跳转列表
  void createTaskbar();     //创建任务工具栏
  void createThumbnailToolBar();    //创建缩略图工具栏

  QWinTaskbarButton *taskbarButton = nullptr;   //创建任务栏按钮
  QWinTaskbarProgress *taskbarProgress = nullptr;   //任务栏中的进度指示器
  QWinThumbnailToolBar *thumbnailToolBar = nullptr;    //操作窗口缩略图工具栏
  QWinThumbnailToolButton *playToolButton = nullptr;    //缩略图播放按钮
  QWinThumbnailToolButton *forwardToolButton = nullptr;    //缩略图前进按钮
  QWinThumbnailToolButton *backwardToolButton = nullptr;    //缩略图后退按钮


  QAbstractButton *playButton = nullptr;    //播放按钮
  VolumeButton *volumeButton = nullptr; //音量按钮
  QSlider *positionSlider = nullptr;    //定位滑块
  QLabel *positionLabel = nullptr;     //定位标签
  QLabel *infoLabel = nullptr;  //信息标签
  QPoint offset;    //  偏移坐标
  QString fileName; //文件名字
};

#endif // MUSICPLAYER_H
