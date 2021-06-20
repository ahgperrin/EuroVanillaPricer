//
//  PricerBlackScholes.cpp
//  EuroVanillaPricer
//
//  Created by Antoine Perrin on 6/20/21.
//

#include <stdio.h>
#include "PricerBlackScholes.h"
#include "AssetObject.h"
#include "OptionObject.h"
#include <cmath>
#include "NormalDistribution.h"

double moneyness(Option option, Asset asset){
    //Param : Option Object, Aset Object
    //Return : Option Moneyness
    return asset.currentPrice()  / option.strike();
    
};
double volTerm(Option option, Asset asset){
    //Param : Option Object, Aset Object
    //Return : volatility term
    return asset.volatility()*sqrt(option.timeMaturity());
};

double driftTerm(Option option, Asset asset){
    //Param : Option Object, Aset Object, Risk Free Rate
    //Return : drift term
    return (asset.riskFreeRate() +(pow( asset.volatility(),2.00)/2))*option.timeMaturity();
};

double prodD1(Option option, Asset asset){
    //Param : Option Object, Aset Object, Risk Free Rate
    //Return : D1 (cf : Black and Scholes Model)
    return (log(moneyness(option,asset)) + driftTerm(option, asset)) / volTerm( option, asset);
};

double probD2(Option option, Asset asset){
    //Param : Option Object, Aset Object, Risk Free Rate
    //Return : D2 (cf : Black and Scholes Model)
    return prodD1( option,  asset) - volTerm(option, asset);
}

double discountFactor(Option option, Asset asset){
    //Param : Option Object, Risk Free Rate
    //Method : Continuous Time
    //Return : B(0,T), discount factor of 1 euro in T beginning t=0
    return exp(-asset.riskFreeRate()*option.timeMaturity());
}

double optionPrice(Option option, Asset asset){
    NormalDist N;
    
    double spot_part;
    double strike_part;
    
    if (option.type()=="c") {
        //Compute Call Price
        spot_part = asset.currentPrice() * N.cdf(prodD1(option,asset));
        strike_part = option.strike() * N.cdf(probD2(option,asset)) *discountFactor(option, asset);
        return spot_part - strike_part;
        
    }else if (option.type()=="p"){
        //Compute Put Price
        spot_part = asset.currentPrice() * N.cdf(-prodD1(option,asset));
        strike_part = option.strike() * N.cdf(-probD2(option,asset)) *discountFactor(option, asset);
        return strike_part - spot_part;
    }else{
        std::cout<<"Unkown Option Type/ Must be c or p"<<std::endl;
        return 0;
    }
    
}
