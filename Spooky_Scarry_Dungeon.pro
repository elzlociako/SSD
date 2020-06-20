TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "C:/SFML-2.5.1/include"

LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

SOURCES += \
        arrow.cpp \
        bags.cpp \
        character.cpp \
        enemy.cpp \
        hero.cpp \
        hud.cpp \
        main.cpp \
        rooms.cpp \
        tilemap.cpp

HEADERS += \
    Biblioteki.h \
    arrow.h \
    bags.h \
    character.h \
    hero.h \
    hud.h \
    rooms.h \
    tilemap.h \
    enemy.h \
