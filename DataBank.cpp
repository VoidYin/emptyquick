#include "DataBank.h"
#include "Deck.h"
#include "Card.h"

CDataBank* CDataBank::mInstance = nullptr;

CDataBank::CDataBank(QObject* parent): QObject(parent)
{
    createDeck("default");
}

QList<CDeck *> *CDataBank::deckList()
{
    return &mDeckList;
}

qint32 CDataBank::deckCount()
{
    return mDeckList.count();
}

CDataBank *CDataBank::getInstance()
{
    if (!mInstance)
        mInstance = new CDataBank();
    return mInstance;
}

//QQmlListProperty<CDeck> CDataBank::deckList()
//{
//    return QQmlListProperty<CDeck>(this, this,
//             &CDataBank::appendDeck,
//             &CDataBank::deckCount,
//             &CDataBank::deck,
//                                   &CDataBank::clearDecks);
//}

void CDataBank::createDeck(QString inName)
{
    CDeck* tmpDeck = new CDeck();
    tmpDeck->setName(inName);

    mDeckList.append(tmpDeck);
    emit deckListChanged();
}

void CDataBank::editDeck(CDeck *originalDeck, QString inName)
{
    originalDeck->setName(inName);
}

void CDataBank::deleteDeck(CDeck *originalDeck)
{
    mDeckList.removeOne(originalDeck);
    originalDeck->clearCards();
    delete originalDeck;

    emit deckListChanged();
    emit allCardListChanged();
}

CDeck *CDataBank::deck(QString deckName)
{
    for (CDeck* tmpDeck: mDeckList)
    {
        if (tmpDeck->name() == deckName)
        {
            return tmpDeck;
        }
    }
    return nullptr;
}

void CDataBank::createCard(QString question, QString answer, QString ownerDeck)
{
    if (!deck(ownerDeck))
        return;
    CCard* tmpCard = new CCard();
    tmpCard->setQuestion(question);
    tmpCard->setAnswer(answer);
    tmpCard->setOwnerDeck(ownerDeck);

    emit allCardListChanged();
}

void CDataBank::editCard(CCard *originalCard, QString question, QString answer, QString ownerDeck)
{
    originalCard->setQuestion(question);
    originalCard->setAnswer(answer);
    originalCard->setOwnerDeck(ownerDeck);
}

void CDataBank::deleteCard(CCard *originalCard)
{
    originalCard->removeFromOwner();
    delete originalCard;
    emit allCardListChanged();
}

//void CDataBank::appendDeck(CDeck* deck)
//{
//    mDeckList.append(deck);

//}

//int CDataBank::deckCount() const
//{
//    return mDeckList.count();
//}

//CDeck* CDataBank::deck(int index) const
//{
//    return mDeckList.at(index);
//}

//void CDataBank::removeDeck(int index)
//{
//    mDeckList.removeAt(index);
//}

//void CDataBank::clearDecks()
//{
//    mDeckList.clear();
//}

//void CDataBank::appendDeck(QQmlListProperty<CDeck>* list, CDeck* deck)
//{
//    CDataBank* dataBank = qobject_cast<CDataBank*>(list->object);
//    if (dataBank)
//        dataBank->mDeckList.append(deck);
//}

//int CDataBank::deckCount(QQmlListProperty<CDeck>* list)
//{
//    CDataBank* dataBank = qobject_cast<CDataBank*>(list->object);
//    if (dataBank)
//        dataBank->mDeckList.count();
//}

//CDeck* CDataBank::deck(QQmlListProperty<CDeck>* list, int index)
//{
//    CDataBank* dataBank = qobject_cast<CDataBank*>(list->object);
//    if (dataBank)
//        dataBank->mDeckList.at(index);
//}

//void CDataBank::clearDecks(QQmlListProperty<CDeck>* list)
//{
//    CDataBank* dataBank = qobject_cast<CDataBank*>(list->object);
//    if (dataBank)
//        dataBank->mDeckList.clear();
//}

