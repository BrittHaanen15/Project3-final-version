#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <chrono>
#include <random>
#include "utils.hpp"
#include "../include/eigen-5.0.1/eigen-5.0.1/Eigen/Dense"
#include "../include/eigen-5.0.1/eigen-5.0.1/Eigen/Eigenvalues"

#include "Particle.hpp"
#include "PenningTrap.hpp"

PenningTrap Init_large_trap(int particle_number, bool interactions, Eigen::Vector3d amplitude_and_frequency, std::mt19937 generator)
{
    //Set magnetic field, potential, and characteristic dimension
    double my_magfield = 9.65e1;
    double my_potential = 2.41e6;
    double my_d = 500;

    //Initialise Penning Trap using my class
    PenningTrap my_trap = PenningTrap(my_magfield, my_potential, my_d, interactions, amplitude_and_frequency);

    //Initialise particles to put in the trap
    double my_charge = 1;
    double my_mass = 40.08;

    //Loop for filling the trap
    ///Random code adapted from snippet provided at https://anderkve.github.io/FYS3150/book/projects/project3.html#
    std::normal_distribution<double> dist(0.0, 0.1 * my_d);

    for(int i=0; i<particle_number; i++)
    {
        Eigen::Vector3d my_position(dist(generator), dist(generator), dist(generator)); // random initial position
        Eigen::Vector3d my_velocity(dist(generator), dist(generator), dist(generator)); // random initial velocity

        //Generate particle and add to trap
            Particle my_particle = Particle(my_charge, my_mass, my_position, my_velocity);
            my_trap.add_particle(my_particle);  
    }
    ///end of random code snippet///////////////////////////////////////////////////////

    return my_trap;
}

void Full_RK4(PenningTrap& my_trap, double duration, int steps)
{   
    //Presets for simulation
    double timestep = duration/steps;
    double time = 0;

    //Run full RK4
    for(int i = 0; i <steps; i++)
    {   
        //Perform RK step
        my_trap.evolve_RK4(timestep, time);
        time += timestep;
        
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Make a vector according to start, stop, step
std::vector<double> make_a_range(double start, double stop, double step, bool verbose)
{
    //Calc number of steps based on start, stop and step size
    int stepsnumber = static_cast<int>((stop-start)/step);

    //Preall vector of this size
    std::vector<double> output(stepsnumber);

    for (int i = 0; i < stepsnumber; i++)
    {
        output[i] = start + i*step;
    }

    //Reality check: print generated vector if needed
    if (verbose == true)
    {
        for (const auto& element : output) 
        {
            std::cout << element << " ";
        }
        std::cout << "\n";
    }
    
   return output;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



