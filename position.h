#pragma once

#include <iostream>

class Position {
    private:
        double m_x, m_y, m_z;

    public:
        Position(double x = 0, double y = 0, double z = 0);
        ~Position();

        double getX() {return m_x;};
        void setX(double x) {m_x = x;};

        double getY() {return m_y;};
        void setY(double y) {m_y = y;};

        double getZ() {return m_z;};
        void setZ(double z) {m_z = z;};
        
        double length();

        double distance(Position& p);

        Position operator+(Position a);
        Position operator-(Position a);

        friend Position operator*(double a, Position);
        friend std::ostream& operator<< (std::ostream &out, const Position &pos);
};
