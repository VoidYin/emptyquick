#include "Card.h"
#include "DataBank.h"
#include "Deck.h"
#include <QtDebug>

CCard::CCard(QObject *parent): QObject(parent)
{

}

QString CCard::ownerDeck()
{
    return mOwnerDeck;
}

QString CCard::toString()
{
    QString rltStr = mQuestion;
    rltStr += ':';
    rltStr += mAnswer;

    //qInfo() << mQuestion << ":" << mAnswer;
    return rltStr;
}

void CCard::setQuestion(QString question)
{
    mQuestion = question;
}

void CCard::setAnswer(QString answer)
{
    mAnswer = answer;
}

void CCard::setOwnerDeck(QString ownerDeck)
{
    removeFromOwner();

    mOwnerDeck = ownerDeck;

    addToOwner();
}

void CCard::addToOwner()
{
    CDataBank* dataBank = CDataBank::getInstance();
    CDeck* tmpDeck = dataBank->deck(mOwnerDeck);
    if (tmpDeck)
        tmpDeck->addCard(this);
}

void CCard::removeFromOwner()
{
    CDataBank* dataBank = CDataBank::getInstance();
    CDeck* tmpDeck = dataBank->deck(mOwnerDeck);
    if (tmpDeck)
        tmpDeck->removeCard(this);
}

void CCard::refreshOwnerName(QString ownerDeck)
{
    mOwnerDeck = ownerDeck;
}
