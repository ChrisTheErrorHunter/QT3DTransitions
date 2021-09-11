/********************************************************************************
** Form generated from reading UI file 'qt3dtransitions.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT3DTRANSITIONS_H
#define UI_QT3DTRANSITIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QT3DTransitions
{
public:
    QWidget *centralwidget;
    QFrame *mainFrame;
    QGroupBox *groupBox;
    QSlider *xTransSlider;
    QSlider *zScaleSlider;
    QSlider *yScaleSlider;
    QSlider *zTiltSlider;
    QSlider *xScaleSlider;
    QSlider *xTiltSlider;
    QSlider *xRotSlider;
    QSlider *zRotSlider;
    QSlider *yRotSlider;
    QSlider *yTiltSlider;
    QSlider *zTransSlider;
    QSlider *yTransSlider;
    QPushButton *resetButton;
    QPushButton *exitButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QCheckBox *visibleCheck;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QT3DTransitions)
    {
        if (QT3DTransitions->objectName().isEmpty())
            QT3DTransitions->setObjectName(QString::fromUtf8("QT3DTransitions"));
        QT3DTransitions->resize(800, 560);
        centralwidget = new QWidget(QT3DTransitions);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mainFrame = new QFrame(centralwidget);
        mainFrame->setObjectName(QString::fromUtf8("mainFrame"));
        mainFrame->setGeometry(QRect(10, 10, 512, 512));
        mainFrame->setFrameShape(QFrame::StyledPanel);
        mainFrame->setFrameShadow(QFrame::Raised);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(530, 10, 261, 511));
        xTransSlider = new QSlider(groupBox);
        xTransSlider->setObjectName(QString::fromUtf8("xTransSlider"));
        xTransSlider->setGeometry(QRect(40, 40, 191, 22));
        xTransSlider->setMinimum(-200);
        xTransSlider->setMaximum(200);
        xTransSlider->setOrientation(Qt::Horizontal);
        zScaleSlider = new QSlider(groupBox);
        zScaleSlider->setObjectName(QString::fromUtf8("zScaleSlider"));
        zScaleSlider->setGeometry(QRect(40, 400, 191, 22));
        zScaleSlider->setMinimum(5);
        zScaleSlider->setMaximum(295);
        zScaleSlider->setValue(100);
        zScaleSlider->setOrientation(Qt::Horizontal);
        yScaleSlider = new QSlider(groupBox);
        yScaleSlider->setObjectName(QString::fromUtf8("yScaleSlider"));
        yScaleSlider->setGeometry(QRect(40, 370, 191, 22));
        yScaleSlider->setMinimum(5);
        yScaleSlider->setMaximum(295);
        yScaleSlider->setValue(100);
        yScaleSlider->setOrientation(Qt::Horizontal);
        zTiltSlider = new QSlider(groupBox);
        zTiltSlider->setObjectName(QString::fromUtf8("zTiltSlider"));
        zTiltSlider->setGeometry(QRect(40, 300, 191, 22));
        zTiltSlider->setMinimum(-200);
        zTiltSlider->setMaximum(200);
        zTiltSlider->setOrientation(Qt::Horizontal);
        xScaleSlider = new QSlider(groupBox);
        xScaleSlider->setObjectName(QString::fromUtf8("xScaleSlider"));
        xScaleSlider->setGeometry(QRect(40, 340, 191, 22));
        xScaleSlider->setMinimum(5);
        xScaleSlider->setMaximum(295);
        xScaleSlider->setValue(100);
        xScaleSlider->setOrientation(Qt::Horizontal);
        xTiltSlider = new QSlider(groupBox);
        xTiltSlider->setObjectName(QString::fromUtf8("xTiltSlider"));
        xTiltSlider->setGeometry(QRect(40, 240, 191, 22));
        xTiltSlider->setMinimum(-200);
        xTiltSlider->setMaximum(200);
        xTiltSlider->setOrientation(Qt::Horizontal);
        xRotSlider = new QSlider(groupBox);
        xRotSlider->setObjectName(QString::fromUtf8("xRotSlider"));
        xRotSlider->setGeometry(QRect(40, 140, 191, 22));
        xRotSlider->setMinimum(0);
        xRotSlider->setMaximum(4000);
        xRotSlider->setValue(360);
        xRotSlider->setOrientation(Qt::Horizontal);
        zRotSlider = new QSlider(groupBox);
        zRotSlider->setObjectName(QString::fromUtf8("zRotSlider"));
        zRotSlider->setGeometry(QRect(40, 200, 191, 22));
        zRotSlider->setMinimum(0);
        zRotSlider->setMaximum(4000);
        zRotSlider->setValue(360);
        zRotSlider->setOrientation(Qt::Horizontal);
        yRotSlider = new QSlider(groupBox);
        yRotSlider->setObjectName(QString::fromUtf8("yRotSlider"));
        yRotSlider->setGeometry(QRect(40, 170, 191, 22));
        yRotSlider->setMinimum(0);
        yRotSlider->setMaximum(4000);
        yRotSlider->setValue(360);
        yRotSlider->setOrientation(Qt::Horizontal);
        yTiltSlider = new QSlider(groupBox);
        yTiltSlider->setObjectName(QString::fromUtf8("yTiltSlider"));
        yTiltSlider->setGeometry(QRect(40, 270, 191, 22));
        yTiltSlider->setMinimum(-200);
        yTiltSlider->setMaximum(200);
        yTiltSlider->setOrientation(Qt::Horizontal);
        zTransSlider = new QSlider(groupBox);
        zTransSlider->setObjectName(QString::fromUtf8("zTransSlider"));
        zTransSlider->setGeometry(QRect(40, 100, 191, 22));
        zTransSlider->setMinimum(-400);
        zTransSlider->setMaximum(400);
        zTransSlider->setOrientation(Qt::Horizontal);
        yTransSlider = new QSlider(groupBox);
        yTransSlider->setObjectName(QString::fromUtf8("yTransSlider"));
        yTransSlider->setGeometry(QRect(40, 70, 191, 22));
        yTransSlider->setMinimum(-200);
        yTransSlider->setMaximum(200);
        yTransSlider->setOrientation(Qt::Horizontal);
        resetButton = new QPushButton(groupBox);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setGeometry(QRect(10, 452, 101, 41));
        exitButton = new QPushButton(groupBox);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(130, 450, 101, 41));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 20, 91, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 120, 71, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 220, 91, 21));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 320, 101, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 40, 16, 21));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 140, 16, 21));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 240, 16, 21));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 340, 16, 21));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 70, 16, 21));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 170, 16, 21));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 270, 16, 21));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(20, 370, 16, 21));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 100, 16, 21));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(20, 200, 16, 21));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(20, 300, 16, 21));
        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 400, 16, 21));
        visibleCheck = new QCheckBox(groupBox);
        visibleCheck->setObjectName(QString::fromUtf8("visibleCheck"));
        visibleCheck->setGeometry(QRect(20, 430, 141, 17));
        QT3DTransitions->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QT3DTransitions);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        QT3DTransitions->setMenuBar(menubar);
        statusbar = new QStatusBar(QT3DTransitions);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        QT3DTransitions->setStatusBar(statusbar);

        retranslateUi(QT3DTransitions);

        QMetaObject::connectSlotsByName(QT3DTransitions);
    } // setupUi

    void retranslateUi(QMainWindow *QT3DTransitions)
    {
        QT3DTransitions->setWindowTitle(QCoreApplication::translate("QT3DTransitions", "QT3DTransitions", nullptr));
        groupBox->setTitle(QCoreApplication::translate("QT3DTransitions", "Panel Kontrolny", nullptr));
        resetButton->setText(QCoreApplication::translate("QT3DTransitions", "Reset", nullptr));
        exitButton->setText(QCoreApplication::translate("QT3DTransitions", "Wyj\305\233cie", nullptr));
        label->setText(QCoreApplication::translate("QT3DTransitions", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Translacja</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("QT3DTransitions", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Rotacja</span></p><p><br/></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("QT3DTransitions", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Pochylenie</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("QT3DTransitions", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Skalowanie</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("QT3DTransitions", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">X</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("QT3DTransitions", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">X</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("QT3DTransitions", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">X</span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("QT3DTransitions", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">X</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("QT3DTransitions", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Y</span></p></body></html>", nullptr));
        label_10->setText(QCoreApplication::translate("QT3DTransitions", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Y</span></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("QT3DTransitions", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Y</span></p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("QT3DTransitions", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Y</span></p></body></html>", nullptr));
        label_13->setText(QCoreApplication::translate("QT3DTransitions", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Z</span></p><p><br/></p></body></html>", nullptr));
        label_14->setText(QCoreApplication::translate("QT3DTransitions", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Z</span></p><p><br/></p></body></html>", nullptr));
        label_15->setText(QCoreApplication::translate("QT3DTransitions", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Z</span></p><p><br/></p></body></html>", nullptr));
        label_16->setText(QCoreApplication::translate("QT3DTransitions", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Z</span></p><p><br/></p></body></html>", nullptr));
        visibleCheck->setText(QCoreApplication::translate("QT3DTransitions", "Rysuj tylko widoczne linie", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QT3DTransitions: public Ui_QT3DTransitions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT3DTRANSITIONS_H
