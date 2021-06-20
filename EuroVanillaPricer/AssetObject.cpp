//
//  AssetObject.cpp
//  EuroVanillaPricer
//
//  Created by Antoine Perrin on 6/19/21.
//

#include <stdio.h>
#include "AssetObject.h"

Asset::Asset(std::string assetName,double curentPrice,double riskFreeRate,double volatility){
    setAssetName(assetName);
    setVolatility(volatility);
    setRiskFreeRate(riskFreeRate);
    setCurrentPrice(curentPrice);
};

void Asset::setAssetName(std::string name){
    m_assetName = name;
};
void Asset::setCurrentPrice(double current_price){
    m_currentPrice = current_price;
};
void Asset::setRiskFreeRate(double risk_free_rate){
    m_riskFreeRate = risk_free_rate;
};
void Asset::setVolatility(double volatility){
    m_volatility = volatility;
};
