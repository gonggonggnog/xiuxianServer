#include "windowsSolve.h"
#include<QMouseEvent>

void windowsSolve::mouseMoveEvent(QMouseEvent* event)
{
    //只允许左键拖动   持续的动作
    if (event->buttons() & Qt::LeftButton)  //buttons处理的是长事件，button处理的是短暂的事件
    {
        //窗口跟随鼠标移动
        //窗口的新位置=鼠标当前位置-差值
        move((event->globalPosition() - m_pt).rx(),(event->globalPosition() - m_pt).ry());
    }
}

void windowsSolve::mousePressEvent(QMouseEvent* ev)
{
    // 如果鼠标左键按下  单击
    if (ev->button() & Qt::LeftButton)
    {
        //求差值=鼠标当前位置-窗口左上角点
        m_pt = ev->globalPosition() - this->geometry().topLeft();  //geometry()是矩形窗口，topLeft()是左上角的信息。
    }
}
