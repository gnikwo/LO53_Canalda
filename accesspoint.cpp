#include "accesspoint.h"

#include <math.h>

AccessPoint::AccessPoint(Position pos, double power, double gain, long int frequency): m_pos(pos), m_gain(gain), m_frequency(frequency) {
    m_power = log10(power)*10 + 30;
}

AccessPoint::AccessPoint(const AccessPoint& c) {
    this->m_pos = c.m_pos;
    this->m_power = c.m_power;
    this->m_gain = c.m_gain;
    this->m_frequency = c.m_frequency;
}

AccessPoint::~AccessPoint() {
}

AccessPoint& AccessPoint::operator=(const AccessPoint& c) {
    this->m_pos = c.m_pos;
    this->m_power = c.m_power;
    this->m_gain = c.m_gain;
    this->m_frequency = c.m_frequency;
    return *this;
}
