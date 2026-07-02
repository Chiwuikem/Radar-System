#include "../include/Target.h"

#include <cmath>

Target::Target(
    int id,
    double x,
    double y,
    double speed,
    double heading
)
{
    this->id = id;
    this->x = x;
    this->y = y;
    this->speed = speed;
    this->heading = heading;
}

int Target::getId() const
{
    return id;
}

double Target::getX() const
{
    return x;
}

double Target::getY() const
{
    return y;
}

double Target::getSpeed() const
{
    return speed;
}

double Target::getHeading() const
{
    return heading;
}

void Target::updatePosition(double seconds)
{
    double radians = heading * M_PI / 180.0;

    x += speed * cos(radians) * seconds;
    y += speed * sin(radians) * seconds;
}