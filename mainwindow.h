#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <Pdh.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addRoot(QString name, QString description);
    void addChild(QTreeWidgetItem *parent, QString name, QString description);
    QString getProcessorName();
    QString getProcessorNo();
    QString getProcessorPageSize();
    QString getProcessorType();

private slots:
    void on_pushButton_clicked();

    void on_pushit_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
