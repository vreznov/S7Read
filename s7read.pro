QT += gui widgets

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    ks7reader.cpp \
    snap7/s7_client.cpp \
    snap7/s7_isotcp.cpp \
    snap7/s7_micro_client.cpp \
    snap7/s7_peer.cpp \
    snap7/snap_msgsock.cpp \
    snap7/snap_sysutils.cpp \
    snap7/snap_threads.cpp \
    mainwindow.cpp

HEADERS += \
    ks7reader.h \
    m_macro.h \
    snap7/s7_client.h \
    snap7/s7_firmware.h \
    snap7/s7_isotcp.h \
    snap7/s7_micro_client.h \
    snap7/s7_partner.h \
    snap7/s7_peer.h \
    snap7/s7_server.h \
    snap7/s7_text.h \
    snap7/s7_types.h \
    snap7/snap_msgsock.h \
    snap7/snap_platform.h \
    snap7/snap_sysutils.h \
    snap7/snap_tcpsrvr.h \
    snap7/snap_threads.h \
    snap7/snap7_libmain.h \
    snap7/sol_threads.h \
    snap7/win_threads.h \
    mainwindow.h

INCLUDEPATH += $$PWD//snap7

# ws2_32.lib WINDOWS SOCKET库
# winmm.lib windows标准库
LIBS += -lws2_32  -lwinmm

FORMS += \
    mainwindow.ui
