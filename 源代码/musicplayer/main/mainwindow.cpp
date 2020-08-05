#include "mainwindow.h"
#include "musicplayer.h"
#include "ui_mainwindow.h"
#include <QMovie>
#include <QGridLayout>
#include <QListWidgetItem>
#include <QLabel>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1200,900);
    setWindowTitle("Music");
    setWindowIcon(QIcon(":/image/blue.png"));

    ui->groupBox->setStyleSheet("QGroupBox{border:none;color: rgb(171,171,171);}QPushButton{background-color: rgb(248,248,248);border:none}");  //这个是去掉groupBox中的所有QGroupBox的边框；
    ui->groupBox_2->setStyleSheet("QGroupBox{border:none;color: rgb(171,171,171);}QPushButton{background-color: rgb(248,248,248);border:none}");
    ui->groupBox_3->setStyleSheet("QGroupBox{border:none;color: rgb(171,171,171);}QPushButton{background-color: rgb(248,248,248);border:none}");
    ui->groupBox_5->setStyleSheet("QGroupBox{border:none;}");
    ui->listWidget_13->setAutoScroll(true);    //滚动长条

    Connect_page();

    sing_message message("少年","梦然","少年","03:56");
    sing_message message2("mojito","周杰伦","mojito","03:05");
    sing_message message3("让我留在你身边","陈奕迅","让我留在你身边","03:08");
    for(int i=0; i<8; i++) Add_ListWidgetItem(message);
    for(int i=0; i<8; i++) Add_ListWidgetItem(message2);
    for(int i=0; i<6; i++) Add_ListWidgetItem1(message3);
    for(int i=0; i<7; i++) Add_ListWidgetItem1(message2);

    //mp.move(180,815);
    //mp.show();
    //mp.setParent(this);





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

    connect(ui->pushButton_7,&QPushButton::pressed,[=](){ui->pushButton_7->setStyleSheet("QPushButton{background-color: rgb(171,171,171);border:none}");});
    connect(ui->pushButton_7,&QPushButton::released,[=](){ui->pushButton_7->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");});
    connect(ui->pushButton,&QPushButton::pressed,[=](){ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(171,171,171);border:none}");});
    connect(ui->pushButton,&QPushButton::released,[=](){ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");});
    connect(ui->pushButton_2,&QPushButton::pressed,[=](){ui->pushButton_2->setStyleSheet("QPushButton{background-color: rgb(171,171,171);border:none}");});
    connect(ui->pushButton_2,&QPushButton::released,[=](){ui->pushButton_2->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");});
    connect(ui->pushButton_3,&QPushButton::pressed,[=](){ui->pushButton_3->setStyleSheet("QPushButton{background-color: rgb(171,171,171);border:none}");});
    connect(ui->pushButton_3,&QPushButton::released,[=](){ui->pushButton_3->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");});
    connect(ui->pushButton_4,&QPushButton::pressed,[=](){ui->pushButton_4->setStyleSheet("QPushButton{background-color: rgb(171,171,171);border:none}");});
    connect(ui->pushButton_4,&QPushButton::released,[=](){ui->pushButton_4->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");});
    connect(ui->pushButton_5,&QPushButton::pressed,[=](){ui->pushButton_5->setStyleSheet("QPushButton{background-color: rgb(171,171,171);border:none}");});
    connect(ui->pushButton_5,&QPushButton::released,[=](){ui->pushButton_5->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");});
    connect(ui->pushButton_6,&QPushButton::pressed,[=](){ui->pushButton_6->setStyleSheet("QPushButton{background-color: rgb(171,171,171);border:none}");});
    connect(ui->pushButton_6,&QPushButton::released,[=](){ui->pushButton_6->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");});
    connect(ui->pushButton_8,&QPushButton::pressed,[=](){ui->pushButton_8->setStyleSheet("QPushButton{background-color: rgb(171,171,171);border:none}");});
    connect(ui->pushButton_8,&QPushButton::released,[=](){ui->pushButton_8->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");});
    connect(ui->pushButton_9,&QPushButton::pressed,[=](){ui->pushButton_9->setStyleSheet("QPushButton{background-color: rgb(171,171,171);border:none}");});
    connect(ui->pushButton_9,&QPushButton::released,[=](){ui->pushButton_9->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");});
    connect(ui->pushButton_10,&QPushButton::pressed,[=](){ui->pushButton_10->setStyleSheet("QPushButton{background-color: rgb(171,171,171);border:none}");});
    connect(ui->pushButton_10,&QPushButton::released,[=](){ui->pushButton_10->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");});
    connect(ui->pushButton_11,&QPushButton::pressed,[=](){ui->pushButton_11->setStyleSheet("QPushButton{background-color: rgb(171,171,171);border:none}");});
    connect(ui->pushButton_11,&QPushButton::released,[=](){ui->pushButton_11->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");});
    connect(ui->pushButton_12,&QPushButton::pressed,[=](){ui->pushButton_12->setStyleSheet("QPushButton{background-color: rgb(171,171,171);border:none}");});
    connect(ui->pushButton_12,&QPushButton::released,[=](){ui->pushButton_12->setStyleSheet("QPushButton{background-color: rgb(248,248,248);border:none}");});
}

void MainWindow::Add_ListWidgetItem(sing_message &message)
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

    ui->listWidget_13->addItem(aItem);
    ui->listWidget_13->setItemWidget(aItem,widget);

    aItem->setSizeHint(QSize(0,50));


    widget->show();
}

void MainWindow::Add_ListWidgetItem1(sing_message &message)
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

    ui->listWidget_14->addItem(aItem);
    ui->listWidget_14->setItemWidget(aItem,widget);

    aItem->setSizeHint(QSize(0,50));

    widget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

