#ifndef FIGURA_H
#define FIGURA_H

#include <QWidget>
#include <cmath>

#include "matrix.h"
#include "camera.h"

#define exp 2.7182818284

class Figura : public QWidget
{
    Q_OBJECT
public:
    Figura(QWidget *parent = nullptr);

private:
    void paintEvent(QPaintEvent *event) override;
    const Matrix window(const Matrix &vertices);
    void SetterAlphas(float rotationX, float rotationY);
    int steps = 0;
    //7 вариант - границы
    float xMin = -2;
    float xMax = 2;
    float zMin = -2;
    float zMax = 2;
    float y(const float &x, const float &z)//вписываем вид графика
    {
        return (std::pow(exp, -sqrt(x*x+z*z)) - 0.5);
    }

    int CountSecants = 200;//количество секущих
    Matrix ver;
    Matrix rotation;
    Matrix corners_;
    float AlphaY = 0;// начальный угол
    float AlphaX = 5;
    float dA = 3;// коэф для угла
    int myTimer;
    void timerEvent(QTimerEvent *event) override;
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;
};

#endif // FIGURA
