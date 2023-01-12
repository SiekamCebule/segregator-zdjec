#ifndef BASEITEM_H
#define BASEITEM_H

#include <QString>


class BaseItem
{
public:
    BaseItem(const QString &name, int parentID, int type);

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

    int getType() const;
    void setType(int newType);

private:
    QString name;
    int ID;
    int parentID;

    int type;
};

#endif // BASEITEM_H
