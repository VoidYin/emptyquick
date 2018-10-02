#ifndef DATABANK_H
#define DATABANK_H

#include <QObject>
#include <QList>

#include "Deck.h"
#include "Card.h"

//class CDeck;
//class CCard;


class CDataBank: public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QQmlListProperty<CDeck> deckList READ deckList)
public:
    CDataBank(QObject* parent = nullptr);

    //QQmlListProperty<CDeck> deckList();

    QList<CDeck*>* deckList();
    qint32 deckCount();
    static CDataBank* getInstance();

    void createDeck(QString inName);
    void editDeck(CDeck* originalDeck, QString inName);
    void deleteDeck(CDeck* originalDeck);
    CDeck* deck(QString deckName);

    void createCard(QString question, QString answer, QString ownerDeck);
    void editCard(CCard* originalCard, QString question, QString answer, QString ownerDeck);
    void deleteCard(CCard* originalCard);

//    void appendDeck(CDeck*);
//    int deckCount() const;
//    CDeck* deck(int) const;
//    void removeDeck(int);
//    void clearDecks();
signals:
    void deckListChanged();
    void allCardListChanged();

//private:
//    static void appendDeck(QQmlListProperty<CDeck>*, CDeck*);
//    static int deckCount(QQmlListProperty<CDeck>*);
//    static CDeck* deck(QQmlListProperty<CDeck>*, int);
//    static void clearDecks(QQmlListProperty<CDeck>*);
private:
    QList<CDeck*> mDeckList;
    QList<CCard*> mAllCardList;

    static CDataBank* mInstance;
};

#endif // DATABANK_H
