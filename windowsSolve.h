#pragma once
#include<QMainWindow>
class windowsSolve : public QMainWindow
{
public:
	void mouseMoveEvent(QMouseEvent* event);
	void mousePressEvent(QMouseEvent* ev);
    QPointF m_pt;
};

