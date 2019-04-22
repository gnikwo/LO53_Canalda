#pragma once

#include <vector>

#include "data.h"
#include "position.h"

class Solver {
    public:
        Solver();
        ~Solver();

        virtual Position solve(std::vector<double>) = 0;
};
