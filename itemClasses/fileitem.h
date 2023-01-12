#ifndef FILEITEM_H
#define FILEITEM_H

#include "baseitem.h"

#include <QPixmap>


class FileItem : public BaseItem
{
public:
    FileItem(const QPixmap &image, qint64 size, const QString &name, int parentID);

    QPixmap getImage() const;
    void setImage(const QPixmap &newImage);

private:
    QPixmap image;
    qint64 size;
};

#endif // FILEITEM_H
