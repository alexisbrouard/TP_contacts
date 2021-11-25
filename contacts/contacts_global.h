#ifndef CONTACTS_GLOBAL_H
#define CONTACTS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CONTACTS_LIBRARY)
#  define CONTACTS_EXPORT Q_DECL_EXPORT
#else
#  define CONTACTS_EXPORT Q_DECL_IMPORT
#endif

#endif // CONTACTS_GLOBAL_H
