
#ifndef XIUXIAN_H
#define XIUXIAN_H
#include "windowsSolve.h"
#include <QMainWindow>
#include <_register.h>
#include <dbSolve.h>



QT_BEGIN_NAMESPACE
#include <ui_xiuxian.h>
QT_END_NAMESPACE

class xiuxian : public windowsSolve

{
    Q_OBJECT

public:
    xiuxian(QWidget *parent = nullptr);
    ~xiuxian();

private slots:
    void on_minBtn_clicked();

    void on_closeBtn_clicked();

    void on_registerBtn_clicked();

    void on_loginBtn_clicked();

private:
    Ui::xiuxian1 *ui;
    void setEdit();
    dbSolve db;
};

#endif // XIUXIAN_H
