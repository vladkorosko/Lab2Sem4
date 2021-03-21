QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    graph_algorithm/edge.cpp \
    graph_algorithm/template_data/graph_list.cpp \
    graph_algorithm/template_data/t_data.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    graph_algorithm/edge.h \
    graph_algorithm/graph.h \
    graph_algorithm/template_data/t_data.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
