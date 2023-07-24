QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    _register.cpp \
    dbSolve.cpp \
    main.cpp \
    userinfo.cpp \
    windowsSolve.cpp \
    xiuxian.cpp

HEADERS += \
    _register.h \
    customdelegate.h \
    dbSolve.h \
    userinfo.h \
    windowsSolve.h \
    xiuxian.h

FORMS += \
    _register.ui \
    userinfo.ui \
    xiuxian.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    xiuxian.qrc
