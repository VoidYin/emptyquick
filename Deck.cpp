#include "Deck.h"
#include "Card.h"
#include <QtDebug>

CDeck::CDeck(QObject* parent): QObject(parent)
{

}

QString CDeck::toString()
{
    QString rltStr = name();
    rltStr += ' ';
    for (qint32 i = 0; i < mCardList.count(); ++i)
    {
        rltStr += mCardList[i]->toString() + ';';
    }
    return rltStr;
}

QString CDeck::name()
{
    return mName;
}

void CDeck::setName(const QString &inName)
{
    mName = inName;

    for (CCard* tmpCard: mCardList)
    {
        tmpCard->refreshOwnerName(inName);
    }
}

void CDeck::addCard(CCard *card)
{
    mCardList.append(card);

    emit cardListChanged();
}

void CDeck::removeCard(CCard *card)
{
    mCardList.removeOne(card);

    emit cardListChanged();
}

void CDeck::deleteCard(CCard *card)
{
    mCardList.removeOne(card);
    delete card;
    emit cardListChanged();
}

void CDeck::clearCards()
{
    for (CCard* tmpCard: mCardList)
    {
        delete tmpCard;
    }
    mCardList.empty();
    emit cardListChanged();
}
