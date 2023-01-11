#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QEventLoop>
#include <QDebug>
#include <QMetaObject>
#include <QFileSystemModel>
#include <QStringList>
#include <QFileInfo>

#include "itemClasses/baseitem.h"
#include "itemClasses/fileitem.h"
#include "itemClasses/diritem.h"
#include "idassigner.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>
#include <QByteArray>
#include <QFile>
#include <QMessageBox>

extern IDAssigner idAssigner;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadAllowedFormats();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_addDir_clicked()
{
    QDir mainFolder = QFileDialog::getExistingDirectory(this, "Wybierz folder");
    if(!(mainFolder.entryInfoList(QDir::Files | QDir::Dirs).empty()))
    {
        folders.push_back(QVector<BaseItem *>());
    }

    for(auto & fileInfo : mainFolder.entryInfoList(QDir::Files)){
            BaseItem * item = new FileItem(QPixmap(fileInfo.filePath()), fileInfo.fileName(), 0, fileInfo.size());
            folders[folders.size() - 1].push_back(item);
    }
    /*for(auto & fileInfo : mainFolder.entryInfoList(QDir::Dirs)){
        BaseItem * item = new BaseItem;
        folders[folders.size() - 1];
    }*/
}

void MainWindow::loadAllowedFormats()
{
    QFile file("config.json");
    file.open(QFile::ReadOnly | QFile::Text);
    QByteArray byteArray = file.readAll();
    file.close();
    QJsonParseError error;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(byteArray, &error);
    if(error.error != QJsonParseError::NoError)
    {
        QMessageBox * message = new QMessageBox;
        message->setModal(true);
        message->setText("Błąd podczas wczytywania ustawień z pliku config.json\nTREŚĆ BŁĘDU ----> " + error.errorString() + "\n");
        message->setIcon(QMessageBox::Icon::Critical);
        message->setStandardButtons(QMessageBox::StandardButton::Close);
        message->setDefaultButton(QMessageBox::StandardButton::Close);

        switch(message->exec()){
        case QMessageBox::Close:
            qDebug()<<"close button";

            break;
        default:
            qDebug()<<"default";
            break;
        }


        return;
    }
    QJsonObject object = jsonDoc.object();
    QJsonValue value = object.value("allowedFormats");
    QJsonArray array = value.toArray();
    for(auto val : array)
    {
        allowedFormats.append(val.toString());
    }
}
