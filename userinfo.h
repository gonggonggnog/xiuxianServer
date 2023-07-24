#ifndef USERINFO_H
#define USERINFO_H

#include "ui_userinfo.h"
#include <windowsSolve.h>
#include <QTcpSocket>
#include <dbSolve.h>
#include <QKeyEvent>

class userInfo : public windowsSolve
{
    Q_OBJECT

public:
    explicit userInfo(QWidget *parent = nullptr);
    ~userInfo();
    void setAccount(QString s);
private slots:
    void on_minBtn_clicked();
    void on_closeBtn_clicked();
    void on_backBtn_clicked();

    void on_chatBtn_clicked();

    void on_sendBtn_clicked();

    void on_userBtn_clicked();

    void on_setNameBtn_clicked();

    void on_nameBtn_clicked();
protected:
    void keyPressEvent(QKeyEvent *event) override;
private:
    QString m_account;
    QString m_name;
    QTcpSocket* m_socket;
    Ui::userInfo1 *ui;
    bool connected;
    dbSolve db;
    void sendMsg(QString msg);
};

#endif // USERINFO_H
