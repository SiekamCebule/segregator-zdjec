#include "baseitem.h"
#include "idassigner.h"

extern IDAssigner idAssigner;

BaseItem::BaseItem(const QString &name = "", int parentID = 0, int type = Dir) : name(name),
    parentID(parentID),
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

int BaseItem::getType() const
{
    return type;
}

void BaseItem::setType(int newType)
{
    type = newType;
}
