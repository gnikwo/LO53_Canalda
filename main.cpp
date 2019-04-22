#include <iostream>
#include <vector>
#include <memory>
#include <math.h>

#include "fingerprintingsolver.h"
#include "nlaterationsolver.h"
#include "cell.h"
#include "position.h"

using std::cout;
using std::endl;

Solver* factory(int i) {
    switch(i) {
        case 1:
            return new NlaterationSolver({
                new AccessPoint(Position(0.5, 0.5, 0), 200, 2, 5*pow(10,9)),
                new AccessPoint(Position(4, 0, 0), 200, 2, 5*pow(10,9)),
                new AccessPoint(Position(4, 5, 5), 200, 2, 5*pow(10,9)),
                new AccessPoint(Position(3, 3, 3), 200, 2, 5*pow(10,9))});
        case 2:
            return new FingerprintingSolver({
                new Cell(Position(2,2,0), {-38,-27,-54,-13}),
                new Cell(Position(2,6,0), {-74,-62,-48,-33}),
                new Cell(Position(2,10,0), {-13,-28,-12,-40}),
                new Cell(Position(6,2,0), {-34,-27,-38,-41}),
                new Cell(Position(6,6,0), {-64,-48,-72,-35}),
                new Cell(Position(6,10,0), {-45,-37,-20,-15}),
                new Cell(Position(10,2,0), {-17,-50,-44,-33}),
                new Cell(Position(10,6,0), {-27,-28,-32,-45}),
                new Cell(Position(10,10,0), {-30,-20,-60,-40})});
        default:
            cout << "Please select a scenario !" << endl;
            exit(1);
    }
}

int main(int argc, char** argv) {
    Position phone(2.5, 4, 3);
    Solver* s = factory(1);
    //cout << s->solve({-26, -42, -13, -46}) << endl;
    cout << s->solve({-33.43349, -33.76453, -28.01424, -20.37994}) << endl;
    return 0;
}
