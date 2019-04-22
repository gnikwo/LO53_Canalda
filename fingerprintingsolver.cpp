#include "fingerprintingsolver.h"

#include <numeric>
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;

using std::vector;

FingerprintingSolver::FingerprintingSolver(std::vector<Cell*> dataset): Solver(), m_dataset(dataset) {
}


FingerprintingSolver::~FingerprintingSolver() {
}


Position FingerprintingSolver::solve(vector<double> sample_rssi_vector) {
    auto nearests = kNearests(4, sample_rssi_vector);
    double d1 = nearests[0]->getDistance();
    double d2 = nearests[1]->getDistance();
    double d3 = nearests[2]->getDistance();
    double d4 = nearests[3]->getDistance();
    double alpha = 1/(  1   + d1/d2 + d1/d3 + d1/d4);
    double beta  = 1/(d2/d1 +   1   + d2/d3 + d2/d4);
    double delta = 1/(d3/d1 + d3/d2 +   1   + d3/d4);
    double gamma = 1/(d4/d1 + d4/d2 + d4/d3 +   1  );
    return alpha * nearests[0]->getPosition() + beta * nearests[1]->getPosition() + delta * nearests[2]->getPosition() + gamma * nearests[3]->getPosition();
}


vector<Cell*> FingerprintingSolver::kNearests(int k, vector<double> sample_rssi_vector) {
    for(auto cell: m_dataset) {
        vector<double> rssi_vector = cell->getRSSIVector();
        auto sample_rssi = sample_rssi_vector.begin();
        double distance = std::accumulate(rssi_vector.begin(), rssi_vector.end(), 0, [&sample_rssi](double total, auto& rssi) {
            total += abs(rssi - *sample_rssi);
            sample_rssi++;
            return total;
        });
        cell->setDistance(distance);
    }
    sort(m_dataset.begin(), m_dataset.end(), [](auto a, auto b) {
        return a->getDistance() > b->getDistance();
    });
    return vector<Cell*>(m_dataset.begin(), m_dataset.begin()+k);
}
