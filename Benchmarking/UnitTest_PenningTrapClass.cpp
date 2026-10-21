//Unit test for penning trap class

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

    //Print assigned values to see that all works as it should
    //Expect only set mag/pot/d now, no particles
    my_trap.return_variables();

    //Initialise particle to put in the trap/////////////////////////
    //Code as tested in UnitTest_ParticleClass//////////////////////
    double my_charge = 1;
    double my_mass = 40.08;
    Eigen::Vector3d my_position = Eigen::Vector3d(1, -1, 2);
    Eigen::Vector3d my_velocity = Eigen::Vector3d(2, 3, 4);
    Particle my_particle = Particle(my_charge, my_mass, my_position, my_velocity);
    /////////////////////////////////////////////////////////////////

    //Add particle
    my_trap.add_particle(my_particle);
    //print, now expect 1 particle in trap
    my_trap.return_variables();

    //Let's add another particle for testing!
    Particle my_particle_two = Particle(2*my_charge, 2*my_mass, 2*my_position, 2*my_velocity);
    my_trap.add_particle(my_particle_two);
    //print, now expect 2 particles in trap
    my_trap.return_variables();

    return 0;
}
