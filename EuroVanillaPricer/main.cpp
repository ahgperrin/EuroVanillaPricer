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
#include "Greeks.h"

int main(int argc, const char * argv[]) {
    
    //Setup Put/Call and an asset
    Option europtestcall("c",0.5,350,365);
    Option europtestput("p",0.5,350,365);
    Asset goldman("The Goldman Sachs Group",348.83,0.0145,0.25);
    
    std::cout<<"================ "<< goldman.get_asset_name()<<" ================"<<std::endl;
    std::cout<<"========================================================="<<std::endl;
    
    std::cout << "Current Stock Price is: "<<goldman.get_current_price()<<" $"<<std::endl;
    
    // Calculate Call
    std::cout << "Price of the call is: "<<option_price(europtestcall,  goldman)<<std::endl;

    // Calculate Put
    std::cout << "Price of the put is: "<<option_price(europtestput,  goldman)<<std::endl;

    // Set Market quote in order to solve volatility
    europtestcall.set_market_quote(7.05);
    europtestput.set_market_quote(6.03);
    
    // Solve implied Volatility
    
    std::cout<<"Implied Volatility of the call is: "<<vanilla_implied_volatility(europtestcall, goldman) <<std::endl;
    std::cout<<"Implied Volatility of the put is: "<<vanilla_implied_volatility(europtestput, goldman) <<std::endl;
    
    // Compute Delta
    std::cout<<"Delta of the put is: "<<delta(europtestput, goldman) <<std::endl;
    std::cout<<"Delta of the call is: "<<delta(europtestcall, goldman) <<std::endl;
    
    // Compute Gamma
    std::cout<<"Gamma is: "<<gamma(europtestput, goldman) <<std::endl;
    
    // Compute Vega
    std::cout<<"Vega is: "<<vega(europtestput, goldman) <<std::endl;
    
    // Compute Rho
    std::cout<<"Rho of the put is: "<<rho(europtestput, goldman) <<std::endl;
    std::cout<<"Rho of the call is: "<<rho(europtestcall, goldman) <<std::endl;
    
    // Compute Theta
    std::cout<<"Theta of the put is: "<<theta(europtestput, goldman) <<std::endl;
    std::cout<<"Theta of the call is: "<<theta(europtestcall, goldman) <<std::endl;
    
    return 0;
}
