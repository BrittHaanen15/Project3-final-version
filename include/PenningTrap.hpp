//Penning trap class header file

#include "Particle.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include "eigen-5.0.1/eigen-5.0.1/Eigen/Dense"
#include "eigen-5.0.1/eigen-5.0.1/Eigen/Eigenvalues"
#ifndef __PenningTrap_hpp__
#define __PenningTrap_hpp__

class PenningTrap 
{
private:
  // Nothing private here so far, right?

public:
  //Member variables: magnetic field mag, potential pot, characteristic dimension d, particles in trap particles
  double mag_, pot_, d_;
  std::vector<Particle> particles_;
  //Variable for turning particle interactions on or off
  bool particle_interactions_;
  ///amp and freq for time dep E
  Eigen::Vector3d amp_freq_;

  // Constructor
  PenningTrap(double B0_in, double V0_in, double d_in, bool particle_interactions = true, Eigen::Vector3d amp_freq = Eigen::Vector3d::Zero());

  // Add a particle to the trap
  void add_particle(Particle p_in);

  // Reality check for unit testing: print out stored variables
  void return_variables();

  //Writing out data
  void write_particles_to_file(const std::string& filename, double time, bool write_header = false);

  // External electric field at point r=(x,y,z)
  Eigen::Vector3d external_E_field(Eigen::Vector3d r, double tt);  

  // External magnetic field at point r=(x,y,z)
  Eigen::Vector3d external_B_field(Eigen::Vector3d r);  

  // Force on particle_i from particle_j
  Eigen::Vector3d force_particle(int i, int j);

  // The total force on particle_i from the external fields
  Eigen::Vector3d total_force_external(int i, double tt);

  // The total force on particle_i from the other particles
  Eigen::Vector3d total_force_particles(int i);

  // The total force on particle_i from both external fields and other particles
  Eigen::Vector3d total_force(int i, double tt);

  // Evolve the system one time step (dt) using Runge-Kutta 4th order
  void evolve_RK4(double dt, double tt);

  // Evolve the system one time step (dt) using Forward Euler
  void evolve_forward_Euler(double dt, double tt);

  //Count number of particles in the trap
  int count_particles();
};

#endif
