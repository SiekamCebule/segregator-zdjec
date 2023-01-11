#include "baseitem.h"
#include "idassigner.h"

extern IDAssigner idAssigner;

BaseItem::BaseItem(const QString &name = "", int parentID = 0, qint64 size = 0, int type = Dir) : name(name),
    parentID(parentID),
    size(size),
    type(type)
{
    ID = idAssigner.generateNewID();
}

QString BaseItem::getName() const
{
    return name;
}

void BaseItem::setName(const QString &newName)
{
    name = newName;
}

int BaseItem::getID() const
{
    return ID;
}

void BaseItem::setID(int newID)
{
    ID = newID;
}

int BaseItem::getParentID() const
{
    return parentID;
}

void BaseItem::setParentID(int newParentID)
{
    parentID = newParentID;
}

qint64 BaseItem::getSize() const
{
    return size;
}

void BaseItem::setSize(qint64 newSize)
{
    size = newSize;
}

int BaseItem::getType() const
{
    return type;
}

void BaseItem::setType(int newType)
{
    type = newType;
}
