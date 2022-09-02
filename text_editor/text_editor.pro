QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets

CONFIG += c++17

SOURCES += \
    sources/main.cpp \
    sources/main_window.cpp \
    sources/status_bar.cpp

HEADERS += \
    headers/main_window.h \
    headers/status_bar.h

FORMS += \
    forms/main_window.ui

RESOURCES += \
    resource.qrc

RC_FILE += \
    config/text_editor.rc

OTHER_FILES += \
    config/text_editor.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
