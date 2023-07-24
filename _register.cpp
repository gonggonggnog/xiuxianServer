#include "_register.h"
#include "dbSolve.h"
#include <qmessagebox.h>
#include "userinfo.h"
_register::_register(QWidget *parent)
{
	this->setParent(parent);
	ui.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint);//ȥ������״̬��
	ui.pwdEdit->setEchoMode(QLineEdit::Password);
    ui.cfpwdEdit->setEchoMode(QLineEdit::Password);
    connect(ui.minBtn_2, &QPushButton::clicked, this, &_register::back);
}

_register::~_register()
{
	db.~dbSolve();
}

//�رհ�ť����
void _register::on_closeBtn_clicked()
{
	this->close();
}
//��С����ť����
void _register::on_minBtn_clicked()
{
	this->showMinimized();
}
//ע�ᰴť����
void _register::on_registerBtn_clicked()
{
	QString pwd = ui.pwdEdit->text();
	QString cfpwd = ui.cfpwdEdit->text();
	QString id = ui.userEdit->text();
	qDebug() << pwd << cfpwd;
	if (pwd != cfpwd)
	{
        QMessageBox::information(0, QString::fromLocal8Bit("�������"), QString::fromLocal8Bit("�������벻ƥ��"));
		return;
	}
	if (!db.addAccount(id, pwd))
	{
        QMessageBox::information(0, QString::fromLocal8Bit("ע��ʧ��"), QString::fromLocal8Bit("�������ʧ��"));
		return;
	}
    QMessageBox::information(0, QString::fromLocal8Bit("success"), QString::fromLocal8Bit("ע��ɹ�"));
    userInfo *user = new userInfo;
    user->setAccount(id);
    user->show();
    this->close();
}
