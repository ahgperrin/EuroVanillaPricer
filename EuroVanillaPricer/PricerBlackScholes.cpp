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
    return asset.get_current_price()  / option.get_strike();
    
};
double vol_term(Option option, Asset asset){
    //Param : Option Object, Aset Object
    //Return : volatility term
    return asset.get_volatility()*sqrt(option.get_time_maturity());
};

double drift_term(Option option, Asset asset,double risk_free_rate){
    //Param : Option Object, Aset Object, Risk Free Rate
    //Return : drift term
    return (risk_free_rate +(pow( asset.get_volatility(),2.00)/2))*option.get_time_maturity();
};

double d_1(Option option, Asset asset,double risk_free_rate){
    //Param : Option Object, Aset Object, Risk Free Rate
    //Return : D1 (cf : Black and Scholes Model)
    return (log(moneyness(option,asset)) + drift_term(option, asset, risk_free_rate)) / vol_term( option, asset);
};

double d_2(Option option, Asset asset,double risk_free_rate){
    //Param : Option Object, Aset Object, Risk Free Rate
    //Return : D2 (cf : Black and Scholes Model)
    return d_1( option,  asset, risk_free_rate) - vol_term(option, asset);
}

double discount_factor(Option option,double risk_free_rate){
    //Param : Option Object, Risk Free Rate
    //Method : Continuous Time
    //Return : B(0,T), discount factor of 1 euro in T beginning t=0
    return exp(-risk_free_rate*option.get_time_maturity());
}

double option_price(Option option, Asset asset,double risk_free_rate){
    NormalDist N;
    
    double spot_part;
    double strike_part;
    
    if (option.get_type()=="c") {
        //Compute Call Price
        spot_part = asset.get_current_price() * N.get_cdf(d_1(option,asset,risk_free_rate));
        strike_part = option.get_strike() * N.get_cdf(d_2(option,asset,risk_free_rate)) *discount_factor(option, risk_free_rate);
        return spot_part - strike_part;
        
    }else if (option.get_type()=="p"){
        //Compute Put Price
        spot_part = asset.get_current_price() * N.get_cdf(-d_1(option,asset,risk_free_rate));
        strike_part = option.get_strike() * N.get_cdf(-d_2(option,asset,risk_free_rate)) *discount_factor(option, risk_free_rate);
        return strike_part - spot_part;
    }else{
        std::cout<<"Unkown Option Type/ Must be c or p"<<std::endl;
        return 0;
    }
    
}
