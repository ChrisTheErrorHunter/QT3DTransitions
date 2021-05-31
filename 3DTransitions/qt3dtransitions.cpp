#include "qt3dtransitions.h"
#include "ui_qt3dtransitions.h"

QT3DTransitions::QT3DTransitions(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QT3DTransitions)
{
    ui->setupUi(this);
}

QT3DTransitions::~QT3DTransitions()
{
    delete ui;
}

