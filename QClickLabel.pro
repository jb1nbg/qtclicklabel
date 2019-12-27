QT          += widgets
TARGET      = qclicklabel
TEMPLATE    = lib
LIBS        += -L.
target.path = /usr/lib
INSTALLS    += target

header_files.path = /usr/include/qtcomp
header_files.files = qclicklabel.h

INSTALLS    += header_files

include(qclicklabel.pri)
