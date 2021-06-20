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

double vanillaImpliedVolatility(Option option,Asset asset){
    // Solve implied Volatility By dichotomie
    double a = 0;
    double b = 2;
    double errMargin = 0.000000000000001;
    double impliedVol = 0;
    double error;
    double currentVol = asset.volatility();
    error = (b-a)/2;
    
    while (error > errMargin) {
        
        impliedVol = (a + b) / 2;
        asset.setVolatility(impliedVol);
        
        if (optionPrice(option,asset)<option.marketQuote()) {
            a = impliedVol;
            
        }else{
            b = impliedVol;
        }
        error = (b - a) / 2;
    }
    
    asset.setVolatility(currentVol);
    return impliedVol;
}
