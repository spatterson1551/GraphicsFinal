/********************************************************************************
** Form generated from reading UI file 'program1.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRAM1_H
#define UI_PROGRAM1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "MyGLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_Program1Class
{
public:
    QWidget *centralWidget;
    MyGLWidget *widget;
    QPushButton *pushButton;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QGroupBox *groupBox;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QFrame *line;
    QGroupBox *groupBox_2;
    QDial *dial;
    QDial *dial_2;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QFrame *line_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_14;
    QFrame *line_3;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QFrame *line_4;
    QPushButton *pushButton_20;
    QFrame *line_5;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QPushButton *pushButton_23;
    QPushButton *pushButton_24;
    QPushButton *pushButton_25;
    QPushButton *pushButton_15;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Program1Class)
    {
        if (Program1Class->objectName().isEmpty())
            Program1Class->setObjectName(QStringLiteral("Program1Class"));
        Program1Class->resize(601, 668);
        centralWidget = new QWidget(Program1Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new MyGLWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 581, 341));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 370, 75, 23));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(40, 400, 75, 23));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(160, 370, 75, 23));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 440, 241, 91));
        pushButton_8 = new QPushButton(groupBox);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(100, 20, 41, 23));
        pushButton_9 = new QPushButton(groupBox);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(100, 50, 41, 23));
        pushButton_10 = new QPushButton(groupBox);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(50, 20, 41, 23));
        pushButton_11 = new QPushButton(groupBox);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(50, 50, 41, 23));
        pushButton_12 = new QPushButton(groupBox);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(160, 20, 41, 23));
        pushButton_13 = new QPushButton(groupBox);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(160, 50, 41, 23));
        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(140, 20, 20, 51));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(270, 360, 321, 171));
        dial = new QDial(groupBox_2);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(20, 30, 161, 141));
        dial->setMaximum(360);
        dial->setWrapping(true);
        dial->setNotchTarget(3.7);
        dial_2 = new QDial(groupBox_2);
        dial_2->setObjectName(QStringLiteral("dial_2"));
        dial_2->setGeometry(QRect(170, 30, 151, 141));
        dial_2->setMaximum(360);
        dial_2->setWrapping(true);
        dial_2->setNotchTarget(3.7);
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 61, 41));
        label->setWordWrap(true);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 20, 51, 41));
        label_2->setWordWrap(true);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 540, 571, 71));
        pushButton_2 = new QPushButton(groupBox_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 30, 91, 23));
        pushButton_3 = new QPushButton(groupBox_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(130, 10, 31, 23));
        line_2 = new QFrame(groupBox_3);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(110, 20, 20, 41));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        pushButton_4 = new QPushButton(groupBox_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(130, 40, 31, 23));
        pushButton_5 = new QPushButton(groupBox_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(170, 10, 31, 23));
        pushButton_14 = new QPushButton(groupBox_3);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(170, 40, 31, 23));
        line_3 = new QFrame(groupBox_3);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(200, 20, 20, 41));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        pushButton_16 = new QPushButton(groupBox_3);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(220, 10, 31, 23));
        pushButton_17 = new QPushButton(groupBox_3);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(220, 40, 31, 23));
        pushButton_18 = new QPushButton(groupBox_3);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setGeometry(QRect(270, 10, 61, 23));
        pushButton_19 = new QPushButton(groupBox_3);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setGeometry(QRect(270, 40, 61, 23));
        line_4 = new QFrame(groupBox_3);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(250, 20, 20, 41));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        pushButton_20 = new QPushButton(groupBox_3);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        pushButton_20->setGeometry(QRect(350, 10, 51, 23));
        line_5 = new QFrame(groupBox_3);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(330, 20, 20, 41));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        pushButton_21 = new QPushButton(groupBox_3);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        pushButton_21->setGeometry(QRect(410, 10, 51, 23));
        pushButton_22 = new QPushButton(groupBox_3);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        pushButton_22->setGeometry(QRect(470, 10, 51, 23));
        pushButton_23 = new QPushButton(groupBox_3);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));
        pushButton_23->setGeometry(QRect(350, 40, 51, 23));
        pushButton_24 = new QPushButton(groupBox_3);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));
        pushButton_24->setGeometry(QRect(410, 40, 51, 23));
        pushButton_25 = new QPushButton(groupBox_3);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));
        pushButton_25->setGeometry(QRect(470, 40, 51, 23));
        pushButton_15 = new QPushButton(centralWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(160, 400, 75, 23));
        Program1Class->setCentralWidget(centralWidget);
        groupBox_2->raise();
        widget->raise();
        pushButton->raise();
        pushButton_6->raise();
        pushButton_7->raise();
        groupBox->raise();
        groupBox_3->raise();
        pushButton_15->raise();
        menuBar = new QMenuBar(Program1Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 601, 21));
        Program1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Program1Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Program1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Program1Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Program1Class->setStatusBar(statusBar);

        retranslateUi(Program1Class);
        QObject::connect(pushButton, SIGNAL(pressed()), widget, SLOT(cameraZoom()));
        QObject::connect(pushButton_6, SIGNAL(pressed()), widget, SLOT(cameraOut()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), widget, SLOT(selectFile()));
        QObject::connect(pushButton_8, SIGNAL(pressed()), widget, SLOT(lightOut()));
        QObject::connect(pushButton_10, SIGNAL(pressed()), widget, SLOT(lightIn()));
        QObject::connect(pushButton_11, SIGNAL(pressed()), widget, SLOT(lightLeft()));
        QObject::connect(pushButton_9, SIGNAL(pressed()), widget, SLOT(lightRight()));
        QObject::connect(dial, SIGNAL(valueChanged(int)), widget, SLOT(camUpDown(int)));
        QObject::connect(dial_2, SIGNAL(valueChanged(int)), widget, SLOT(camLeftRight(int)));
        QObject::connect(pushButton_12, SIGNAL(pressed()), widget, SLOT(lightUp()));
        QObject::connect(pushButton_13, SIGNAL(pressed()), widget, SLOT(lightDown()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), widget, SLOT(nextGeometry()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), widget, SLOT(objectLeft()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), widget, SLOT(objectIn()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), widget, SLOT(objectRight()));
        QObject::connect(pushButton_14, SIGNAL(clicked()), widget, SLOT(objectOut()));
        QObject::connect(pushButton_15, SIGNAL(clicked()), widget, SLOT(subDivide()));
        QObject::connect(pushButton_16, SIGNAL(clicked()), widget, SLOT(objectUp()));
        QObject::connect(pushButton_17, SIGNAL(clicked()), widget, SLOT(objectDown()));
        QObject::connect(pushButton_18, SIGNAL(clicked()), widget, SLOT(rotateCW()));
        QObject::connect(pushButton_19, SIGNAL(clicked()), widget, SLOT(rotateCCW()));
        QObject::connect(pushButton_20, SIGNAL(clicked()), widget, SLOT(scaleUpX()));
        QObject::connect(pushButton_23, SIGNAL(clicked()), widget, SLOT(scaleDownX()));
        QObject::connect(pushButton_21, SIGNAL(clicked()), widget, SLOT(scaleUpY()));
        QObject::connect(pushButton_24, SIGNAL(clicked()), widget, SLOT(scaleDownY()));
        QObject::connect(pushButton_22, SIGNAL(clicked()), widget, SLOT(scaleUpZ()));
        QObject::connect(pushButton_25, SIGNAL(clicked()), widget, SLOT(scaleDownZ()));

        QMetaObject::connectSlotsByName(Program1Class);
    } // setupUi

    void retranslateUi(QMainWindow *Program1Class)
    {
        Program1Class->setWindowTitle(QApplication::translate("Program1Class", "Program1", 0));
        pushButton->setText(QApplication::translate("Program1Class", "ZoomIn", 0));
        pushButton_6->setText(QApplication::translate("Program1Class", "ZoomOut", 0));
        pushButton_7->setText(QApplication::translate("Program1Class", "Select File", 0));
        groupBox->setTitle(QApplication::translate("Program1Class", "LIGHT", 0));
        pushButton_8->setText(QApplication::translate("Program1Class", "+ Z", 0));
        pushButton_9->setText(QApplication::translate("Program1Class", "+ X", 0));
        pushButton_10->setText(QApplication::translate("Program1Class", "- Z", 0));
        pushButton_11->setText(QApplication::translate("Program1Class", "- X", 0));
        pushButton_12->setText(QApplication::translate("Program1Class", "+ Y", 0));
        pushButton_13->setText(QApplication::translate("Program1Class", "- Y", 0));
        groupBox_2->setTitle(QApplication::translate("Program1Class", "CAMERA", 0));
        label->setText(QApplication::translate("Program1Class", "Up/Down", 0));
        label_2->setText(QApplication::translate("Program1Class", "Left/Right", 0));
        groupBox_3->setTitle(QApplication::translate("Program1Class", "Scene Manipulation", 0));
        pushButton_2->setText(QApplication::translate("Program1Class", "Next Geometry", 0));
        pushButton_3->setText(QApplication::translate("Program1Class", "- X", 0));
        pushButton_4->setText(QApplication::translate("Program1Class", "- Z", 0));
        pushButton_5->setText(QApplication::translate("Program1Class", "+ X", 0));
        pushButton_14->setText(QApplication::translate("Program1Class", "+ Z", 0));
        pushButton_16->setText(QApplication::translate("Program1Class", "+ Y", 0));
        pushButton_17->setText(QApplication::translate("Program1Class", "- Y", 0));
        pushButton_18->setText(QApplication::translate("Program1Class", "+ Rotation", 0));
        pushButton_19->setText(QApplication::translate("Program1Class", "- Rotation", 0));
        pushButton_20->setText(QApplication::translate("Program1Class", "+scaleX", 0));
        pushButton_21->setText(QApplication::translate("Program1Class", "+scaleY", 0));
        pushButton_22->setText(QApplication::translate("Program1Class", "+scaleZ", 0));
        pushButton_23->setText(QApplication::translate("Program1Class", "-scaleX", 0));
        pushButton_24->setText(QApplication::translate("Program1Class", "-scaleY", 0));
        pushButton_25->setText(QApplication::translate("Program1Class", "-scaleZ", 0));
        pushButton_15->setText(QApplication::translate("Program1Class", "Sub-Divide", 0));
    } // retranslateUi

};

namespace Ui {
    class Program1Class: public Ui_Program1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRAM1_H
