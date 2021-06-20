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
    return (discount_factor( option, asset) / (asset.get_current_price()* vol_term( option, asset))) * (1/sqrt(2*M_PI)) * exp(-pow(d_1(option, asset),2)/2);
}

double vega(Asset asset, Option option){
    return 0.00;
}

double rho(Asset asset, Option option){
    return 0.00;
}

double theta(Asset asset, Option option){
    return 0.00;
}
