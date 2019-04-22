#pragma once

#include "position.h"

class AccessPoint {
    private:
        Position m_pos;
        double m_power;
        double m_gain;
        long int m_frequency;

    public:
        AccessPoint(Position pos, double power, double gain, long int frequency = 0);
        AccessPoint(const AccessPoint& c);
        ~AccessPoint();

        Position getPosition() {return m_pos;};

        double getPower() {return m_power;};
        
        double getGain() {return m_gain;};

        long int getFrequency() {return m_frequency;};
        void setFrequency(long int frequency) {m_frequency = frequency;};

        AccessPoint& operator=(const AccessPoint&);
};
