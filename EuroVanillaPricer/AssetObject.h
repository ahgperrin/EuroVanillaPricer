//
//  AssetObject.h
//  EuroVanillaPricer
//
//  Created by Antoine Perrin on 6/19/21.
//

#ifndef AssetObject_h
#define AssetObject_h
#include<iostream>
class Asset{
    
private:
    std::string m_assetName;
    double m_currentPrice;
    double m_riskFreeRate;
    double m_volatility;

public:
    //Constructor
    Asset(std::string asset_name,double current_price,double risk_free_rate,double volatility);
    
    //getters
    std::string assetName(){return m_assetName;};
    double currentPrice(){return m_currentPrice;};
    double riskFreeRate(){return m_riskFreeRate;};
    double volatility(){return m_volatility;};
    
    //setters
    void setAssetName(std::string);
    void setCurrentPrice(double);
    void setRiskFreeRate(double);
    void setVolatility(double);
    
};
#endif /* AssetObject_h */
