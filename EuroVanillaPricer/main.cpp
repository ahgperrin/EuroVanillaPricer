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
    Option europeanCall("c",0.5,350,365);
    Option europeanPut("p",0.5,350,365);
    Asset goldmanSachs("The Goldman Sachs Group",348.83,0.0145,0.25);
    
    std::cout<<"================ "<< goldmanSachs.assetName()<<" ================"<<std::endl;
    std::cout<<"========================================================="<<std::endl;
    
    std::cout << "Current Stock Price is: "<<goldmanSachs.currentPrice()<<" $"<<std::endl;
    
    // Calculate Call
    std::cout << "Price of the call is: "<<optionPrice(europeanCall,  goldmanSachs)<<std::endl;

    // Calculate Put
    std::cout << "Price of the put is: "<<optionPrice(europeanPut,  goldmanSachs)<<std::endl;

    // Set Market quote in order to solve volatility
    europeanCall.setMarketQuote(7.05);
    europeanPut.setMarketQuote(6.03);
    
    // Solve implied Volatility
    
    std::cout<<"Implied Volatility of the call is: "<<vanillaImpliedVolatility(europeanCall, goldmanSachs) <<std::endl;
    std::cout<<"Implied Volatility of the put is: "<<vanillaImpliedVolatility(europeanPut, goldmanSachs) <<std::endl;
    
    // Compute Delta
    std::cout<<"Delta of the put is: "<<delta(europeanPut, goldmanSachs) <<std::endl;
    std::cout<<"Delta of the call is: "<<delta(europeanCall, goldmanSachs) <<std::endl;
    
    // Compute Gamma
    std::cout<<"Gamma is: "<<gamma(europeanPut, goldmanSachs) <<std::endl;
    
    // Compute Vega
    std::cout<<"Vega is: "<<vega(europeanPut, goldmanSachs) <<std::endl;
    
    // Compute Rho
    std::cout<<"Rho of the put is: "<<rho(europeanPut, goldmanSachs) <<std::endl;
    std::cout<<"Rho of the call is: "<<rho(europeanCall, goldmanSachs) <<std::endl;
    
    // Compute Theta
    std::cout<<"Theta of the put is: "<<theta(europeanPut, goldmanSachs) <<std::endl;
    std::cout<<"Theta of the call is: "<<theta(europeanCall, goldmanSachs) <<std::endl;
    
    return 0;
}
