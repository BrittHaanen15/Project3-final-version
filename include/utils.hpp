//Make a vector according to start, stop, step
std::vector<double> make_a_range(double start, double stop, double step, bool verbose);

#include <random>
#include "eigen-5.0.1/eigen-5.0.1/Eigen/Dense"
#include "Particle.hpp"
#include "PenningTrap.hpp"
//Run a full RK4 sim for specified time and particle number
void Full_RK4(PenningTrap& my_trap, double duration, int steps);

//Initialise a large trap acc. to default parameters and wanted number of particles
PenningTrap Init_large_trap(int particle_number, bool interactions, Eigen::Vector3d amplitude_and_frequency, std::mt19937 generator);
