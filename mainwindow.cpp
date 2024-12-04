#include "mainwindow.h"
#include "bird.h"
#include "pipe.h"
#include <QTimer>
#include <QKeyEvent>
#include "./ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),scene(new QGraphicsScene(this)), bird(new Bird())
    , ui(new Ui::MainWindow)
{

    scene->setSceneRect(0, 0, 1280, 720);
    bird->setPos(640, 360);
    QGraphicsView *view = new QGraphicsView(scene, this);
    setCentralWidget(view);
    scene->addItem(bird);
    // Tạo timer để cập nhật trạng thái của chim
    QTimer *timerbird = new QTimer(this);
    connect(timerbird, &QTimer::timeout, bird, &Bird::updatePosition);
    timerbird->start(20); // Gọi mỗi 20ms
    QTimer *timerpipe = new QTimer(this);
    connect(timerpipe, &QTimer::timeout, this, &MainWindow::createPipes);
    timerpipe->start(2000); // Gọi mỗi 2s
    QTimer *timerpipeupdate = new QTimer(this);
    connect(timerpipeupdate, &QTimer::timeout, this, &MainWindow::updatePipes);
    timerpipeupdate->start(20); // Gọi mỗi 2ms
    view->setRenderHint(QPainter::Antialiasing);  // Tăng chất lượng đồ họa (nếu cần)
    view->setRenderHint(QPainter::SmoothPixmapTransform);  // Làm mịn các hình ảnh
    setCentralWidget(view);

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Key Pressed:" << event->key();

    if (event->key() == Qt::Key_Space) // Nhấn phím cách
    {
        bird->jump();
    }
}
void MainWindow:: createPipes(){
    pipe *newtoppipe = new pipe(true);
    pipe *newbotpipe = new pipe(false);
    pipes.push_back(newtoppipe);  // Thêm ống mới vào danh sách
    pipes.push_back(newbotpipe);
    scene->addItem(newtoppipe);
    scene->addItem(newbotpipe);
    newtoppipe->setPos(1200, rand() % 200);
    newtoppipe->setScale(0.5);
    newbotpipe->setPos(1200, newtoppipe->y() + 500);
    newbotpipe->setScale(0.5);
}
void MainWindow:: updatePipes(){
    for (auto it = pipes.begin(); it != pipes.end(); ) {
        (*it)->move();

        // Nếu ống đã bị xóa, loại bỏ nó khỏi vector
        if ((*it)->isDeleted()) {  // Giả sử bạn có một phương thức kiểm tra xóa
            it = pipes.erase(it);  // Loại bỏ ống khỏi vector
        } else {
            ++it;  // Tiến tới phần tử tiếp theo
        }
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
