#include "mainwindow.h"
#include "MaskPath.h"
#include "ui_mainwindow.h"

#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
	ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &QCoreApplication::quit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int iw = 5;
    QPainterPath path = MaskPath::DrawMask(this->rect(),24, iw);
    painter.fillPath(path, Qt::gray);

    QPainterPath inlinePath = path;

    QColor border = isMouseOver ? Qt::white : Qt::gray;
    border.setAlpha(250);
    painter.setPen(QPen(border, iw, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin));
    painter.drawPath(inlinePath);
    QWidget::paintEvent(event);

}

void MainWindow::enterEvent(QEnterEvent *event)
{
    qDebug() << "inside ";
    isMouseOver = true;
    update();
    QWidget::enterEvent(event);
}

void MainWindow::leaveEvent(QEvent *event)
{
    isMouseOver = false;
    update();
    qDebug() << "outside ";
    QWidget::leaveEvent(event);

}

