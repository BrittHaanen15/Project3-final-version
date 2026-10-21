//Unit test for forward euler step
//Using particle and penning trap classes as verified in previous Unit Test files

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <chrono>
#include <algorithm>
#include "utils.hpp"
#include "eigen-5.0.1/eigen-5.0.1/Eigen/Dense"
#include "eigen-5.0.1/eigen-5.0.1/Eigen/Eigenvalues"

#include "Particle.hpp"
#include "PenningTrap.hpp"

int main()
{
    //Set magnetic field, potential, and characteristic dimension
    double my_magfield = 9.65e1;
    double my_potential = 2.41e6;
    double my_d = 500;

    //Initialise Penning Trap using my class
    PenningTrap my_trap = PenningTrap(my_magfield, my_potential, my_d);

    //Initialise particles to put in the trap/////////////////////////
    //Code as tested in UnitTest_ParticleClass//////////////////////
    //Initialise particles as for previous tests, since I already calculated the forces
    double my_charge = 1;
    double my_mass = 40.08;
    
    //Particle 1
    Eigen::Vector3d my_position_one = Eigen::Vector3d(2,4,6);
    Eigen::Vector3d my_velocity_one = Eigen::Vector3d(2, 3, 4);;
    Particle my_particle_one = Particle(my_charge, my_mass, my_position_one, my_velocity_one);
    my_trap.add_particle(my_particle_one);

    //Particle 2
    Eigen::Vector3d my_position_two = Eigen::Vector3d(1,2,3);
    Eigen::Vector3d my_velocity_two = Eigen::Vector3d(2, 3, 4);;
    Particle my_particle_two = Particle(2*my_charge, my_mass, my_position_two, my_velocity_two);
    my_trap.add_particle(my_particle_two);
    /////////////////////////////////////////////////////////////////

    std::cout << "Before Euler step" << std::endl;
    my_trap.return_variables();

    //See if it runs
    my_trap.evolve_forward_Euler(0.01);

    std::cout << "After Euler step" << std::endl;
    my_trap.return_variables();

    return 0;
}
