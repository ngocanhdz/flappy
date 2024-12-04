#ifndef GAME_H
#define GAME_H

#include <QWidget>

class Game : public QWidget {
    Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);
    void startGame();
    void stopGame();
    void resetGame();

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    int score;
    bool isPlaying;
};

#endif // GAME_H
