#ifndef TARGET_H
#define TARGET_H

class Target {
private:
    int id;
    double x;
    double y;
    double speed;
    double heading;

public:
    Target(
        int id,
        double x,
        double y,
        double speed,
        double heading
    );

    int getId() const;

    double getX() const;
    double getY() const;
    double getSpeed() const;
    double getHeading() const;

    void updatePosition(double seconds);
};

#endif