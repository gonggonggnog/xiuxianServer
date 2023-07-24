
#include "xiuxian.h"
#include <ui_xiuxian.h>
#include<_register.h>
#include<QSettings>
#include <QMessageBox>
#include"userinfo.h"
#include<QLineEdit>
#include <synchapi.h>
xiuxian::xiuxian(QWidget *parent)
    : ui(new Ui::xiuxian1)
{
    this->setParent(parent);
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->pwdEdit->setEchoMode(QLineEdit::Password);
    setEdit();
}

xiuxian::~xiuxian()
{
    delete ui;
}
//设置记住密码
void xiuxian::setEdit()
{
    QSettings setting ("./config.ini",QSettings::IniFormat);  //设置一个用于存储的ini文件
    QString id = setting.value("id").toString();//读取账号
    QString pwd = db.getPasswd(id);//读取密码
    ui->userEdit->setText(id); //设置账号
    ui->pwdEdit->setText(pwd);
}

void xiuxian::on_minBtn_clicked()
{
    this->showMinimized();
}


void xiuxian::on_closeBtn_clicked()
{
    this->close();
}


void xiuxian::on_registerBtn_clicked()
{
    _register *reg = new _register;
    reg->show();
    db.~dbSolve();
    connect(reg, &_register::back, this, [=]{
        this->show();
        reg->hide();
    });
    this->hide();
}


void xiuxian::on_loginBtn_clicked()
{
    QString id = ui->userEdit->text();
    QString passwd = ui->pwdEdit->text();
    qDebug()<<id<<"  "<<db.getPasswd(id);
    if(db.getPasswd(id) != passwd)
    {
        QMessageBox::information(0, QString("登陆失败"), QString("账号或密码错误"));
        return;
    }
    userInfo *user = new userInfo;
    user->setAccount(id);
    user->show();
    this->close();
    if(ui->checkBox->isChecked())
    {

        QSettings setting ("./config.ini",QSettings::IniFormat);  //设置一个用于存储的ini文件
        setting.setValue("id",id);
        setting.sync();
    }
}

