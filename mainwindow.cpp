#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    setWindowTitle(tr("DSP - Demo - HoughLine"));
    // Set the widget to be a scaled content widget
//        ui->label1  ->setScaledContents(true);
//        ui->label2  ->setScaledContents(true);
//        ui->label3  ->setScaledContents(true);
//        ui->label4  ->setScaledContents(true);
//        ui->label5  ->setScaledContents(true);
//        ui->label6  ->setScaledContents(true);
        ui->display1->setScaledContents(true);
        ui->display2->setScaledContents(true);
        ui->display3->setScaledContents(true);
        ui->display4->setScaledContents(true);
        ui->display5->setScaledContents(true);
        ui->display6->setScaledContents(true);

        // Set size of the widget
//        ui->label1  ->setFixedSize( QLWidth, 15 );
//        ui->label2  ->setFixedSize( QLWidth, 15 );
//        ui->label3  ->setFixedSize( QLWidth, 15 );
//        ui->label4  ->setFixedSize( QLWidth, 15 );
//        ui->label5  ->setFixedSize( QLWidth, 15 );
//        ui->label6  ->setFixedSize( QLWidth, 15 );
        ui->display1->setFixedSize( QLWidth, QLHeight );
        ui->display2->setFixedSize( QLWidth, QLHeight );
        ui->display3->setFixedSize( QLWidth, QLHeight );
        ui->display4->setFixedSize( QLWidth, QLHeight );
        ui->display5->setFixedSize( QLWidth, QLHeight );
        ui->display6->setFixedSize( QLWidth, QLHeight );

    cap.open(1);
    setWindowTitle(QString("openCV HoughLine V %1:%2").arg(CV_MAJOR_VERSION).arg(CV_MINOR_VERSION));


    // Call update every 100ms
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(100);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update(){
    //************************************************************************************* Capture image

    // Capture image from camera, return if fail to load the camera

    if( !cap.isOpened() ) return;

    cap >> capture;



    //************************************************************************************** Preprocessor

    // Camera calibration, make the image undistort.

    // Blur the image so that edges detected by Canny due to noises will reduced
    medianBlur(capture, smooth, 5);
    for( int i = 0; i < 10; i++)
        medianBlur(smooth, smooth, 5);



    // Main Algorithm ********************************************

    // Edge detection
    Canny(smooth, edge, 50, 100, 3);

    // Hough Line
    std::vector<Vec4i> lines;
    HoughLinesP(edge, lines, 1, CV_PI/180, 100, 50, 10 );

    // Draw Hough Line
    capture.copyTo( hline );
    for( size_t i = 0; i < lines.size(); i++ ){
        Vec4i l = lines[i];
        line( hline, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 1, CV_AA);
    }

    // Search red line from all detected line
    std::vector<Vec4i> redLine;
//    for( unsigned int lineIdx = 0; lineIdx < lines.size(); lineIdx++ ){
//        int total = 0, x, y;

//        // calculate color of 2 pixel of each line
//        x = lines[lineIdx][0];
//        y = lines[lineIdx][1];
//        pixel = capture.at<int>( x,y );
//        total += pixel[2] - pixel[1] - pixel[0];

//        x = lines[lineIdx][2];
//        y = lines[lineIdx][3];
//        pixel = capture.at<int>( x,y );
//        total += pixel[2] - pixel[1] - pixel[0];

//        // if it is red, copy the coordinate to redLine
//        if( total > 200 )
//            redLine.push_back( lines[lineIdx] );
//    }

    // Draw Red Lines
    capture.copyTo(hline2);
    for( size_t i = 0; i < redLine.size(); i++ ){
        Vec4i l = redLine[i];
        line( hline2, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(255,0,0), 2, CV_AA);
    }

    // Convert cv::Mat to QImage
    QImage img1 = MatToQImage( capture );
    QImage img2 = MatToQImage( smooth  );
    QImage img3 = MatToQImage( smooth    );
    QImage img4 = MatToQImage( edge   );
    QImage img5 = MatToQImage( hline  );

    // Display QImage
    ui->display1->setPixmap(QPixmap::fromImage(img1));
    ui->display4->setPixmap(QPixmap::fromImage(img4));
    ui->display2->setPixmap(QPixmap::fromImage(img2));
    ui->display3->setPixmap(QPixmap::fromImage(img3));
    ui->display5->setPixmap(QPixmap::fromImage(img5));
}


