//
//  AssetObject.cpp
//  EuroVanillaPricer
//
//  Created by Antoine Perrin on 6/19/21.
//

#include <stdio.h>
#include "AssetObject.h"

Asset::Asset(std::string asset_name,double current_price,double risk_free_rate,double volatility){
    set_asset_name(asset_name);
    set_volatility(volatility);
    set_risk_free_rate(risk_free_rate);
    set_current_price(current_price);
};

void Asset::set_asset_name(std::string name){
    m_asset_name = name;
};
void Asset::set_current_price(double current_price){
    m_current_price = current_price;
};
void Asset::set_risk_free_rate(double risk_free_rate){
    m_risk_free_rate = risk_free_rate;
};
void Asset::set_volatility(double volatility){
    m_volatility = volatility;
};
