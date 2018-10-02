#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtDebug>

#include "DataBank.h"
#include "Deck.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    //qmlRegisterType<CDataBank>("Backend", 1, 0, "DataBank");
    //qmlRegisterType<CDeck>("Backend", 1, 0, "Deck");
    CDataBank* dataBank = CDataBank::getInstance();
    dataBank->createCard("2+3","5","default");
    qInfo("decklistnum: %d", dataBank->deckCount());
    for (qint32 i = 0; i < dataBank->deckCount(); ++i)
    {
        qInfo() << "deck" << i << (*dataBank->deckList())[i]->toString();
    }
    dataBank->createDeck("english");
    dataBank->createCard("clever", "聪明", "english");
    dataBank->createCard("fraud", "骗子", "english");
    qInfo("decklistnum: %d", dataBank->deckCount());
    for (qint32 i = 0; i < dataBank->deckCount(); ++i)
    {
        qInfo() << "deck" << i << (*dataBank->deckList())[i]->toString();
    }

    QQmlApplicationEngine engine;
    //engine.rootContext()->setContextProperty("dataBank", dataBank);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;


    return app.exec();
}
