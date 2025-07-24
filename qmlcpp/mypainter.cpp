#include "mypainter.h"
#include <QDebug>
MyPainter::MyPainter(QQuickPaintedItem *parent)
    : QQuickPaintedItem{parent}
{
    qDebug()<<"hello";
}
