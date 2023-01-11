#ifndef BASEITEM_H
#define BASEITEM_H

#include <QString>


class BaseItem
{
public:
    BaseItem(const QString &name, int parentID, qint64 size, int type);

    enum Type{
        File,
        Dir
    };

    QString getName() const;
    void setName(const QString &newName);

    int getID() const;
    void setID(int newID);

    int getParentID() const;
    void setParentID(int newParentID);

    qint64 getSize() const;
    void setSize(qint64 newSize);

    int getType() const;
    void setType(int newType);

private:
    QString name;
    int ID;
    int parentID;
    qint64 size;
    int type;
};

#endif // BASEITEM_H
