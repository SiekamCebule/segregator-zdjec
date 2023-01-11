#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QEventLoop>
#include <QString>
#include <QVector>
#include <QDir>
#include <QStringList>


#include "idassigner.h"
#include "itemClasses/baseitem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_addDir_clicked();

private:
    Ui::MainWindow *ui;

    QVector<QVector<BaseItem *>> folders;
    QStringList allowedFormats;
    void loadAllowedFormats();
};
#endif // MAINWINDOW_H
