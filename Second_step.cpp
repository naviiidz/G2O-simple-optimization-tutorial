#include <iostream>
#include "g2o/core/factory.h"
#include "g2o/core/sparse_optimizer.h"
#include "g2o/core/optimization_algorithm_factory.h"
#include "g2o/stuff/command_args.h"

using namespace std;
using namespace g2o;

int main() {
SparseOptimizer optimizer; // creating an instance of the optimizer
optimizer.setVerbose(true);

// allocate the solver
g2o::OptimizationAlgorithmProperty solverProperty;
optimizer.setAlgorithm(
g2o::OptimizationAlgorithmFactory::instance()->construct("lm_var",
solverProperty));

}


