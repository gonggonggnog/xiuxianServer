#include "userinfo.h"
#include "ui_userinfo.h"
#include "customdelegate.h"
userInfo::userInfo(QWidget *parent)
    :m_socket(new QTcpSocket)
    ,ui(new Ui::userInfo1)
    ,connected(false)
{
    this->setParent(parent);
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->chatList->setItemDelegate(new CustomDelegate);
    //设置frame默认显示聊天界面
    ui->chatFrame->setVisible(true);
    ui->backFrame->setVisible(false);
    ui->userFrame->setVisible(false);
    //设置修改密码输入框隐藏
    ui->nameBtn->setVisible(false);
    ui->nameEdit->setVisible(false);
    //连接服务器
    this->m_socket->connectToHost(QHostAddress("127.0.0.1"), 8989);
    connect(this->m_socket, &QTcpSocket::connected, this, [=]{
        this->connected = true;
        ui->IsConnected->setText("CONNECTED");
        connect(this->m_socket, &QTcpSocket::readyRead, this, [=]{
            QString msg = this->m_socket->readAll();
            ui->chatList->addItem(msg);
        });
    });
}

userInfo::~userInfo()
{
    delete ui;
}

void userInfo::setAccount(QString s)
{
    this->m_account = s;
    this->m_name = db.getName(s);
    //设置userInfo显示账号
    ui->accountLabel->setText(this->m_account);
    ui->nameLabel->setText(this->m_name);
}

void userInfo::on_minBtn_clicked()
{
    this->showMinimized();
}


void userInfo::on_closeBtn_clicked()
{
    this->close();
}

void userInfo::on_backBtn_clicked()
{
    ui->backFrame->setVisible(true);
    ui->userFrame->setVisible(false);
    ui->chatFrame->setVisible(false);
    ui->backList->addItems(db.getBack(this->m_account));
}


void userInfo::on_chatBtn_clicked()
{
    ui->chatFrame->setVisible(true);
    ui->userFrame->setVisible(false);
    ui->backFrame->setVisible(false);
}

void userInfo::on_sendBtn_clicked()
{
    QString msg = ui->msgEdit->text();
    sendMsg(msg);
}

void userInfo::sendMsg(QString msg)
{
    if(!this->connected||msg.isEmpty()) return;
    m_socket->write((this->m_name+":"+msg).toUtf8());
    QListWidgetItem* item1 = new QListWidgetItem();
    item1->setData(Qt::UserRole+1, msg+":YOU");
    ui->chatList->addItem(item1);
    ui->msgEdit->setText("");
}

void userInfo::on_userBtn_clicked()
{
    ui->userFrame->setVisible(true);
    ui->chatFrame->setVisible(false);
    ui->backFrame->setVisible(false);
}


void userInfo::on_setNameBtn_clicked()
{
    if(ui->nameBtn->isVisible()){
        ui->nameBtn->setVisible(false);
        ui->nameEdit->setVisible(false);
    }else{
        ui->nameBtn->setVisible(true);
        ui->nameEdit->setVisible(true);
    }
}


void userInfo::on_nameBtn_clicked()
{
    QString s = ui->nameEdit->text();
    if(s.isEmpty()) return;
    m_name = s;
    db.setName(m_account,s);
    ui->nameLabel->setText(s);
    ui->nameBtn->setVisible(false);
    ui->nameEdit->setVisible(false);
}

void userInfo::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
    {
        QString msg = ui->msgEdit->text();
        sendMsg(msg);
    }
}

