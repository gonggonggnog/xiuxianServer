#pragma once
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
class dbSolve
{
public:
	dbSolve();
	~dbSolve();
	QString getPasswd(QString s);
	bool addAccount(QString id, QString passwd);
    bool setPasswd(QString s,QString passwd);
    QList<QString> getBack(QString s);
    QString getName(QString s);
    bool setName(QString id, QString passwd);
private:
    QSqlDatabase db;
	QSqlQuery res;
    QSqlRecord rec;
};

