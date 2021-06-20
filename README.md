#  Black and Schole Option Pricer with C++

This code has been written to calculate option price with C++ Programming language.
### Why C++ ? 
    C++ because it is much more low latency in calculating Implied volatility by solver methods than another language.

### FrameWork:
    Option Class : Create an object Option with his caracteristics:
        - Strike Price 
        - Time to maturity : In years
        - Option Type : "c" for call / "p" for put
        - Another attribute is "market_quote" : You can set this attributes using his setter and this 
        attribute is used to solve implied volatility
        - Basis : Number days in the year in order to compute the value of one day to compute theta
    Asset Class : Create an object Asset with his caracteristics:
        - Volatility
        - Rick free Rate of returns
        - Name
        - Current Price : Spot
    Module : Implied Solver
        - This module contains function used to solve implied volatility from european market quote
    Module : Pricer Black and scholes
        - This module contains function used to price options
    Module : Normal Distribution
        - This module contains Class NormalDist which is used in order to compute stats from normal distribution

### Example (same as in the main.cpp):

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
    Output Will be :
    
    
    ================ The Goldman Sachs Group ================
    =========================================================
    Current Stock Price is: 348.83 $
    Price of the call is: 25.2061
    Price of the put is: 23.8478
    Implied Volatility of the call is: 0.0646389
    Implied Volatility of the put is: 0.0680967
    Delta of the put is: -0.459952
    Delta of the call is: 0.540048
    Gamma is: 0.00638371
    Vega is: 0.970981
    Rho of the put is: -0.914611
    Rho of the call is: 0.822747
    Theta of the put is: -0.0674986
    Theta of the call is: -0.0674524
