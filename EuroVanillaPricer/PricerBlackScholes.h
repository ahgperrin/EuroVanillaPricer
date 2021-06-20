//
//  PricerBlackScholes.h
//  EuroVanillaPricer
//
//  Created by Antoine Perrin on 6/20/21.
//

#ifndef PricerBlackScholes_h
#define PricerBlackScholes_h
#include "AssetObject.h"
#include "OptionObject.h"

double moneyness(Option opt,Asset Ass);
double vol_term(Option option, Asset asset);
double drift_term(Option option, Asset asset,double risk_free_rate);
double d_1(Option option, Asset asset,double risk_free_rate);
double d_2(Option option, Asset asset,double risk_free_rate);
double discount_factor(Option option,double risk_free_rate);
double option_price(Option option, Asset asset,double risk_free_rate);

#endif /* PricerBlackScholes_h */
