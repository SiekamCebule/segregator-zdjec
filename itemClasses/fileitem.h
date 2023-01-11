#ifndef FILEITEM_H
#define FILEITEM_H

#include "baseitem.h"

#include <QPixmap>


class FileItem : public BaseItem
{
public:
    FileItem(const QPixmap &image, const QString &name, int parentID, qint64 size);

private:
    QPixmap image;
};

#endif // FILEITEM_H
