#ifndef MY_PAINTER_H
#define MY_PAINTER_H

#include <QObject>
#include <QQmlEngine>
#include <QQuickPaintedItem>
#include <QPainter>
class MyPainter : public QQuickPaintedItem
{
    Q_OBJECT
    //字体大小
    Q_PROPERTY(int penSize MEMBER penSize_ NOTIFY penSizeChanged FINAL)
    Q_PROPERTY(QColor penColor MEMBER penColor_ NOTIFY penColorChanged FINAL)
    QML_ELEMENT
public:
    explicit MyPainter(QQuickPaintedItem *parent = nullptr);

    //开始绘制 记录坐标 开放给QML
    Q_INVOKABLE void beginPaint(QPoint pos)
    {
        last_=pos;
    }

    Q_INVOKABLE void movePaint(QPoint pos)
    {
        if(img_.isNull())
        {
            img_=QImage(this->width(),this->height(),QImage::Format_RGB32);
        }
        QPainter painter(&img_);
        QPen pen;
        pen.setStyle(Qt::SolidLine);
        pen.setWidth(penSize_);
        pen.setBrush(penColor_);
        pen.setCapStyle(Qt::RoundCap);
        pen.setJoinStyle(Qt::RoundJoin);
        painter.setPen(pen);
        painter.setRenderHint(QPainter::Antialiasing,true);
        painter.drawLine(last_,pos);
        last_=pos;
        update();
    }

signals:
    void penSizeChanged();
    void penColorChanged();
private:
    void paint(QPainter* painter) override
    {
        if(!img_.isNull())
        {
            painter->drawImage(QPoint(0,0),img_);
        }
        painter->drawText(QPoint(100,100),"test paint");
    }

    QImage img_;
    QPoint last_;
    int penSize_;
    QColor penColor_;
};

#endif // MY_PAINTER_H
