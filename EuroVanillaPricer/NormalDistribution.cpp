//
//  NormalDistribution.cpp
//  EuroVanillaPricer
//
//  Created by Antoine Perrin on 6/20/21.
//

#include <stdio.h>
#include <iostream>
#include "NormalDistribution.h"

double NormalDist::get_cdf(double x){
    // Compute Cumulative normal distribution
    double k = 1.0/(1.0 + 0.2316419*x);
    double k_sum = k*(0.319381530 + k*(-0.356563782 + k*(1.781477937 + k*(-1.821255978 + 1.330274429*k))));
    if (x >= 0.0) {
        return (1.0 - (1.0/(pow(2*M_PI,0.5)))*exp(-0.5*x*x) * k_sum);
    } else {
        return 1.0 - get_cdf(-x);
    }

};

double NormalDist::get_pdf(double x){
    //Compute Non cumulative Normal distribution
    double pi = 4*atan(1.0);
    return exp(0.5*x*(-x))*sqrt(2*pi);
};
