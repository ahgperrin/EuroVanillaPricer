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
    
    
    Output Will be :
    
    Price of the call is: 0.897683
    Price of the call is: 6.5654
    Price of the put is: 4.39918
    Price of the put is: 0.166398
    Implied Volatility of the call is: 0.301762
    Implied Volatility of the put is: 1.01417
