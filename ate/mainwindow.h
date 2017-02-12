#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>

class QGraphicsScene;
class QGraphicsView;
class GameController
{
    Q_OBJECT
public:
    GameController(QGraphicsScene *scene,QObject *parent);
    void pause();
    void resume();
    bool eventFilter(QObject *object,QEvent *event);
    void handleKeyPressed(QKeyEvent *event);
    void snakeAteFood(Snake *snake,Food *food);
    void addNewFood();
    void snakeAteItself(Snake *snake);
    void gameOver();
private:
    QTimer timer;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void adjustViewSize();

private:
    void initScene();
    void initSceneBackground();
    QGraphicsScene *scene;
    QGraphicsView *view;
    GameController *game;

};

#endif // MAINWINDOW_H
