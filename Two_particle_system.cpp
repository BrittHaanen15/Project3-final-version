//One or two particle system

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
    //Declare outputs at top of file, for simple running of my simulations
    int n = 32000;
    std::string filename = "./Project3_Outputs/twoparticles_n32000_RK4_nointeractions.csv";
    double total_time = 50; //micro seconds

    //Set magnetic field, potential, and characteristic dimension
    double my_magfield = 9.65e1;
    double my_potential = 2.41e6;
    double my_d = 500;

    //Initialise Penning Trap using my class
    PenningTrap my_trap = PenningTrap(my_magfield, my_potential, my_d, false);

    //Initialise particles to put in the trap
    //Initialise particles as for previous tests, since I already calculated the forces
    double my_charge = 1;
    double my_mass = 40.08;
    
    //Particle 1
    Eigen::Vector3d my_position_one = Eigen::Vector3d(20,0,20);
    Eigen::Vector3d my_velocity_one = Eigen::Vector3d(0,25,0);;
    Particle my_particle_one = Particle(my_charge, my_mass, my_position_one, my_velocity_one);
    my_trap.add_particle(my_particle_one);

    //Particle 2 //////////////////////////////////////////////////////////////////////////////////
    //Comment in/out this code section to make it a one or two particle system
    Eigen::Vector3d my_position_two = Eigen::Vector3d(25,25,0);
    Eigen::Vector3d my_velocity_two = Eigen::Vector3d(0,40,5);;
    Particle my_particle_two = Particle(my_charge, my_mass, my_position_two, my_velocity_two);
    my_trap.add_particle(my_particle_two);
    ///////////////////////////////////////////////////////////////////////////////////////////////

    //Presets for simulation
    double timestep = total_time/n;
    double time = 0;

    //Initialise file for writing out the data
    my_trap.write_particles_to_file(filename, time, true);

    for(int i = 0; i <n; i++)
    {   
        //Perform RK step
        my_trap.evolve_RK4(timestep);
        time += timestep;

        //Write locations to file
        my_trap.write_particles_to_file(filename, time);
        
    }

    return 0;
}
