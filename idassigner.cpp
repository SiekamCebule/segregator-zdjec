#include "idassigner.h"

IDAssigner::IDAssigner()
{

}

int IDAssigner::generateNewID()
{
    int ID = 1;
    while(true)
    {
        if(values.contains(ID) == false){
            values.insert(ID);
            break;
        }
        else
            ID++;
    }
    return ID;
}

void IDAssigner::removeID(int value)
{
    QSet<int>::const_iterator iterator = values.find(value);
    values.erase(iterator);
}

IDAssigner idAssigner;
