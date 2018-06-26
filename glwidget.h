#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <qvector.h>
#include <iterator>

#include "cpu.h"

class MyGLWidget : public QGLWidget

{
   Q_OBJECT
public:
    MyGLWidget(QWidget *parent = 0);
    ~MyGLWidget();

     QVector<int> generateRandomVector(int n);///used for testing purposes
     int generateRandomNumber();///used for testing purposes
     void pushRandomNumber();///used for testing purposes

public slots:
    void update();

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;


private:
    int color = 0;
    QVector<int> cpuLoad; ///used for testing purposes
    QVector<int>::iterator it; ///used for testing purposes
    int previousPointX = 0;
    int previousPointY = 0;
    int interval = 5;
    int point = 0;
    CPU cpu;

};

#endif // GLWIDGET_H
