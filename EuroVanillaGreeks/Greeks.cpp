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
    if (option.get_type()=="c") {
        return discount_factor( option, asset) * N.get_cdf(d_1(option,asset));
        
    }else if (option.get_type()=="p"){
        return discount_factor( option, asset) * N.get_cdf(d_1(option,asset)) - 1;
        
    }else{
        std::cout<<"Unknown Option Type"<<std::endl;
        return 0.00;
    }
    
}

double gamma(Option option,Asset asset){
    //Compute Gamma
    return (discount_factor( option, asset) / (asset.get_current_price()* vol_term( option, asset))) * (1/sqrt(2*M_PI)) * exp(-pow(d_1(option, asset),2)/2);
}

double vega(Option option,Asset asset){
    //Compute Vega
    return 0.01 * asset.get_current_price()*discount_factor(option, asset)*sqrt(option.get_time_maturity())*(1/sqrt(2*M_PI))* exp(-pow(d_1(option, asset),2)/2);
}

double rho(Option option,Asset asset){
    //Compute Rho
    if (option.get_type()=="c") {
        return 0.01 * discount_factor(option, asset)*option.get_time_maturity()*option.get_strike() * N.get_cdf(d_2(option, asset));
        
    }else if (option.get_type()=="p"){
        return -0.01 * discount_factor(option, asset)*option.get_time_maturity()*option.get_strike() * N.get_cdf(-d_2(option, asset));
        
    }else{
        std::cout<<"Unknown Option Type"<<std::endl;
        return 0.00;
    }
}

double theta(Option option,Asset asset){
    //Compute Theta
    
    double term_1 = ((asset.get_current_price()*asset.get_volatility()*discount_factor(option, asset))/(2* sqrt(option.get_time_maturity()))) * (1/sqrt(2*M_PI)) * exp(-pow(d_1(option, asset),2)/2);
    double term_2 = asset.get_risk_free_rate() * option.get_strike() * discount_factor( option, asset);
    double term_3 = asset.get_risk_free_rate() * asset.get_current_price()*discount_factor(option, asset);
    
    if (option.get_type()=="c") {
        return (1.00/option.get_basis()) * -(term_1 - term_2* N.get_cdf(d_2(option, asset)) + term_3* N.get_cdf(d_1(option, asset)));
        
    }else if (option.get_type()=="p"){
        return (1.00/option.get_basis()) * -(term_1 + term_2* N.get_cdf(-d_2(option, asset)) - term_3* N.get_cdf(-d_1(option, asset)));
        
    }else{
        std::cout<<"Unknown Option Type"<<std::endl;
        return 0.00;
    }}
