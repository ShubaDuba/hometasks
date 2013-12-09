#include "cannonBall.h"
#include <QtMath>

const qreal TIMESTEP = 0.1;   // update interval
CannonBall::CannonBall(QObject *parent) :
	QObject(parent)
{
}

CannonBall::CannonBall(Cannon *chosenCannon,
					   QGraphicsScene *chosenScene,
					   QPushButton *fireButton)
{
	this->mScene = chosenScene;
	this->mCannon = chosenCannon;
	this->mBody = new QGraphicsEllipseItem();
	this->mTime = 0;
	this->mTimer = new QTimer();
	connect(fireButton
			, SIGNAL(clicked())
			, this
			, SLOT(create()));
	connect(this->mTimer
			, SIGNAL(timeout())
			, this
			, SLOT(launch()));
}

void CannonBall::launch()
{
	if (mYCoordinate >= 20)
	{
		mTimer->stop();
		mTime = 0;
		return;
	}

	mTime += TIMESTEP;
	const int G = 10;   // gravity constant
	int tmpSpeed = mCannon->getSpeed();
	qreal radTmpAngle = mCannon->getAngle() * M_PI / 180;
	this->mXCoordinate = (mXCoordinate + tmpSpeed * cos(radTmpAngle) * TIMESTEP);
	this->mYCoordinate = (mYCoordinate - tmpSpeed * sin(radTmpAngle) * TIMESTEP
						  + G * TIMESTEP * (2 * mTime - TIMESTEP) / 2);
	this->mBody->setX(mXCoordinate);
	this->mBody->setY(mYCoordinate);
}

void CannonBall::create()
{
	qreal radTmpAngle = this->mCannon->getAngle() * M_PI / 180;
	int tmpAngle = this->mCannon->getAngle();
	int tmpHeight = this->mCannon->getHeight();
	int tmpWidth = this->mCannon->getWidth();

	if (this->mTimer->isActive()) {
		return;
	}

	mTimer->start(TIMESTEP * 100);

	if (this->mBody != NULL)
	{
		delete(this->mBody);
	}

	this->mBody = new QGraphicsEllipseItem(0,
											0,
											tmpWidth,
											tmpWidth);
	this->mXCoordinate = cos(radTmpAngle) * tmpHeight;
	this->mYCoordinate = sin(radTmpAngle) * tmpHeight * (-1);
	this->mBody->setPos(this->mXCoordinate,
						this->mYCoordinate);
	this->mBody->setRotation(- tmpAngle);
	this->mScene->addItem(this->mBody);
}

CannonBall::~CannonBall()
{
	delete this->mBody;
	delete this->mScene;
	delete this->mCannon;
}

