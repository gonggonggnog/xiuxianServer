#include "windowsSolve.h"
#include<QMouseEvent>

void windowsSolve::mouseMoveEvent(QMouseEvent* event)
{
    //ֻ��������϶�   �����Ķ���
    if (event->buttons() & Qt::LeftButton)  //buttons������ǳ��¼���button������Ƕ��ݵ��¼�
    {
        //���ڸ�������ƶ�
        //���ڵ���λ��=��굱ǰλ��-��ֵ
        move((event->globalPosition() - m_pt).rx(),(event->globalPosition() - m_pt).ry());
    }
}

void windowsSolve::mousePressEvent(QMouseEvent* ev)
{
    // �������������  ����
    if (ev->button() & Qt::LeftButton)
    {
        //���ֵ=��굱ǰλ��-�������Ͻǵ�
        m_pt = ev->globalPosition() - this->geometry().topLeft();  //geometry()�Ǿ��δ��ڣ�topLeft()�����Ͻǵ���Ϣ��
    }
}
