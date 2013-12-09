#include "cannon.h"
#include <QtMath>

Cannon::Cannon(QObject *parent) :
	QObject(parent)
{
}

Cannon::Cannon(QGraphicsScene *currentScene,
				QSpinBox *angleChanger,
				QSpinBox *speedChanger,
				qreal width,
				qreal height,
				qreal xCoordinate,
				qreal yCoordinate)
{
	qreal temp = sqrt(width * height);
	this->mBase = currentScene->addEllipse(QRectF(xCoordinate - temp / 2,
													yCoordinate - temp / 2,
													temp * 1.5,
													temp * 1.5));
	this->mBody = currentScene->addRect(xCoordinate,
										yCoordinate,
										height,
										width);
	this->mAngleSpinBox = angleChanger;
	this->mSpeedSpinBox = speedChanger;
	this->mAngle = 0;
	this->mSpeed = 0;
	this->mWidth = width;
	this->mHeight = height;

	connect(angleChanger,
			SIGNAL(valueChanged(int)),
			this,
			SLOT(setAngle(int)));
	connect(speedChanger,
			SIGNAL(valueChanged(int)),
			this,
			SLOT(setSpeed(int)));
}

void Cannon::setAngle(int angle)
{
	QTransform transform;
	transform.rotate(- angle);
	this->mBody->setTransform(transform);
	this->mAngle = angle;
}

void Cannon::setSpeed(int speed)
{
	this->mSpeed = speed;
}

int Cannon::getAngle()
{
	return this->mAngle;
}

int Cannon::getSpeed()
{
	return this->mSpeed;
}

qreal Cannon::getHeight()
{
	return this->mHeight;
}

qreal Cannon::getWidth()
{
	return this->mWidth;
}

Cannon::~Cannon()
{
	delete this->mBody;
	delete this->mAngleSpinBox;
	delete this->mSpeedSpinBox;
}

