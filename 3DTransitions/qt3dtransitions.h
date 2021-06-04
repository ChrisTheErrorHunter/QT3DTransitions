#ifndef QT3DTRANSITIONS_H
#define QT3DTRANSITIONS_H

#include <QMainWindow>
#include <QPainter>
#include <QVector3D>
#include <cmath>

QT_BEGIN_NAMESPACE
namespace Ui { class QT3DTransitions; }
QT_END_NAMESPACE

class QT3DTransitions : public QMainWindow
{
    Q_OBJECT

public:
    QT3DTransitions(QWidget *parent = nullptr);
    ~QT3DTransitions();

private:
    Ui::QT3DTransitions *ui;
    QImage *img;
    int szer, wys;
    int beginX, beginY;
    int prismSize = 100;
    double transX = 0, transY = 0, transZ = 0;
    double rotX = 0, rotY = 0, rotZ = 0;
    double tiltX = 0, tiltY = 0, tiltZ = 0;
    double scaleX = 100, scaleY = 100, scaleZ = 100;
    std::vector<QVector3D> vector;

private slots:
    void paintEvent(QPaintEvent*);
    void putPixel(int x, int y);
    void drawLine(int x0, int y0, int x1, int y1);
    void paintPrism();

    void on_resetButton_clicked();
    void on_exitButton_clicked();
    void on_xTransSlider_valueChanged(int value);
    void on_yTransSlider_valueChanged(int value);
    void on_zTransSlider_valueChanged(int value);
    void on_xRotSlider_valueChanged(int value);
    void on_yRotSlider_valueChanged(int value);
    void on_zRotSlider_valueChanged(int value);
    void on_xTiltSlider_valueChanged(int value);
    void on_yTiltSlider_valueChanged(int value);
    void on_zTiltSlider_valueChanged(int value);
    void on_xScaleSlider_valueChanged(int value);
    void on_yScaleSlider_valueChanged(int value);
    void on_zScaleSlider_valueChanged(int value);
};
#endif // QT3DTRANSITIONS_H
