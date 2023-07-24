#include "_register.h"
#include "dbSolve.h"
#include <qmessagebox.h>
#include "userinfo.h"
_register::_register(QWidget *parent)
{
	this->setParent(parent);
	ui.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint);//去除窗体状态栏
	ui.pwdEdit->setEchoMode(QLineEdit::Password);
    ui.cfpwdEdit->setEchoMode(QLineEdit::Password);
    connect(ui.minBtn_2, &QPushButton::clicked, this, &_register::back);
}

_register::~_register()
{
	db.~dbSolve();
}

//关闭按钮处理
void _register::on_closeBtn_clicked()
{
	this->close();
}
//最小化按钮处理
void _register::on_minBtn_clicked()
{
	this->showMinimized();
}
//注册按钮处理
void _register::on_registerBtn_clicked()
{
	QString pwd = ui.pwdEdit->text();
	QString cfpwd = ui.cfpwdEdit->text();
	QString id = ui.userEdit->text();
	qDebug() << pwd << cfpwd;
	if (pwd != cfpwd)
	{
        QMessageBox::information(0, QString::fromLocal8Bit("输入错误"), QString::fromLocal8Bit("两次密码不匹配"));
		return;
	}
	if (!db.addAccount(id, pwd))
	{
        QMessageBox::information(0, QString::fromLocal8Bit("注册失败"), QString::fromLocal8Bit("添加数据失败"));
		return;
	}
    QMessageBox::information(0, QString::fromLocal8Bit("success"), QString::fromLocal8Bit("注册成功"));
    userInfo *user = new userInfo;
    user->setAccount(id);
    user->show();
    this->close();
}
