#ifndef VOLUMEBUTTON_H
#define VOLUMEBUTTON_H

#include <QToolButton>

QT_FORWARD_DECLARE_CLASS(QMenu)
QT_FORWARD_DECLARE_CLASS(QLabel)
QT_FORWARD_DECLARE_CLASS(QSlider)

class VolumeButton : public QToolButton //定义音量工具按钮
{
  Q_OBJECT
  Q_PROPERTY(int volume READ volume WRITE setVolume NOTIFY volumeChanged)

public:
  explicit VolumeButton(QWidget *parent = nullptr);

  int volume() const;   //音量值

public slots:
  void increaseVolume();    //增大音量
  void descreaseVolume();   //减小音量
  void setVolume(int volume);   //设置音量值
  void stylize();   //格式化

signals:
  void volumeChanged(int volume);   //音量改变信号

private:
  QMenu *menu = nullptr;    //菜单
  QLabel *label = nullptr;  //标签
  QSlider *slider = nullptr;    //滑块
};

#endif // VOLUMEBUTTON_H
