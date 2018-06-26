#include "glwidget.h"
#include <QCoreApplication>
#include <QtWidgets>
#include <QtOpenGL>


MyGLWidget::MyGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    qDebug() << __FUNCTION__ << "ENTER";
    cpuLoad.push_back(5);

    cpu.init();


}

MyGLWidget::~MyGLWidget(){}

void MyGLWidget::initializeGL()
{
    qDebug() << __FUNCTION__ << "ENTER";
    glClearColor( 0, 0, 0, 1);
    glDrawBuffer(GL_FRONT_LEFT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    glOrtho(0,800,0,500,0,1);
}

void MyGLWidget::paintGL()
{
    //qDebug() << __FUNCTION__ << "ENTER";

    auto iter = cpu.threads.begin();

    if(iter == cpu.threads.end())
    {
        qDebug() << __FUNCTION__ << "Empty CPU LOAD";
        exit(-1);
    }
   Thread* thr = cpu.threads.at(0);

   int crrpoint = thr->query.getRecord(thr->getCounterInfo());//query.getValue(thr->getProcessorTimeName().c_str());
    qDebug("Current point: %d %ls", crrpoint, thr->getProcessorTimeName().c_str());
    qDebug() << previousPointX << " " << previousPointY;

    glLineWidth(2);
    glBegin(GL_LINES);
     glVertex2f(previousPointX, previousPointY);
     glVertex2f(interval, crrpoint);
    glEnd();
    glFlush();

    previousPointX = interval;
    previousPointY = crrpoint;

    interval += 5;
    pushRandomNumber();

}
QVector<int> MyGLWidget::generateRandomVector(int n)
{
   QVector<int> randomVector;
    for (int i=0; i < n ; i++)
    {
        int randomNumber = generateRandomNumber();
        randomVector.push_back(randomNumber);
    }

    for(auto it: randomVector)
        qDebug() << it++;
    return randomVector;
}

int MyGLWidget::generateRandomNumber()
{
    int randomNum = qrand() % 100;
    return randomNum;
}

void MyGLWidget::pushRandomNumber()
{
    cpuLoad.pop_front();
    cpuLoad.push_back(generateRandomNumber());
    //qDebug() << "CPU load size" << cpuLoad.size();
}


void MyGLWidget::resizeGL(int width, int height)
{
    qDebug() << __FUNCTION__ << "ENTER" << width << "X"<< height;
}

void MyGLWidget::update()
{
  //  qDebug() << __FUNCTION__ << "ENTER";
    paintGL();

}
