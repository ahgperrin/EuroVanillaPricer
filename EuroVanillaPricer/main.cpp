//
//  main.cpp
//  EuroVanillaPricer
//
//  Created by Antoine Perrin on 6/19/21.
//

#include <iostream>

#include "OptionObject.h"
#include "AssetObject.h"
#include "PricerBlackScholes.h"
#include "ImpliedSolver.h"


int main(int argc, const char * argv[]) {
    
    //Setup Put/Call and an asset
    Option europtestcall("c",1,30);
    Option europtestput("p",1,30);
    Asset socgen("Societe Generale",26.20,0.01,0.2);
    
    // Calculate Call
    std::cout << "Price of the call is: "<<option_price(europtestcall,  socgen)<<std::endl;
    // Modify strike and recalculate
    europtestcall.set_strike(20);
    std::cout << "Price of the call is: "<<option_price(europtestcall,  socgen)<<std::endl;
    
    // Calculate Put
    std::cout << "Price of the put is: "<<option_price(europtestput,  socgen)<<std::endl;
    // Modify strike and recalculate
    europtestput.set_strike(20);
    std::cout << "Price of the put is: "<<option_price(europtestput,  socgen)<<std::endl;
    
    // Set Market quote in order to solve volatility
    europtestcall.set_market_quote(7.05);
    europtestput.set_market_quote(6.03);
    
    // Solve implied Volatility
    
    std::cout<< "Implied Volatility of the call is: "<<vanilla_implied_volatility(europtestcall, socgen, 0.01) <<std::endl;
    std::cout<<"Implied Volatility of the put is: "<<vanilla_implied_volatility(europtestput, socgen, 0.01) <<std::endl;
    return 0;
}
