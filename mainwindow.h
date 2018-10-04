#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "MatToQImage.h"
using namespace cv;

// Define the size of QLabel
#define scale  1.3
#define QLHeight scale*240
#define QLWidth  scale*320

// Define the title for each QLabel
//#define _label1 "Capture"
//#define _label2 "Smooth"
//#define _label3 "Edge"
//#define _label4 "Hough line"
//#define _label5 "Red line found"
//#define _label6 ""

// Define the resolution of camera
//#define height 480
//#define width  640


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    VideoCapture cap;
    Mat capture, smooth, edge, hline, hline2;


private slots:
    void update();

};

#endif // MAINWINDOW_H
