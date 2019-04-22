#pragma once

#include <vector>

#include "position.h"

class Cell {
    private:
        Position m_pos;
        std::vector<double> m_rssi_vector;
        double m_distance;

    public:
        Cell(Position pos, std::vector<double> rssi_vector, double distance = 0);
        Cell(const Cell& c);
        ~Cell();

        Position getPosition() {return m_pos;};

        std::vector<double> getRSSIVector() {return m_rssi_vector;};

        double getDistance() {return m_distance;};
        void setDistance(double distance) {m_distance = distance;};

        Cell& operator=(const Cell&);
};
