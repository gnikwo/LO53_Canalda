#include "position.h"

#include <math.h>

Position::Position(double x, double y, double z): m_x(x), m_y(y), m_z(z) {
}

Position::~Position() {
}

Position Position::operator+(Position a) {
    return Position(this->m_x + a.m_x, this->m_y + a.m_y, this->m_z + a.m_z);
}

Position Position::operator-(Position a) {
    return Position(this->m_x - a.m_x, this->m_y - a.m_y, this->m_z - a.m_z);
}

double Position::length() {
    return sqrt(pow(m_x, 2) + pow(m_y, 2) + pow(m_z, 2));
}

double Position::distance(Position& p) {
    return (p - *this).length();
}

Position operator*(double a, Position pos) {
    return Position(pos.m_x * a, pos.m_y * a, pos.m_z * a);
}

std::ostream& operator<<(std::ostream &out, const Position &pos) {
    out << "(" << pos.m_x << ", " << pos.m_y << ", " << pos.m_z << ")";
    return out;
}
