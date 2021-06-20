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
    std::string m_asset_name;
    double m_current_price;
    double m_mean_returns;
    double m_volatility;

public:
    //Constructor
    Asset(std::string asset_name,double current_price,double mean_returns,double volatility);
    
    //getters
    std::string get_asset_name(){return m_asset_name;};
    double get_current_price(){return m_current_price;};
    double get_mean_returns(){return m_mean_returns;};
    double get_volatility(){return m_volatility;};
    
    //setters
    void set_asset_name(std::string);
    void set_current_price(double);
    void set_mean_returns(double);
    void set_volatility(double);
    
};
#endif /* AssetObject_h */
