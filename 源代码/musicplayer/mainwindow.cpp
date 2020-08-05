#include "mainwindow.h"
#include "musicplayer.h"
#include "ui_mainwindow.h"
#include <QMovie>
#include <QGridLayout>
#include <QListWidgetItem>
#include <QLabel>
#include <QFileDialog>
#include <QPushButton>
#include <QtMultimedia/QMediaMetaData>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player.move(170,780);
    player.setParent(this);

    connect(ui->actionb_2, &QAction::triggered, [=](){
        player.openFile();
    });

    Connect_button();


    setFixedSize(1200,900);
    setWindowTitle("Music");
    setWindowIcon(QIcon(":/image/blue.png"));


    connect(ui->action2_3,&QAction::triggered,[=](){
        ui->centralwidget->setStyleSheet("QWidget{background-image:url(:/image/01.png);}");

        ui->groupBox->setStyleSheet("QGroupBox{border:none;color: rgb(255,255,255);}QPushButton{border:none}");
        ui->groupBox_2->setStyleSheet("QGroupBox{border:none;color: rgb(255,255,255);}QPushButton{border:none}");
        ui->groupBox_3->setStyleSheet("QGroupBox{border:none;color: rgb(255,255,255);}QPushButton{border:none}");
    });
    connect(ui->action1_8,&QAction::triggered,[=](){
        ui->centralwidget->setStyleSheet("QWidget{background-image:url();}");
        ui->groupBox->setStyleSheet("QGroupBox{border:none;color: rgb(171,171,171);}QPushButton{background-color: rgb(240,240,240);border:none}");
        ui->groupBox_2->setStyleSheet("QGroupBox{border:none;color: rgb(171,171,171);}QPushButton{background-color: rgb(240,240,240);border:none}");
        ui->groupBox_3->setStyleSheet("QGroupBox{border:none;color: rgb(171,171,171);}QPushButton{background-color: rgb(240,240,240);border:none}");
    });
    connect(ui->action3_5,&QAction::triggered,[=](){
        ui->centralwidget->setStyleSheet("QWidget{background-image:url(:/image/02.png);}");
        ui->groupBox->setStyleSheet("QGroupBox{border:none;color: rgb(0,0,0);}QPushButton{border:none}");
        ui->groupBox_2->setStyleSheet("QGroupBox{border:none;color: rgb(0,0,0);}QPushButton{border:none}");
        ui->groupBox_3->setStyleSheet("QGroupBox{border:none;color: rgb(0,0,0);}QPushButton{border:none}");
    });
    connect(ui->actiona_4,&QAction::triggered,[=](){
        QMessageBox::information(this,"关于作者","这家伙很懒，什么都没有留下");
    });
    connect(ui->pushButton_25,&QPushButton::clicked,[=](){
        QMessageBox::information(this,"提示","这是个摆设");
    });
    connect(ui->pushButton_26,&QPushButton::clicked,[=](){
        QMessageBox::information(this,"提示","这也是个摆设");
    });
    connect(ui->pushButton_27,&QPushButton::clicked,[=](){
        QMessageBox::information(this,"提示","这还是个摆设");
    });
    ui->groupBox->setStyleSheet("QGroupBox{border:none;color: rgb(171,171,171);}QPushButton{background-color: rgb(248,248,248);border:none}");  //这个是去掉groupBox中的所有QGroupBox的边框；
    ui->groupBox_2->setStyleSheet("QGroupBox{border:none;color: rgb(171,171,171);}QPushButton{background-color: rgb(248,248,248);border:none}");
    ui->groupBox_3->setStyleSheet("QGroupBox{border:none;color: rgb(171,171,171);}QPushButton{background-color: rgb(248,248,248);border:none}");
    ui->groupBox_5->setStyleSheet("QGroupBox{border:none;}");
    ui->listWidget_13->setAutoScroll(true);    //滚动长条

    Connect_page();


}

void MainWindow::Connect_button()
{
    connect(ui->actiona_5, &QAction::triggered ,[=](){
        sing_message message;
        message.name = player.mediaPlayer.metaData(QMediaMetaData::Title).toString();
        message.singer = player.mediaPlayer.metaData(QMediaMetaData::Author).toString();
        message.Album = player.mediaPlayer.metaData(QMediaMetaData::AlbumTitle).toString();
        message.time= player.times;
        Add_ListWidgetItem(message,ui->listWidget_13);
    });
    connect(ui->action1_6, &QAction::triggered ,[=](){
        sing_message message;
        message.name = player.mediaPlayer.metaData(QMediaMetaData::Title).toString();
        message.singer = player.mediaPlayer.metaData(QMediaMetaData::Author).toString();
        message.Album = player.mediaPlayer.metaData(QMediaMetaData::AlbumTitle).toString();
        message.time= player.times;
        Add_ListWidgetItem(message,ui->listWidget_14);
    });
    connect(ui->action2_4, &QAction::triggered ,[=](){
        sing_message message;
        message.name = player.mediaPlayer.metaData(QMediaMetaData::Title).toString();
        message.singer = player.mediaPlayer.metaData(QMediaMetaData::Author).toString();
        message.Album = player.mediaPlayer.metaData(QMediaMetaData::AlbumTitle).toString();
        message.time= player.times;
        Add_ListWidgetItem(message,ui->listWidget_15);
    });
    connect(ui->action3_3, &QAction::triggered ,[=](){
        sing_message message;
        message.name = player.mediaPlayer.metaData(QMediaMetaData::Title).toString();
        message.singer = player.mediaPlayer.metaData(QMediaMetaData::Author).toString();
        message.Album = player.mediaPlayer.metaData(QMediaMetaData::AlbumTitle).toString();
        message.time= player.times;
        Add_ListWidgetItem(message,ui->listWidget_16);
    });
    connect(ui->action4_3, &QAction::triggered ,[=](){
        sing_message message;
        message.name = player.mediaPlayer.metaData(QMediaMetaData::Title).toString();
        message.singer = player.mediaPlayer.metaData(QMediaMetaData::Author).toString();
        message.Album = player.mediaPlayer.metaData(QMediaMetaData::AlbumTitle).toString();
        message.time= player.times;
        Add_ListWidgetItem(message,ui->listWidget_17);
    });
    connect(ui->action5_2, &QAction::triggered ,[=](){
        sing_message message;
        message.name = player.mediaPlayer.metaData(QMediaMetaData::Title).toString();
        message.singer = player.mediaPlayer.metaData(QMediaMetaData::Author).toString();
        message.Album = player.mediaPlayer.metaData(QMediaMetaData::AlbumTitle).toString();
        message.time= player.times;
        Add_ListWidgetItem(message,ui->listWidget_18);
    });
    connect(ui->action6_2, &QAction::triggered ,[=](){
        sing_message message;
        message.name = player.mediaPlayer.metaData(QMediaMetaData::Title).toString();
        message.singer = player.mediaPlayer.metaData(QMediaMetaData::Author).toString();
        message.Album = player.mediaPlayer.metaData(QMediaMetaData::AlbumTitle).toString();
        message.time= player.times;
        Add_ListWidgetItem(message,ui->listWidget_19);
    });
    connect(ui->action1_7, &QAction::triggered ,[=](){
        sing_message message;
        message.name = player.mediaPlayer.metaData(QMediaMetaData::Title).toString();
        message.singer = player.mediaPlayer.metaData(QMediaMetaData::Author).toString();
        message.Album = player.mediaPlayer.metaData(QMediaMetaData::AlbumTitle).toString();
        message.time= player.times;
        Add_ListWidgetItem(message,ui->listWidget_20);
    });
    connect(ui->action2_5, &QAction::triggered ,[=](){
        sing_message message;
        message.name = player.mediaPlayer.metaData(QMediaMetaData::Title).toString();
        message.singer = player.mediaPlayer.metaData(QMediaMetaData::Author).toString();
        message.Album = player.mediaPlayer.metaData(QMediaMetaData::AlbumTitle).toString();
        message.time= player.times;
        Add_ListWidgetItem(message,ui->listWidget_21);
    });
    connect(ui->action3_4, &QAction::triggered ,[=](){
        sing_message message;
        message.name = player.mediaPlayer.metaData(QMediaMetaData::Title).toString();
        message.singer = player.mediaPlayer.metaData(QMediaMetaData::Author).toString();
        message.Album = player.mediaPlayer.metaData(QMediaMetaData::AlbumTitle).toString();
        message.time= player.times;
        Add_ListWidgetItem(message,ui->listWidget_22);
    });
    connect(ui->action4_4, &QAction::triggered ,[=](){
        sing_message message;
        message.name = player.mediaPlayer.metaData(QMediaMetaData::Title).toString();
        message.singer = player.mediaPlayer.metaData(QMediaMetaData::Author).toString();
        message.Album = player.mediaPlayer.metaData(QMediaMetaData::AlbumTitle).toString();
        message.time= player.times;
        Add_ListWidgetItem(message,ui->listWidget_23);
    });
    connect(ui->action5_3, &QAction::triggered ,[=](){
        sing_message message;
        message.name = player.mediaPlayer.metaData(QMediaMetaData::Title).toString();
        message.singer = player.mediaPlayer.metaData(QMediaMetaData::Author).toString();
        message.Album = player.mediaPlayer.metaData(QMediaMetaData::AlbumTitle).toString();
        message.time= player.times;
        Add_ListWidgetItem(message,ui->listWidget_24);
    });

}

void MainWindow::Connect_page()
{
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->pushButton_7,&QPushButton::clicked,[=](){ui->stackedWidget->setCurrentIndex(0);});
    connect(ui->pushButton,&QPushButton::clicked,[=](){ui->stackedWidget->setCurrentIndex(1);});
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){ui->stackedWidget->setCurrentIndex(2);});
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){ui->stackedWidget->setCurrentIndex(3);});
    connect(ui->pushButton_4,&QPushButton::clicked,[=](){ui->stackedWidget->setCurrentIndex(4);});
    connect(ui->pushButton_5,&QPushButton::clicked,[=](){ui->stackedWidget->setCurrentIndex(5);});
    connect(ui->pushButton_6,&QPushButton::clicked,[=](){ui->stackedWidget->setCurrentIndex(6);});
    connect(ui->pushButton_8,&QPushButton::clicked,[=](){ui->stackedWidget->setCurrentIndex(7);});
    connect(ui->pushButton_9,&QPushButton::clicked,[=](){ui->stackedWidget->setCurrentIndex(8);});
    connect(ui->pushButton_10,&QPushButton::clicked,[=](){ui->stackedWidget->setCurrentIndex(9);});
    connect(ui->pushButton_11,&QPushButton::clicked,[=](){ui->stackedWidget->setCurrentIndex(10);});
    connect(ui->pushButton_12,&QPushButton::clicked,[=](){ui->stackedWidget->setCurrentIndex(11);});

    ui->pushButton_7->setStyleSheet("QPushButton{background-color: rgba(171, 171, 171, 100);border:none}");
    //rgba(171, 171, 171, 100)
    connect(ui->pushButton_7,&QPushButton::clicked,[=](){ui->pushButton_7->setStyleSheet("QPushButton{background-color: rgba(171, 171, 171, 100);border:none}");
        ui->pushButton_2->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_3->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_4->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_5->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_6->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_8->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_9->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_10->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_11->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_12->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
    });

    connect(ui->pushButton,&QPushButton::clicked,[=](){ui->pushButton->setStyleSheet("QPushButton{background-color: rgba(171, 171, 171, 100);border:none}");
        ui->pushButton_2->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_3->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_4->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_5->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_6->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_7->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_8->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_9->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_10->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_11->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_12->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){ui->pushButton_2->setStyleSheet("QPushButton{background-color: rgba(171, 171, 171, 100);border:none}");
        ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_3->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_4->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_5->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_6->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_7->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_8->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_9->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_10->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_11->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_12->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
    });
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){ui->pushButton_3->setStyleSheet("QPushButton{background-color: rgba(171, 171, 171, 100);border:none}");
        ui->pushButton_2->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_4->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_5->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_6->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_7->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_8->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_9->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_10->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_11->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_12->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
    });
    connect(ui->pushButton_4,&QPushButton::clicked,[=](){ui->pushButton_4->setStyleSheet("QPushButton{background-color: rgba(171, 171, 171, 100);border:none}");
        ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_2->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_3->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_5->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_6->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_7->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_8->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_9->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_10->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_11->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_12->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
    });
    connect(ui->pushButton_5,&QPushButton::clicked,[=](){ui->pushButton_5->setStyleSheet("QPushButton{background-color: rgba(171, 171, 171, 100);border:none}");
        ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_2->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_3->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_4->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_6->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_7->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_8->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_9->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_10->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_11->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_12->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
    });
    connect(ui->pushButton_6,&QPushButton::clicked,[=](){ui->pushButton_6->setStyleSheet("QPushButton{background-color: rgba(171, 171, 171, 100);border:none}");
        ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_2->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_3->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_4->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_5->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_7->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_8->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_9->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_10->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_11->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_12->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
    });
    connect(ui->pushButton_7,&QPushButton::clicked,[=](){ui->pushButton_7->setStyleSheet("QPushButton{background-color: rgba(171, 171, 171, 100);border:none}");
        ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_2->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_3->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_4->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_5->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_6->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_8->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_9->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_10->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_11->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_12->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
    });
    connect(ui->pushButton_8,&QPushButton::clicked,[=](){ui->pushButton_8->setStyleSheet("QPushButton{background-color: rgba(171, 171, 171, 100);border:none}");
        ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_2->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_3->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_4->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_5->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_6->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_7->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");

        ui->pushButton_9->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_10->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_11->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_12->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
    });
    connect(ui->pushButton_9,&QPushButton::clicked,[=](){ui->pushButton_9->setStyleSheet("QPushButton{background-color: rgba(171, 171, 171, 100);border:none}");
        ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_2->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_3->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_4->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_5->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_6->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_7->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_8->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");

        ui->pushButton_10->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_11->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_12->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
    });
    connect(ui->pushButton_10,&QPushButton::clicked,[=](){ui->pushButton_10->setStyleSheet("QPushButton{background-color: rgba(171, 171, 171, 100);border:none}");
        ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_2->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_3->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_4->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_5->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_6->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_7->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_8->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_9->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_11->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_12->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
    });
    connect(ui->pushButton_11,&QPushButton::clicked,[=](){ui->pushButton_11->setStyleSheet("QPushButton{background-color: rgba(171, 171, 171, 100);border:none}");
        ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_2->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_3->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_4->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_5->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_6->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_7->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_8->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_9->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_10->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_12->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
    });
    connect(ui->pushButton_12,&QPushButton::clicked,[=](){ui->pushButton_12->setStyleSheet("QPushButton{background-color: rgba(171, 171, 171, 100);border:none}");
        ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_2->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_3->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_4->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_5->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_6->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_7->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_8->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_9->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_10->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
        ui->pushButton_11->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");
    });
}

void MainWindow::Add_ListWidgetItem(sing_message &message, QListWidget *& Widget)
{

    name = new QLabel(message.name);
    singer = new QLabel(message.singer);
    Album = new QLabel(message.Album);
    time = new QLabel(message.time);


    playBtn = new QToolButton;                          //歌曲播放按钮
    playBtn->setToolButtonStyle(Qt::ToolButtonIconOnly);  //只显示图片
    playBtn->setIconSize(QSize(20,20));                   //按钮大小
    playBtn->setIcon(QIcon(":/images/play.png"));       //添加图片
    playBtn->setStyleSheet("QToolButton{background-color:transparent}");//背景透明

    addBtn = new QToolButton;
    addBtn->setToolButtonStyle(Qt::ToolButtonIconOnly);  //只显示图片
    addBtn->setIconSize(QSize(20,20));                   //按钮大小
    addBtn->setIcon(QIcon(":/images/add.png"));       //添加图片
    addBtn->setStyleSheet("QToolButton{background-color:transparent}");//背景透明

    downloadBtn = new QToolButton;
    downloadBtn->setToolButtonStyle(Qt::ToolButtonIconOnly);  //只显示图片
    downloadBtn->setIconSize(QSize(20,20));                   //按钮大小
    downloadBtn->setIcon(QIcon(":/images/down.png"));       //添加图片
    downloadBtn->setStyleSheet("QToolButton{background-color:transparent}");//背景透明

    moreBtn = new QToolButton;
    moreBtn->setToolButtonStyle(Qt::ToolButtonIconOnly);  //只显示图片
    moreBtn->setIconSize(QSize(20,20));                   //按钮大小
    moreBtn->setIcon(QIcon(":/images/trash.png"));       //添加图片
    moreBtn->setStyleSheet("QToolButton{background-color:transparent}");//背景透明

    QGroupBox *widget = new QGroupBox;
    QHBoxLayout *layout = new QHBoxLayout(widget);
    layout->addWidget(playBtn);
    layout->addWidget(name);
    layout->addWidget(singer);
    layout->addWidget(Album);
    layout->addWidget(time);
    layout->addWidget(addBtn);
    layout->addWidget(downloadBtn);
    layout->addWidget(moreBtn);

    widget->setLayout(layout);

    QListWidgetItem *aItem = new QListWidgetItem;

    Widget->addItem(aItem);
    Widget->setItemWidget(aItem,widget);

    aItem->setSizeHint(QSize(0,50));
    QList<QUrl> Urls = player.Url;
    connect(playBtn,&QPushButton::clicked,[=](){
        player.playUrl(Urls.constFirst());
    });
    connect(addBtn,&QPushButton::clicked,[&](){
        QMessageBox::information(this,"提示","请前往菜单添加到歌单");
    });
    connect(downloadBtn,&QPushButton::clicked,[=](){
       QMessageBox::information(this,"提示","该歌曲为本地歌曲，无需下载");
    });
    connect(moreBtn,&QPushButton::clicked,[=](){
        ui->listWidget_13->removeItemWidget(aItem);
        delete aItem;
    });
    //mediaPlayer.play();

    widget->show();
}


MainWindow::~MainWindow()
{
    delete ui;
}
