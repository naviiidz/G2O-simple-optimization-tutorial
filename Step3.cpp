#include <iostream>
#include "g2o/core/factory.h"
#include "g2o/core/sparse_optimizer.h"
#include "g2o/core/optimization_algorithm_factory.h"
#include "g2o/stuff/command_args.h"

using namespace std;
using namespace g2o;

// Third change ***
// we use the 2D and 3D SLAM types here
G2O_USE_TYPE_GROUP(slam2d);
G2O_USE_TYPE_GROUP(slam3d);
G2O_USE_OPTIMIZATION_LIBRARY(eigen);
// ***

int main(int argc, char** argv) { //First change 


//Second change**
int maxIterations;
string outputFilename;
string inputFilename;
CommandArgs arg;
arg.param("iter", maxIterations, 10,
          "perform n iterations, if negative consider the gain");
arg.param("out", outputFilename, "", "output final version of the graph");
arg.param("in", inputFilename, "", "output final version of the graph");

arg.parseArgs(argc, argv);

cout<<maxIterations<<" is maximum iterations"<<endl;
cout<<outputFilename<<" is output file name"<<endl;
// **

  
SparseOptimizer optimizer; // creating an instance of the optimizer
optimizer.setVerbose(true);
// allocate the solver
g2o::OptimizationAlgorithmProperty solverProperty;
optimizer.setAlgorithm(
g2o::OptimizationAlgorithmFactory::instance()->construct("lm_var",
solverProperty));



// Fourth change ****
  ifstream ifs(inputFilename.c_str());
  if (!ifs) {
    cerr << "unable to open " << inputFilename << endl;
    return 1;
  }
  optimizer.load(ifs);
  optimizer.initializeOptimization();
  optimizer.optimize(maxIterations);

  if (outputFilename.size() > 0) {
    cout<<"hey"<<endl;
    if (outputFilename == "-") {
      cerr << "saving to stdout";
      optimizer.save(cout);
    } else {
      cerr << "saving " << outputFilename << " ... ";
      optimizer.save(outputFilename.c_str());
    }
    cerr << "done." << endl;
  }
// ****
}


