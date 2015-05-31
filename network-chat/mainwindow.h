#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include "ui_mainwindow.h"
#include "client.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Client client;

private slots:

    void newParticipant(const QString &nick);
    void participantLeft(const QString &nick);


    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_listWidget_clicked(const QModelIndex &index);
};

#endif // MAINWINDOW_H
