//Unit test for the penning trap class functions
//Initialisation of penning trap verified in UnitTest_PenningTrapClass
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

    //Calculate external electric field for this particle at arbitrary location
    Eigen::Vector3d my_loc(2, 4, 6);
    Eigen::Vector3d result = my_trap.external_E_field(my_loc);
    
    //print result
    std::cout << "external E: " << std::endl;
    std::cout << result << std::endl;

    //Calculate external electric field for this particle at arbitrary location
    Eigen::Vector3d result_B1 = my_trap.external_B_field(my_loc);
    //print result
    std::cout << "external B, location 1: " << std::endl;
    std::cout << result_B1 << std::endl;

    //Try at another location, should always be the same
    //Calculate external electric field for this particle at arbitrary location
    Eigen::Vector3d my_loc_two(-2, 5, -4);
    Eigen::Vector3d result_B2 = my_trap.external_B_field(my_loc_two);
    
    //print result
    std::cout << "external B, location 2: " << std::endl;
    std::cout << result_B2 << std::endl;

    //Initialise particles to put in the trap/////////////////////////
    //Code as tested in UnitTest_ParticleClass//////////////////////
    double my_charge = 1;
    double my_mass = 40.08;
    Eigen::Vector3d my_position_two = Eigen::Vector3d(1, 2, 3);
    Eigen::Vector3d my_velocity = Eigen::Vector3d(2, 3, 4);

    Particle my_particle_one = Particle(my_charge, my_mass, my_loc, my_velocity);
    Particle my_particle_two = Particle(2*my_charge, my_mass,my_position_two, my_velocity);

    //Add particles
    my_trap.add_particle(my_particle_one);
    my_trap.add_particle(my_particle_two);
    /////////////////////////////////////////////////////////////////

    //Calculate force that particle 0 experiences from particle 1
    Eigen::Vector3d C_force = my_trap.force_particle(0, 1);

    //Print result
    std::cout << "C force on particle 0 from particle 1" << std::endl;
    std::cout << C_force << std::endl; 
    
    //Calculate total force that particle 0 experiences from external field
    Eigen::Vector3d ext_force_p0 = my_trap.total_force_external(0);
    std::cout << "Total external force on particle 0" << std::endl;
    std::cout << ext_force_p0 << std::endl;

    //Calculate total force that particle 0 experiences from other particles
    //Should match outcome for "C force on particle 0 from particle 1"
    std::cout << "Total other particle forces on particle 0" << std::endl;
    std::cout << my_trap.total_force_particles(0) << std::endl;

    //Calculate total force that particle 0 experiences
    //Should be the sum of the two previous ones
    std::cout << "Total force on particle 0" << std::endl;
    std::cout << my_trap.total_force(0) << std::endl;

    return 0;
}
