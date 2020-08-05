#include "musicplayer.h"
#include "mainwindow.h"

#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QDesktopWidget>
#include <QFileInfo>
#include <QMimeDatabase>
#include <QSettings>
#include <QIcon>
#include <QDir>
#include <QUrl>



int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  MainWindow w;

   w.show();

  return app.exec();
}
