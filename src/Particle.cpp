//Particle class source file
#include "Particle.hpp"
#include <iostream>

Particle::Particle(double q, double m, Eigen::Vector3d r, Eigen::Vector3d v)
{
    //Assign member variables from the given inputs
    q_ = q;
    m_ = m;
    r_ = r;
    v_ = v;
}

void Particle::return_variables()
{
    std::cout << "Charge: " << q_ << std::endl;
    std::cout << "Mass: " << m_ << std::endl;
    std::cout << "Position: " << r_ << std::endl;
    std::cout << "Velocity: " << v_ << std::endl;
}

