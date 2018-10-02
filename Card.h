#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QDateTime>

class CCard: public QObject
{
    Q_OBJECT

public:
    enum class LearnState
    {
        NotFormulated = 0,
        FormulatedNotLearnt,
        Learnt,
    };
public:
    CCard(QObject* parent = nullptr);

    QString ownerDeck();

    QString toString();
    /** when edit/add card */
    void setQuestion(QString question);
    void setAnswer(QString answer);
    void setOwnerDeck(QString ownerDeck);

    void addToOwner();
    void removeFromOwner();

    /** when ownerDeckName changed */
    void refreshOwnerName(QString);
private:
    QString mOwnerDeck;

    QString mQuestion;
    QString mAnswer;

    QDateTime mCreateTime;
    QDateTime mStartLearnTime;
    QDateTime mReviewTime;

};

#endif // CARD_H
