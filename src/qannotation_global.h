#pragma once

#ifndef QT_STATIC
#  if defined(QT_BUILD_SQL_LIB)
#    define Q_ANNOTATION_EXPORT Q_DECL_EXPORT
#  else
#    define Q_ANNOTATION_EXPORT Q_DECL_IMPORT
#  endif
#else
#  define Q_ANNOTATION_EXPORT
#endif
