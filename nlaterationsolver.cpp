#include "nlaterationsolver.h"

#include <numeric>
#include <algorithm>
#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

using std::vector;

NlaterationSolver::NlaterationSolver(std::vector<AccessPoint*> dataset): Solver(), m_dataset(dataset) {
}


NlaterationSolver::~NlaterationSolver() {
}


Position NlaterationSolver::solve(vector<double> sample_rssi_vector) {
    auto bbox = getBoundingBox();
    double x_min = bbox[0];
    double x_max = bbox[1];
    double y_min = bbox[2];
    double y_max = bbox[3];
    double z_min = bbox[4];
    double z_max = bbox[5];
    double distance_min = 99999;
    Position pos;
    auto distances = getDistances(sample_rssi_vector);
    for(double x = x_min; x < x_max; x += 0.1) {
        for(double y = y_min; y < y_max; y += 0.1) {
            for(double z = z_min; z < z_max; z += 0.1) {
                auto distance = distances.begin();
                double distance_sum = 0; 
                Position point(x, y, z);
                for(auto accesspoint: m_dataset) {
                    distance_sum += abs(accesspoint->getPosition().distance(point) - *distance);
                    distance++;
                }
                if(distance_sum < distance_min) {
                    distance_min = distance_sum;
                    pos = point;
                }
            }
        }
    }
    return pos;
}


vector<double> NlaterationSolver::getDistances(vector<double> sample_rssi_vector) {
    vector<double> distances;
    auto sample_rssi = sample_rssi_vector.begin();
    for(auto accesspoint: m_dataset) {
        double lambda = 3 * pow(10,8) / accesspoint->getFrequency();
        double gain = 2;
        double FSPL = accesspoint->getPower() + accesspoint->getGain() + gain - ((*sample_rssi) + 30);
        distances.push_back(pow(10, FSPL/20) * lambda/(4*M_PI));
        sample_rssi++;
    }
    return distances;
}


vector<double> NlaterationSolver::getBoundingBox() {
    double x_min = 999999;
    double x_max = -999999;
    double y_min = 999999;
    double y_max = -999999;
    double z_min = 999999;
    double z_max = -999999;
    for(auto accesspoint: m_dataset) {
        Position pos = accesspoint->getPosition();
        if(pos.getX() < x_min)
            x_min = pos.getX();
        if(pos.getX() > x_max)
            x_max = pos.getX();
        if(pos.getY() < y_min)
            y_min = pos.getY();
        if(pos.getY() > y_max)
            y_max = pos.getY();
        if(pos.getZ() < z_min)
            z_min = pos.getZ();
        if(pos.getZ() > z_max)
            z_max = pos.getZ();
    }
    return {x_min, x_max, y_min, y_max, z_min, z_max};
}
