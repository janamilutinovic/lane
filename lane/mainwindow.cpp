
#include <QApplication>

#include "chatdialog.h"
#include "mainwindow.h"


#include <QtCore/QSettings>
#include <QtNetwork/QNetworkConfigurationManager>
#include <QtNetwork/QNetworkSession>
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->setFocusPolicy(Qt::NoFocus);

    connect(&client, SIGNAL(newParticipant(QString)),
            this, SLOT(newParticipant(QString)));
    connect(&client, SIGNAL(participantLeft(QString)),
            this, SLOT(participantLeft(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newParticipant(const QString &nick)
{
    if (nick.isEmpty() || (nick.compare(client.nickName())==0) /*TODO check IP adress*/)
        return;
    ui->listWidget->addItem(nick);
}

void MainWindow::participantLeft(const QString &nick)
{
    if (nick.isEmpty())
        return;

    QList<QListWidgetItem *> items = ui->listWidget->findItems(nick,
                                                           Qt::MatchExactly);
    if (items.isEmpty())
        return;

    delete items.at(0);

}

void MainWindow::on_listWidget_clicked(const QModelIndex &index)
{
    ChatDialog dialog;
     dialog.setModal(true);
     dialog.exec();
}
