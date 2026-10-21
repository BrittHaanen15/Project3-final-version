//Unit test for the Particle class that I created

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

int main()
{
    //Set charge and mass as for Ca+
    double my_charge = 1;
    double my_mass = 40.08;

    //Set position and velocity arbitrarily for now
    Eigen::Vector3d my_position = Eigen::Vector3d(1, -1, 2);
    Eigen::Vector3d my_velocity = Eigen::Vector3d(2, 3, 4);

    //Initialise particle using my class
    Particle my_particle = Particle(my_charge, my_mass, my_position, my_velocity);

    //Print assigned values to see that all works as it should
    my_particle.return_variables();

    return 0;
}