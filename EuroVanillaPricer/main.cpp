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
    
    //Setup
    Option europtestcall("c",1,30);
    Option europtestput("p",1,30);
    Asset socgen("Societe Generale",26.20,0.05,0.364868);
    
    // Calculate Call
    std::cout << option_price(europtestcall,  socgen,0.01)<<std::endl;
    europtestcall.set_strike(20);
    std::cout << option_price(europtestcall,  socgen,0.01)<<std::endl;
    
    // Calculate Put
    std::cout << option_price(europtestput,  socgen,0.01)<<std::endl;
    europtestput.set_strike(20);
    std::cout << option_price(europtestput,  socgen,0.01)<<std::endl;
    
    // Set Market quote
    europtestcall.set_market_quote(7.05);
    europtestput.set_market_quote(6.03);
    std::cout<< europtestcall.get_market_quote()<<std::endl;
    std::cout<< europtestput.get_market_quote()<<std::endl;
    std::cout<<vanilla_implied_volatility(europtestcall, socgen, 0.01) <<std::endl;
    std::cout<<vanilla_implied_volatility(europtestput, socgen, 0.01) <<std::endl;
    return 0;
}
