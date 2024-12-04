#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bird.h"
#include "pipe.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void createPipes();
    void updatePipes();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene; // Thuộc tính để quản lý QGraphicsScene
    Bird *bird;            // Thuộc tính cho đối tượng Bird
    pipe *toppipe;
    pipe *botpipe;
    std::vector<pipe*> pipes;
protected: // Đảm bảo sử dụng từ khóa 'protected' để ghi đè sự kiện
    void keyPressEvent(QKeyEvent *event) override; // Ghi đè (override) phương thức keyPressEvent
};
#endif // MAINWINDOW_H
