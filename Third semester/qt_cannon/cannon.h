#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsRectItem>
#include <QtWidgets/QSpinBox>

/// Cannon class
class Cannon : public QObject
{
	Q_OBJECT

public slots:
	/// Method which is needed to set angle of cannon
	void setAngle(int angle);

	/// Method which is needed to set cannonball launch speed
	void setSpeed(int speed);

	/// Function which returns angle of cannon
	int getAngle();

	/// Function which returns cannonball launch speed
	int getSpeed();

	/// Function which returns cannon width
	qreal getWidth();

	/// Function which returns cannon height
	qreal getHeight();

public:
	/// Destructor
	~Cannon();

	///Constructor
	Cannon(QGraphicsScene *currentScene,
			QSpinBox *angleChanger,
			QSpinBox *speedChanger,
			qreal width,
			qreal height,
			qreal xCoordinate,
			qreal yCoordinate);

	explicit Cannon(QObject *parent = 0);

private:
	/// Body of a cannon
	QGraphicsRectItem *mBody;

	/// Base of cannon
	QGraphicsEllipseItem *mBase;

	/// Cannonball speed regulator
	QSpinBox *mSpeedSpinBox;

	/// Cannon angle regulator
	QSpinBox *mAngleSpinBox;

	/// X coordinate of cannon body
	qreal mXCoordinate;

	/// Y coordinate of cannon body
	qreal mYCoordinate;

	/// Width of cannon body
	qreal mWidth;

	/// Height of cannon body
	qreal mHeight;

	/// Angle of cannon body
	qreal mAngle;

	/// Speed of cannonball launch
	qreal mSpeed;


};
