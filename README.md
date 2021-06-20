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
