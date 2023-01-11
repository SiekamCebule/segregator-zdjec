#ifndef IDASSIGNER_H
#define IDASSIGNER_H

#include <QSet>

class IDAssigner
{
public:
    IDAssigner();

    int generateNewID();
    void removeID(int value);
private:
    QSet<int> values;
};

extern IDAssigner idAssigner;

#endif // IDASSIGNER_H
