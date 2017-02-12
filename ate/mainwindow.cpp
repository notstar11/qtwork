#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "food.h"
#include "snake.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    scene(new QGraphicsScene(this)),
    view(new QGraphicsView(scene,this)),
    game(new GameController(*scene,this))
{
    setCentralWidget(view);
    resize(600,600);
    initScene();
    initSceneBackground();
    QTimer::singleShot(0,this,SLOT(adjustViewSize()));
}
void MainWindow::initScene()
{
    scene->setSceneRect(-100,-100,200,200);
}
void MainWindow::initSceneBackground()
{
    QPixmap bg(TILE_SIZE,TILE_SIZE);
    QPainter p(&bg);
    p.setBrush(QBrush(Qt::gray));
    p.drawRect(0,0,TILE_SIZE,TILE_SIZE);
    view->setBackgroudBrush(QBrush(bg));
}

MainWindow::~MainWindow()
{

}
GameController::GameController(QGraphicsScene *scene, QObject *parent):
    QObject(parent),
    scene(scene),
    snake(new Snake(this))
{
    timer.start(1000/33);
    Food *a1=new Food(0,-50);
    scene->addItem(a1);
    scene->addItem(snake);
    scene->installEventFilter(this);
    resume();
}
void GameController::pause()
{
    disconnect(&timer,SIGNAL(timeout()),scene,SLOT(advance()));
}
void GameController::resume()
{
    connect(&timer,SIGNAL(timeout()),scene,SLOT(advance()));
}
void GameController::handleKeyPressed(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Left:
        snake->setMoveDirection(Snake::MoveLeft);
        break;
    case Qt::Key_Right:
        snake->setMoveDirection(Snake::MoveRight);
        break;
    case Qt::Key_Up:
        snake->setMoveDirection(Snake::MoveUp);
        break;
    case Qt::Key_Down:
        snake->setMoveDirection(Snake::MoveDown);
        break;
    }
}

void GameController::eventFilter(QObject *object, QEvent *event)
{
    if(event->type()==QEvent::KeyPress){
        handleKeyPressed((QKeyEvent *)event);
        return true;
    }else{
        return QObject::eventFilter(object,event);
    }
}
void GameController::snakeAteFood(Snake *snake, Food *food)
{
    scene.removeItem(food);
    delete food;
    addNewFood();
}
void GameController::addNewFood()
{
    int x,y;
    do{
        x=(int)(qrand()%100)/10;
        y=(int)(qrand()%100)/10;
        x*=10;
        y*=10;
    }while(snake->shape().contrains(snake->mapFromScene(QPointF(x+5,y+5))));
    Food *food=new Food(x,y);
    scene.aaddItem(food);
}
void GameController::snakeAteItself(Snake *snake)
{
    QTimer::singleShot(0,this,SLOT(gameOver()));
}
void GameController::gameOver()
{
    scene.clear();
    snake=new Snake(*this);
    scene.addItem(snake);
    addNewFood();
}
























