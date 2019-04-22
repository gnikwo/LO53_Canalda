#pragma once

#include <vector>

#include "position.h"

class Solver {
    public:
        Solver();
        ~Solver();

        virtual Position solve(std::vector<double>) = 0;
};
