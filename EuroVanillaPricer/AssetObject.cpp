//
//  AssetObject.cpp
//  EuroVanillaPricer
//
//  Created by Antoine Perrin on 6/19/21.
//

#include <stdio.h>
#include "AssetObject.h"

Asset::Asset(std::string asset_name,double current_price,double mean_returns,double volatility){
    set_asset_name(asset_name);
    set_volatility(volatility);
    set_mean_returns(mean_returns);
    set_current_price(current_price);
};

void Asset::set_asset_name(std::string name){
    m_asset_name = name;
};
void Asset::set_current_price(double current_price){
    m_current_price = current_price;
};
void Asset::set_mean_returns(double mean_returns){
    m_mean_returns = mean_returns;
};
void Asset::set_volatility(double volatility){
    m_volatility = volatility;
};
