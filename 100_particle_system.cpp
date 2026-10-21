//One or two particle system

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <random>
#include "utils.hpp"
#include "eigen-5.0.1/eigen-5.0.1/Eigen/Dense"
#include "eigen-5.0.1/eigen-5.0.1/Eigen/Eigenvalues"

#include "Particle.hpp"
#include "PenningTrap.hpp"

int main()
{
    //Declare outputs at top of file, for simple running of my simulations
    double amplitude = 0.7;
    std::string filename = "./Project3_Outputs/100_particles_f0.7.csv";
    std::mt19937 generator;
    generator.seed(5);
    

    //Setting values we want to simulate
    std::vector<double> freqs = make_a_range(0.2, 2.54, 0.02, true);

    std::ofstream file(filename);
    file << "frequency,trapped\n";

    for(int i=0; i<static_cast<int>(freqs.size());i++)
    {   
        Eigen::Vector3d params(amplitude, freqs[i], 0);

        //Initialise new trap
        PenningTrap trap_this_round = Init_large_trap(100, false, params, generator);
        
        //Run RK4 on it
        Full_RK4(trap_this_round, 500, 40000);

        //print nr of particles in trap
        int number = trap_this_round.count_particles();
        std::cout << number << std::endl;
        //Save to file
        file << freqs[i] << ","
             << number << "\n";
    }

    return 0;
}

