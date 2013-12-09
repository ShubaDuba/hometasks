#pragma once

#include <QtWidgets/QMainWindow>
#include "cannon.h"
#include "cannonBall.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);

	///Destructor
	~MainWindow();

private:
	/// Cannon
	Cannon *mCannon;

	/// Scene
	QGraphicsScene *mScene;

	/// Cannonball
	CannonBall *mCannonball;

	Ui::MainWindow *mUi;
};
