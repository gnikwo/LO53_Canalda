#pragma once

#include "solver.h"
#include "accesspoint.h"

class NlaterationSolver: public Solver {
    private:
        std::vector<AccessPoint*> m_dataset;

    public:
        NlaterationSolver(std::vector<AccessPoint*> dataset);
        ~NlaterationSolver();

        virtual Position solve(std::vector<double> sample_rssi_vector);

    private:
        std::vector<double> getDistances(std::vector<double> sample_rssi_vector);
        std::vector<double> getBoundingBox();
};
