#include "dbSolve.h"
#include <QMessageBox>
#include <QSqlQuery>
#include<qsqlerror.h>
#include<qdebug.h>
#include <QString>
#include <QDebug>
#include <QList>
dbSolve::dbSolve()
{
    db.removeDatabase("QMYSQL");
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("123.249.29.21");
    db.setUserName("root");
    db.setPassword("Zzz111...");
    db.setDatabaseName("xiuxian");
    db.open();
    if (!db.isOpen())//打开数据库,如果返回false表示打开失败
    {
        //QMessageBox::critical(0, QString("Critical消息框"), QString("这是一个Critical消息框！"));
        qDebug()<<"database not opened";
        qDebug()<<db.lastError().text();
        return;
    }else
        qDebug()<<"database opened";
    res = QSqlQuery(db);
}

dbSolve::~dbSolve()
{
    db.close();
}

QString dbSolve::getPasswd(QString s)
{
    res.clear();
    res.exec(QString("select * from users where user_id='%1'").arg(s));
    if(res.next()){
        //qDebug()<<res.value("user_passwd");
        return res.value("user_passwd").toString();
    }
    return "";
}
bool dbSolve::addAccount(QString id,QString passwd)
{
    res.clear();
    bool result = res.exec(QString("insert into users(user_id,user_passwd) values ( '%1','%2')")
        .arg(id).arg(passwd));
    return result ? true : false;
}
bool dbSolve::setPasswd(QString id,QString passwd)
{
    res.clear();
    bool result = res.exec(QString("update users set user_passwd='%1' where user_id='%2'")
        .arg(passwd).arg(id));
    return result ? true : false;
}

QList<QString> dbSolve::getBack(QString s)
{
    QList<QString> l;
    res.clear();
    res.exec(QString("select * from back where user_id='%1'").arg(s));
    while(res.next()){
        //qDebug()<<res.value("goods_name").toString();
        QString temp = res.value("state")==1?"*":"";
        QString templ = res.value("goods_num").toString();
        if(templ=='0') continue;
        l.append(temp+res.value("goods_name").toString()+"X"+templ);
    }
    return l;
}

QString dbSolve::getName(QString s)
{
    res.clear();
    res.exec(QString("select * from users where user_id='%1'").arg(s));
    if(res.next()){
        return res.value("user_name").toString();
    }
    return "";
}

bool dbSolve::setName(QString id,QString name)
{
    res.clear();
    bool result = res.exec(QString("update users set user_name='%1' where user_id='%2'")
                               .arg(name).arg(id));
    return result ? true : false;
}
