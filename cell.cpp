#include "cell.h"

using std::vector;

Cell::Cell(Position pos, vector<double> rssi_vector, double distance): m_pos(pos), m_rssi_vector(rssi_vector), m_distance(distance) {}

Cell::Cell(const Cell& c) {
    this->m_pos = c.m_pos;
    this->m_rssi_vector = c.m_rssi_vector;
    this->m_distance = c.m_distance;
}

Cell::~Cell() {
}

Cell& Cell::operator=(const Cell& c) {
    this->m_pos = c.m_pos;
    this->m_rssi_vector = c.m_rssi_vector;
    this->m_distance = c.m_distance;
    return *this;
}
