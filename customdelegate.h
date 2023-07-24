
#ifndef CUSTOMDELEGATE_H
#define CUSTOMDELEGATE_H

#include "qapplication.h"
#include <QStyledItemDelegate>
#include <QPainter>

class CustomDelegate : public QStyledItemDelegate
{
public:
    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override
    {
        QStyleOptionViewItem opt = option;
        initStyleOption(&opt, index);

        // 获取左侧文本和右侧文本
        QString leftText = index.data(Qt::UserRole).toString();
        QString rightText = index.data(Qt::UserRole + 1).toString();

        // 绘制背景和选择状态
        QApplication::style()->drawControl(QStyle::CE_ItemViewItem, &opt, painter);

        // 计算左侧文本的绘制区域
        QRect leftRect = option.rect;
        leftRect.setRight(leftRect.center().x() - 5); // 设置为项的中心点的左侧

        // 绘制左侧文本
        painter->drawText(leftRect, Qt::AlignLeft | Qt::AlignVCenter, leftText);

        // 计算右侧文本的绘制区域
        QRect rightRect = option.rect;
        rightRect.setLeft(rightRect.center().x() + 5); // 设置为项的中心点的右侧

        // 绘制右侧文本
        painter->drawText(rightRect, Qt::AlignRight | Qt::AlignVCenter, rightText);
    }
};


#endif // CUSTOMDELEGATE_H
