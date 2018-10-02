#ifndef DECK_H
#define DECK_H

#include <QObject>

class CCard;

class CDeck: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
public:
    CDeck(QObject* parent = nullptr);

    QString toString();
    QString name();
    void setName(const QString& inName);

    void addCard(CCard* card);
    /** 把卡片从此牌组移出，并不删除卡片 */
    void removeCard(CCard* card);
    /** 把卡片彻底删除 */
    void deleteCard(CCard* card);
    /** 清空卡片 */
    void clearCards();
signals:
    void nameChanged();
    void cardListChanged();
private:
    QString mName;
    QList<CCard*> mCardList;
    QList<CCard*> mLearntCardList;
    QList<CCard*> mReviewingCardList;

    QString mDeckSettingName;
};

#endif // DECK_H
