#include <QQmlEngine>
#include <QGuiApplication>
#include <QQmlComponent>
#include <QQuickWindow>
#include <QQuickStyle>
int main(int argc,char* argv[])
{
    QGuiApplication app(argc,argv);

    QQuickStyle::setStyle("Fusion");
    QQmlEngine eng;
    QQmlComponent com(&eng);
    com.loadUrl(QUrl("qrc:/main.qml"));
    std::unique_ptr<QQuickWindow> ct(static_cast<QQuickWindow*>(com.create()));

    return app.exec();
}
