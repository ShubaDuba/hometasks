#pragma once

#include <QtCore/QTimer>
#include <QtCore/QObject>
#include <QtWidgets/QPushButton>
#include "cannon.h"

/// Cannonball class
class CannonBall : public QObject
{
	Q_OBJECT

public:
	/// Constructor
	CannonBall(Cannon *chosenCannon,
				QGraphicsScene *chosenScene,
				QPushButton *fireButton);

	/// Destructor
	~CannonBall();

	explicit CannonBall(QObject *parent = 0);

public slots:
	/// Method to calculate cannonball flight process
	void launch();

	/// Method to place cannonball in starting position
	void create();

private:
	/// Timer
	QTimer *mTimer;

	/// The cannonball's body
	QGraphicsEllipseItem *mBody;

	/// Scene on which the cannonball is
	QGraphicsScene *mScene;

	/// Cannon from which the cannonball flew
	Cannon *mCannon;

	/// X coordinate of the cannonball
	qreal mXCoordinate;

	/// Y coordinate of the cannonball
	qreal mYCoordinate;

	/// Auxiliary time valuable
	qreal mTime;
};
