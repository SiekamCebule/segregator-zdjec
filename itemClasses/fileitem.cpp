#include "fileitem.h"

FileItem::FileItem(const QPixmap &image = QPixmap(), const QString &name = "", int parentID = 0, qint64 size = 0)
    : BaseItem(name, parentID, size, File),
      image(image)
{
}
