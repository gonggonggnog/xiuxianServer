#pragma once

#include "windowsSolve.h"
#include "ui__register.h"
#include "dbSolve.h"

class _register : public windowsSolve
{
	Q_OBJECT

public:
	_register(QWidget *parent = nullptr);
	~_register();
	
private slots:
	void on_closeBtn_clicked();
	void on_minBtn_clicked();
    void on_registerBtn_clicked();

signals:
    void back();
private:
    dbSolve db;
    Ui::_register1Class ui;
};
