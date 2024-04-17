QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    SnakeGame.cpp \
    gameoverdialog.cpp \
    generateFood.cpp \
    getRandomWord.cpp \
    highestScores.cpp \
    keyPressEvent.cpp \
    main.cpp \
    moveSnake.cpp \
    paintEvent.cpp \
    soundPlay.cpp \
    widget.cpp

HEADERS += \
    SnakeGame.h \
    gameoverdialog.h \
    soundPlay.h \
    widget.h

FORMS += \
    gameoverdialog.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    res.qrc
