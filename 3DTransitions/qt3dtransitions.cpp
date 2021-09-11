#include "qt3dtransitions.h"
#include "ui_qt3dtransitions.h"

QT3DTransitions::QT3DTransitions(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QT3DTransitions)
{
    ui->setupUi(this);
    szer = ui->mainFrame->width();
    wys = ui->mainFrame->height();
    beginX = ui->mainFrame->x();
    beginY = ui->mainFrame->y();
    img = new QImage(szer, wys, QImage::Format_RGB32);
    img->fill(Qt::black);
    sourceTex = new QImage(":/woodtex.jpg");
    sourceVec.push_back(QPoint(256, 1));
    sourceVec.push_back(QPoint(510, 1));
    sourceVec.push_back(QPoint(510, 510));
    on_resetButton_clicked();
    qDebug()<<szer<<" "<<wys;
}

QT3DTransitions::~QT3DTransitions()
{
    delete ui;
}

void QT3DTransitions::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.drawImage(beginX, beginY, *img);
}

void QT3DTransitions::putPixel(int x, int y, QColor color, QImage *img)
{
    unsigned char *pixel;
    pixel = img -> bits();
    if(!(x <= 0 || x >= szer || y <= 0 || y >= wys))
    {
        pixel[szer * 4 * y + 4 * x] = uchar(color.blue());
        pixel[szer * 4 * y + 4 * x + 1] = uchar(color.green());
        pixel[szer * 4 * y + 4 * x + 2] = uchar(color.red());
    }
}

void QT3DTransitions::drawLine(double x0, double y0, double x1, double y1) //nowa funkcja od rysowania linii, poprzednia posiadała buga,
{                                                                           // który ujawnił się dopiero przy rysowaniu ścian widocznych
    double a = (y1 - y0) / (x1 - x0);
    double b = y0 - a * x0;
    double c = (x1 - x0) / (y1 - y0);
    double d = x0 - c * y0;
    double y;
    if(x0 > x1) std::swap(x0, x1);
    if(y0 > y1) std::swap(y0, y1);
    if(abs(a) <= 1)
    {
        for(int x = x0; x <= x1; x++)
        {
            y = a * x + b;
            putPixel(x, y, Qt::white, img);
        }
    }
    else
    {
        for(int x = y0; x <= y1; x++)
        {
            y = c * x + d;
            putPixel(y, x, Qt::white, img);
        }
    }
}

void QT3DTransitions::paintPrism()
{
    double tmpX, tmpY, tmpZ;
    img->fill(Qt::black);
    vector.clear();
    vector.push_back(QVector3D((szer / 2) - (prismSize / 2), (wys / 2) - (prismSize / 2), 0));
    vector.push_back(QVector3D((szer / 2) + (prismSize / 2), (wys / 2) - (prismSize / 2), 0));
    vector.push_back(QVector3D((szer / 2) + (prismSize / 2), (wys / 2) + (prismSize / 2), 0));
    vector.push_back(QVector3D((szer / 2) - (prismSize / 2), (wys / 2) + (prismSize / 2), 0));
    vector.push_back(QVector3D((szer / 2) - (prismSize / 2), (wys / 2) - (prismSize / 2), prismSize));
    vector.push_back(QVector3D((szer / 2) + (prismSize / 2), (wys / 2) - (prismSize / 2), prismSize));
    vector.push_back(QVector3D((szer / 2) + (prismSize / 2), (wys / 2) + (prismSize / 2), prismSize));
    vector.push_back(QVector3D((szer / 2) - (prismSize / 2), (wys / 2) + (prismSize / 2), prismSize));
    for(int i = 0; i < (int)vector.size(); i++)
    {
        vector[i].setX(vector[i].x() - szer / 2);
        vector[i].setY(vector[i].y() - wys / 2);
        tmpY = ((vector[i].y() * cos(rotX)) - (vector[i].z() * sin(rotX))); //rotacjaX, Rotacje liczone na zmiennych tymczasowych,
        tmpZ = ((vector[i].y() * sin(rotX)) + (vector[i].z() * cos(rotX))); //w innym wypadku pojawia się bug przy konwersji typów zmiennych
        vector[i].setY(tmpY);
        vector[i].setZ(tmpZ);
        tmpX = ((vector[i].x() * cos(rotY)) - (vector[i].z() * sin(rotY))); //rotacjaY
        tmpZ = ((vector[i].x() * sin(rotY)) + (vector[i].z() * cos(rotY)));
        vector[i].setX(tmpX);
        vector[i].setZ(tmpZ);
        tmpX = ((vector[i].x() * cos(rotZ)) - (vector[i].y() * sin(rotZ))); //rotacjaZ
        tmpY = ((vector[i].x() * sin(rotZ)) + (vector[i].y() * cos(rotZ)));
        vector[i].setX(tmpX);
        vector[i].setY(tmpY);
        vector[i].setY(vector[i].y() + (vector[i].z() * tiltY)); //tiltX
        vector[i].setZ(vector[i].z() + (vector[i].z() * tiltZ));
        vector[i].setX(vector[i].x() + (vector[i].z() * tiltX)); //tiltY
        vector[i].setZ(vector[i].z() + (vector[i].z() * tiltZ));
        vector[i].setX(vector[i].x() + (vector[i].z() * tiltX)); //tiltZ
        vector[i].setY(vector[i].y() + (vector[i].z() * tiltY));
        vector[i].setX((vector[i].x() * scaleX) + (szer / 2) + transX); //skalowanie i transpozycja
        vector[i].setY((vector[i].y() * scaleY) + (wys / 2) + transY);
        vector[i].setZ((vector[i].z() * scaleZ) + transZ);
        vector[i].setX((vector[i].x() / ((vector[i].z() / szer) + 1.0))); //rzut do 2D
        vector[i].setY((vector[i].y() / ((vector[i].z() / wys) + 1.0)));
    }
    if(ui->visibleCheck->isChecked())
    {
        if(visibilityCheck(vector[0].x(), vector[0].y(), vector[4].x(), vector[4].y(), vector[1].x(), vector[1].y())) //Góra
        {
            drawLine(vector[0].x(), vector[0].y(), vector[4].x(), vector[4].y());
            drawLine(vector[0].x(), vector[0].y(), vector[1].x(), vector[1].y());
            drawLine(vector[5].x(), vector[5].y(), vector[1].x(), vector[1].y());
            drawLine(vector[5].x(), vector[5].y(), vector[4].x(), vector[4].y());
        }
        if(visibilityCheck(vector[3].x(), vector[3].y(), vector[2].x(), vector[2].y(), vector[7].x(), vector[7].y())) //Dół
        {
            drawLine(vector[3].x(), vector[3].y(), vector[2].x(), vector[2].y());
            drawLine(vector[3].x(), vector[3].y(), vector[7].x(), vector[7].y());
            drawLine(vector[6].x(), vector[6].y(), vector[2].x(), vector[2].y());
            drawLine(vector[6].x(), vector[6].y(), vector[7].x(), vector[7].y());
        }
        if(visibilityCheck(vector[0].x(), vector[0].y(), vector[1].x(), vector[1].y(), vector[3].x(), vector[3].y())) //Przód
        {
            drawLine(vector[0].x(), vector[0].y(), vector[1].x(), vector[1].y());
            drawLine(vector[0].x(), vector[0].y(), vector[3].x(), vector[3].y());
            drawLine(vector[2].x(), vector[2].y(), vector[3].x(), vector[3].y());
            drawLine(vector[2].x(), vector[2].y(), vector[1].x(), vector[1].y());
        }
        if(visibilityCheck(vector[4].x(), vector[4].y(), vector[7].x(), vector[7].y(), vector[5].x(), vector[5].y())) //Tył
        {
            drawLine(vector[4].x(), vector[4].y(), vector[7].x(), vector[7].y());
            drawLine(vector[4].x(), vector[4].y(), vector[5].x(), vector[5].y());
            drawLine(vector[6].x(), vector[6].y(), vector[5].x(), vector[5].y());
            drawLine(vector[6].x(), vector[6].y(), vector[7].x(), vector[7].y());
        }
        if(visibilityCheck(vector[4].x(), vector[4].y(), vector[0].x(), vector[0].y(), vector[7].x(), vector[7].y())) //Lewa
        {
           drawLine(vector[0].x(), vector[0].y(), vector[4].x(), vector[4].y());
           drawLine(vector[0].x(), vector[0].y(), vector[3].x(), vector[3].y());
           drawLine(vector[7].x(), vector[7].y(), vector[3].x(), vector[3].y());
           drawLine(vector[7].x(), vector[7].y(), vector[4].x(), vector[4].y());
        }
        if(visibilityCheck(vector[1].x(), vector[1].y(), vector[5].x(), vector[5].y(), vector[2].x(), vector[2].y())) //Prawa
        {
            drawLine(vector[1].x(), vector[1].y(), vector[2].x(), vector[2].y());
            drawLine(vector[1].x(), vector[1].y(), vector[5].x(), vector[5].y());
            drawLine(vector[6].x(), vector[6].y(), vector[2].x(), vector[2].y());
            drawLine(vector[6].x(), vector[6].y(), vector[5].x(), vector[5].y());
        }
    }
    else
    {
        drawLine(vector[0].x(), vector[0].y(), vector[1].x(), vector[1].y()); //góra
        drawLine(vector[0].x(), vector[0].y(), vector[4].x(), vector[4].y());
        drawLine(vector[4].x(), vector[4].y(), vector[5].x(), vector[5].y());
        drawLine(vector[5].x(), vector[5].y(), vector[1].x(), vector[1].y());
        drawLine(vector[2].x(), vector[2].y(), vector[3].x(), vector[3].y()); //dół
        drawLine(vector[2].x(), vector[2].y(), vector[6].x(), vector[6].y());
        drawLine(vector[3].x(), vector[3].y(), vector[7].x(), vector[7].y());
        drawLine(vector[6].x(), vector[6].y(), vector[7].x(), vector[7].y());
        drawLine(vector[0].x(), vector[0].y(), vector[3].x(), vector[3].y()); //ściany
        drawLine(vector[1].x(), vector[1].y(), vector[2].x(), vector[2].y());
        drawLine(vector[4].x(), vector[4].y(), vector[7].x(), vector[7].y());
        drawLine(vector[5].x(), vector[5].y(), vector[6].x(), vector[6].y());
    }
    update();
}

bool QT3DTransitions::visibilityCheck(int x0, int y0, int x1, int y1, int x2, int y2)
{
    return ((((x1 - x0) * (y2 - y0)) - ((x2 - x0) * (y1 - y0))) > 0); // |M| > 0 dla widocznych : zródło https://en.wikipedia.org/wiki/Back-face_culling
}

void QT3DTransitions::texture(std::vector<QPoint> vector)
{
    double xa, xb, xc;
    double ya, yb, yc;
    double u, v, w;
    double mainMatrixDet, vDet, wDet;
    int Ymax = findBorder(vector, maxY);
    int Ymin = findBorder(vector, minY);
    int Xmax = findBorder(vector, maxX);
    int Xmin = findBorder(vector, minX);
    QColor cColor;
    xa = vector[0].x();
    xb = vector[1].x();
    xc = vector[2].x();
    ya = vector[0].y();
    yb = vector[1].y();
    yc = vector[2].y();
    mainMatrixDet = (((xb - xa) * (yc - ya)) - ((yb - ya) * (xc - xa)));
    for(int yi = Ymin; yi < Ymax; yi++)
    {
        for(int xi = Xmin; xi < Xmax; xi++)
        {
            vDet = ((xi - xa) * (yc - ya)) - ((xc - xa) * (yi - ya));
            v = vDet / mainMatrixDet;
            wDet = ((xb - xa) * (yi - ya)) - ((yb - ya) * (xi - xa));
            w = wDet / mainMatrixDet;
            u = (1 - w - v);

            if((0 <= u) && (u <= 1) && (0 <= v) && (v <= 1) && (0 <= w) && (w <= 1))
            {
                double xst, yst, xat, yat, xbt, ybt, xct, yct;
                xat = sourceVec[0].x();
                yat = sourceVec[0].y();
                xbt = sourceVec[1].x();
                ybt = sourceVec[1].y();
                xct = sourceVec[2].x();
                yct = sourceVec[2].y();
                xst = (u * xat) + v * (xbt) + w * (xct);
                yst = (u * yat) + v * (ybt) + w * (yct);
                cColor = pixelColor(xst, yst, sourceTex);
                putPixel(xi, yi, cColor, img);;
                //targetTex->setPixelColor(xi,yi, sourceTex->pixel(xst, yst));
                update();
            }
        }
    }
}

QColor QT3DTransitions::pixelColor(int x, int y, QImage *img)
{
    x += beginX - 10;
    y += beginY - 10;
    QColor ret;
    unsigned char *pixel;
    pixel = img->bits();
    ret.setBlue(pixel[szer * 4 * y + 4 * x]);
    ret.setGreen(pixel[szer * 4 * y + 4 * x + 1]);
    ret.setRed(pixel[szer * 4 * y + 4 * x + 2]);
    return ret;
}

int QT3DTransitions::findBorder(std::vector<QPoint> vector, fmode mode)
{
    int resault;
    if(mode == minX)
    {
        resault = vector[0].x();
        for(int i = 1; i < 3; i++)
        {
            if(resault > vector[i].x())
            {
                resault = vector[i].x();
            }
        }
    }
    else if(mode == minY)
    {
        resault = vector[0].y();
        for(int i = 1; i < 3; i++)
        {
            if(resault > vector[i].y())
            {
                resault = vector[i].y();
            }
        }
    }
    else if(mode == maxX)
    {
        resault = vector[0].x();
        for(int i = 1; i < 3; i++)
        {
            if(resault < vector[i].x())
            {
                resault = vector[i].x();
            }
        }
    }
    else if(mode == maxY)
    {
        resault = vector[0].y();
        for(int i = 1; i < 3; i++)
        {
            if(resault < vector[i].y())
            {
                resault = vector[i].y();
            }
        }
    }
    else resault = -1;
    return resault;
}

void QT3DTransitions::on_resetButton_clicked()
{
    transX = 0; transY = 0; transZ = 0;
    rotX = 0.0, rotY = 0.0, rotZ = 0.0;
    tiltX = 0; tiltY = 0; tiltZ = 0;
    scaleX = 1.0; scaleY = 1.0; scaleZ = 1.0;
    ui->xTransSlider->setValue(transX);
    ui->yTransSlider->setValue(transY);
    ui->zTransSlider->setValue(transZ);
    ui->xRotSlider->setValue(rotX * 180);
    ui->yRotSlider->setValue(rotY * 180);
    ui->zRotSlider->setValue(rotZ * 180);
    ui->xTiltSlider->setValue(tiltX);
    ui->yTiltSlider->setValue(tiltY);
    ui->zTiltSlider->setValue(tiltZ);
    ui->xScaleSlider->setValue(scaleX * 100);
    ui->yScaleSlider->setValue(scaleY * 100);
    ui->zScaleSlider->setValue(scaleZ * 100);
    paintPrism();
    update();
}

void QT3DTransitions::on_exitButton_clicked()
{
    qApp->quit();
}

void QT3DTransitions::on_xTransSlider_valueChanged(int value)
{
    transX = (double)value;
    paintPrism();
}

void QT3DTransitions::on_yTransSlider_valueChanged(int value)
{
    transY = (double)value;
    paintPrism();
}

void QT3DTransitions::on_zTransSlider_valueChanged(int value)
{
    transZ = (double)value;
    paintPrism();
}

void QT3DTransitions::on_xRotSlider_valueChanged(int value)
{
    rotX = (double)value / 180.0;
    paintPrism();
}

void QT3DTransitions::on_yRotSlider_valueChanged(int value)
{
    rotY = (double)value / 180.0;;
    paintPrism();
}

void QT3DTransitions::on_zRotSlider_valueChanged(int value)
{
    rotZ = (double)value / 180.0;;
    paintPrism();
}

void QT3DTransitions::on_xTiltSlider_valueChanged(int value)
{
    tiltX = (double)value / 100.0;
    paintPrism();
}

void QT3DTransitions::on_yTiltSlider_valueChanged(int value)
{
    tiltY = (double)value / 100.0;
    paintPrism();
}

void QT3DTransitions::on_zTiltSlider_valueChanged(int value)
{
    tiltZ = (double)value / 100.0;
    paintPrism();
}

void QT3DTransitions::on_xScaleSlider_valueChanged(int value)
{
    scaleX = (double)value / 100.0;
    paintPrism();
}

void QT3DTransitions::on_yScaleSlider_valueChanged(int value)
{
    scaleY = (double)value / 100.0;
    paintPrism();
}

void QT3DTransitions::on_zScaleSlider_valueChanged(int value)
{
    scaleZ = (double)value / 100.0;
    paintPrism();
}

void QT3DTransitions::on_visibleCheck_clicked()
{
    paintPrism();
}
