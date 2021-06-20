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
    double m_risk_free_rate;
    double m_volatility;

public:
    //Constructor
    Asset(std::string asset_name,double current_price,double risk_free_rate,double volatility);
    
    //getters
    std::string get_asset_name(){return m_asset_name;};
    double get_current_price(){return m_current_price;};
    double get_risk_free_rate(){return m_risk_free_rate;};
    double get_volatility(){return m_volatility;};
    
    //setters
    void set_asset_name(std::string);
    void set_current_price(double);
    void set_risk_free_rate(double);
    void set_volatility(double);
    
};
#endif /* AssetObject_h */
