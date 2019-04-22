#pragma once

#include "solver.h"
#include "cell.h"

class FingerprintingSolver: public Solver {
    private:
        std::vector<Cell*> m_dataset;

    public:
        FingerprintingSolver(std::vector<Cell*> dataset);
        ~FingerprintingSolver();

        virtual Position solve(std::vector<double> sample_rssi_vector);

    private:
        std::vector<Cell*> kNearests(int k, std::vector<double> sample_rssi_vector);
};
