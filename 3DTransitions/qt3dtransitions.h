#ifndef QT3DTRANSITIONS_H
#define QT3DTRANSITIONS_H

#include <QMainWindow>
#include <QPainter>
#include <QVector3D>
#include <cmath>
#include <cstdlib>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class QT3DTransitions; }
QT_END_NAMESPACE

enum fmode
{
    minX,
    minY,
    maxX,
    maxY
};

class QT3DTransitions : public QMainWindow
{
    Q_OBJECT

public:
    QT3DTransitions(QWidget *parent = nullptr);
    ~QT3DTransitions();

private:
    Ui::QT3DTransitions *ui;
    QImage *img;
    QImage *sourceTex;
    int szer, wys;
    int beginX, beginY;
    double prismSize = 100.0;
    double transX = 0.0, transY = 0.0, transZ = 0.0;
    double rotX = 0.0, rotY = 0.0, rotZ = 0.0;
    double tiltX = 0.0, tiltY = 0.0, tiltZ = 0.0;
    double scaleX = 1.0, scaleY = 1.0, scaleZ = 1.0;
    std::vector<QVector3D> vector;
    std::vector<QPoint> sourceVec;
    std::vector<QPoint> targetVec;

private slots:
    void paintEvent(QPaintEvent*);
    void putPixel(int x, int y, QColor color, QImage *img);
    void drawLine(double x0, double y0, double x1, double y1);
    void paintPrism();
    void texture(std::vector<QPoint> vector);
    int findBorder(std::vector<QPoint> vector, fmode mode);
    QColor pixelColor(int x, int y, QImage *img);
    bool visibilityCheck(int x1, int x2, int y1, int y2, int z1, int z2);
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
    void on_visibleCheck_clicked();
};
#endif // QT3DTRANSITIONS_H
