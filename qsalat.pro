TEMPLATE = app
QT = gui \
 core \
 network \
 webkit \
 phonon \
 sql
CONFIG += qt warn_on release
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
QRC_DIR = build
FORMS = ui/salat.ui \
 ui/qibla.ui \
 ui/hijri.ui \
 ui/worldtime.ui \
 ui/location.ui \
 ui/audio.ui \
 ui/calculation.ui \
 ui/calendar.ui 
HEADERS = src/qsalat.h \
 src/qpray.h \
 src/qhijri.h \
 src/qqibla.h \
 src/qlocation.h \
 src/qaudio.h \
 src/qworldTime.h \
 src/qcalculation.h \
 src/qhijridate.h \
 src/alarm.h \
 src/database.h \
 src/qcalendar.h \
 src/log.h
SOURCES = src/qsalat.cpp \
 src/main.cpp \
 src/qpray.cpp \
 src/qhijri.cpp \
 src/qqibla.cpp \
 src/qlocation.cpp \
 src/qaudio.cpp \
 src/qcalculation.cpp \
 src/qworldTime.cpp \
 src/qhijridate.cpp \
 src/alarm.cpp \
 src/database.cpp \
 src/qcalendar.cpp \
 src/log.cpp
RESOURCES += qrc/salat.qrc qrc/qibla.qrc qrc/worldtime.qrc
TRANSLATIONS = en/qsalat_en.ts fr/qsalat_fr.ts
CODECFORTR = UTF-8
RC_FILE = rc/qsalat.rc
