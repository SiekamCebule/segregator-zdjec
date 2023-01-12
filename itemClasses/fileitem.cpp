#include "fileitem.h"

FileItem::FileItem(const QPixmap &image = QPixmap(), qint64 size = 0, const QString &name = "", int parentID = 0)
    : BaseItem(name, parentID, File),
      image(image),
      size(size)
{
}

QPixmap FileItem::getImage() const
{
    return image;
}

void FileItem::setImage(const QPixmap &newImage)
{
    image = newImage;
}
