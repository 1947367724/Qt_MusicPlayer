#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QToolButton>
#include <QListWidgetItem>
#include "musicplayer.h"
#include <QStringList>
#include <QGridLayout>
#include <QMediaPlaylist>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class sing_message
{
public:
    QString name;   //歌名
    QString singer;   //歌手
    QString Album;   //专辑
    QString time;   //时长
    sing_message(QString a,QString b,QString c,QString d):name(a),singer(b),Album(c),time(d){}
    sing_message(){}
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    sing_message message;
    MusicPlayer player;
    QMediaPlaylist *playerlist;

private:
    Ui::MainWindow *ui;
    QLabel *name;   //歌名
    QLabel *singer;   //歌手
    QLabel *Album;   //专辑
    QLabel *time;   //时长
    int n;

    QToolButton *playBtn;   //播放按钮
    QToolButton *addBtn;      //添加按钮
    QToolButton *downloadBtn; //下载按钮
    QToolButton *moreBtn; //更多操作按钮



    void Connect_page();        //按钮连接页面
    void Connect_button();
    void Add_ListWidgetItem(sing_message &message, QListWidget *&Widget); //添加歌曲信息到页面1




};
#endif // MAINWINDOW_H
