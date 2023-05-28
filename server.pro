QT -= gui
QT += core network

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        explosion.cpp \
        main.cpp \
        population.cpp \
        server.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    explosion.h \
    population.h \
    server.h

LIBS += -LC:/curl/lib -lcurl
INCLUDEPATH += C:/curl/include
INCLUDEPATH += C:/json/json-develop/include
