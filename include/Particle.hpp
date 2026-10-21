//Particle class header file

#include "eigen-5.0.1/eigen-5.0.1/Eigen/Dense"
#include <iostream>
#ifndef __Particle_hpp__
#define __Particle_hpp__

class Particle 
{
private:
  // Nothing private here so far, right?

public:
  //Member variables
  double q_, m_;
  Eigen::Vector3d r_, v_;

  // Constructor
  Particle(double q, double m, Eigen::Vector3d r, Eigen::Vector3d v);

  // Reality check for unit testing: print out stored variables
  void return_variables();
};

#endif
