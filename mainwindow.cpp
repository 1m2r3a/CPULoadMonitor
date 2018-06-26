#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(2);

    addRoot("Processor Name", getProcessorName());
    ui->treeWidget->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), ui->myGLWidget, SLOT(update()));
    timer->start(1500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->treeWidget->currentItem()->setBackgroundColor(0, Qt::red);
    ui->treeWidget->currentItem()->setBackgroundColor(1, Qt::blue);
    QMessageBox::information(this, "Title", "ui->treeWidget->cur ");
}

void MainWindow::addRoot(QString name, QString description)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeWidget);
    itm->setText(0, name);

    itm->setText(1, description);
    itm->setExpanded(true);

    addChild(itm, "Number of processors", getProcessorNo());
    addChild(itm, "Page size", getProcessorPageSize());
    addChild(itm, "Processor type", getProcessorType());
}

void MainWindow::addChild(QTreeWidgetItem *parent, QString name, QString description)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(0, name);
    itm->setText(1, description);
    parent->addChild(itm);
}
#include <intrin.h>
QString MainWindow::getProcessorName()
{
    int CPUInfo[4] = {-1};
    unsigned   nExIds, i =  0;
    char CPUBrandString[0x40];
    // Get the information associated with each extended ID.
    __cpuid(CPUInfo, 0x80000000);
    nExIds = CPUInfo[0];
    for (i=0x80000000; i<=nExIds; ++i)
    {
        __cpuid(CPUInfo, i);
        // Interpret CPU brand string
        if  (i == 0x80000002)
            memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
        else if  (i == 0x80000003)
            memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
        else if  (i == 0x80000004)
            memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
    }
    //string includes manufacturer, model and clockspeed
    return  CPUBrandString;
}

QString MainWindow::getProcessorNo()
{
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);
    return QString::number(sysinfo.dwNumberOfProcessors);
}

QString MainWindow::getProcessorPageSize()
{
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);
    return QString::number(sysinfo.dwPageSize);
}

QString MainWindow::getProcessorType()
{
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);
    return QString::number(sysinfo.dwProcessorType);
}

void MainWindow::on_pushit_clicked()
{
    close();
}
