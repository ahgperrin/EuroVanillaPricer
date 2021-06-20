//
//  Greeks.cpp
//  EuroVanillaPricer
//
//  Created by Antoine Perrin on 6/20/21.
//

#include <stdio.h>
#include "OptionObject.h"
#include "AssetObject.h"
#include "PricerBlackScholes.h"
#include "NormalDistribution.h"
#include "Greeks.h"
NormalDist N;

double delta( Option option,Asset asset){
    //Compute Delta
    if (option.type()=="c") {
        return discountFactor( option, asset) * N.cdf(prodD1(option,asset));
        
    }else if (option.type()=="p"){
        return discountFactor( option, asset) * N.cdf(prodD1(option,asset)) - 1;
        
    }else{
        std::cout<<"Unknown Option Type"<<std::endl;
        return 0.00;
    }
    
}

double gamma(Option option,Asset asset){
    //Compute Gamma
    return (discountFactor( option, asset) / (asset.currentPrice()* volTerm( option, asset))) * (1/sqrt(2*M_PI)) * exp(-pow(prodD1(option, asset),2)/2);
}

double vega(Option option,Asset asset){
    //Compute Vega
    return 0.01 * asset.currentPrice()*discountFactor(option, asset)*sqrt(option.timeMaturity())*(1/sqrt(2*M_PI))* exp(-pow(prodD1(option, asset),2)/2);
}

double rho(Option option,Asset asset){
    //Compute Rho
    if (option.type()=="c") {
        return 0.01 * discountFactor(option, asset)*option.timeMaturity()*option.strike() * N.cdf(probD2(option, asset));
        
    }else if (option.type()=="p"){
        return -0.01 * discountFactor(option, asset)*option.timeMaturity()*option.strike() * N.cdf(-probD2(option, asset));
        
    }else{
        std::cout<<"Unknown Option Type"<<std::endl;
        return 0.00;
    }
}

double theta(Option option,Asset asset){
    //Compute Theta
    
    double term_1 = ((asset.currentPrice()*asset.volatility()*discountFactor(option, asset))/(2* sqrt(option.timeMaturity()))) * (1/sqrt(2*M_PI)) * exp(-pow(prodD1(option, asset),2)/2);
    double term_2 = asset.riskFreeRate() * option.strike() * discountFactor( option, asset);
    double term_3 = asset.riskFreeRate() * asset.currentPrice()*discountFactor(option, asset);
    
    if (option.type()=="c") {
        return (1.00/option.basis()) * -(term_1 - term_2* N.cdf(probD2(option, asset)) + term_3* N.cdf(prodD1(option, asset)));
        
    }else if (option.type()=="p"){
        return (1.00/option.basis()) * -(term_1 + term_2* N.cdf(-probD2(option, asset)) - term_3* N.cdf(-prodD1(option, asset)));
        
    }else{
        std::cout<<"Unknown Option Type"<<std::endl;
        return 0.00;
    }}
