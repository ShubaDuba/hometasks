#include "mainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	mUi(new Ui::MainWindow)
{
	mUi->setupUi(this);
	QGraphicsScene *mScene = new QGraphicsScene;
	mUi->graphicsView->setScene(mScene);
	mUi->graphicsView->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
	Cannon *mCannon = new Cannon(mScene,
								 mUi->angleSpinBox,
								 mUi->speedSpinBox,
								 20,
								 60,
								 0,
								 0);
	CannonBall *mCannonball = new CannonBall(mCannon,
											 mScene,
											 mUi->fireButton);
}

MainWindow::~MainWindow()
{
	delete mCannon;
	delete mCannonball;
	delete mScene;
	delete mUi;
}

