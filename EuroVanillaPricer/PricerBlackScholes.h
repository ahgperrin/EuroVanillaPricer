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
double volTerm(Option option, Asset asset);
double driftTerm(Option option, Asset asset);
double prodD1(Option option, Asset asset);
double probD2(Option option, Asset asset);
double discountFactor(Option option,Asset asset);
double optionPrice(Option option, Asset asset);

#endif /* PricerBlackScholes_h */
