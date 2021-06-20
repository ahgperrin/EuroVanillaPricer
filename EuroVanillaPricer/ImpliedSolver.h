//
//  ImpliedSolver.h
//  EuroVanillaPricer
//
//  Created by Antoine Perrin on 6/20/21.
//

#ifndef ImpliedSolver_h
#define ImpliedSolver_h
#include "AssetObject.h"
#include "OptionObject.h"
double vanilla_implied_volatility(Option option,Asset asset,double risk_free_rate);
#endif /* ImpliedSolver_h */
