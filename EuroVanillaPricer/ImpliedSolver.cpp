//
//  ImpliedSolver.cpp
//  EuroVanillaPricer
//
//  Created by Antoine Perrin on 6/20/21.
//

#include <stdio.h>
#include "ImpliedSolver.h"
#include "PricerBlackScholes.h"
#include "AssetObject.h"
#include "OptionObject.h"

double vanilla_implied_volatility(Option option,Asset asset){
    // Solve implied Volatility By dichotomie
    double a = 0;
    double b = 2;
    double err_margin = 0.000000000000001;
    double implied_vol = 0;
    double error;
    double current_vol = asset.get_volatility();
    error = (b-a)/2;
    
    while (error > err_margin) {
        implied_vol = (a + b) / 2;
        asset.set_volatility(implied_vol);
        if (option_price(option,asset)<option.get_market_quote()) {
            a = implied_vol;
        }else{
            b = implied_vol;
        }
        error = (b - a) / 2;
    }
    
    asset.set_volatility(current_vol);
    return implied_vol;
}
