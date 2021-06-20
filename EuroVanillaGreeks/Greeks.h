//
//  Greeks.h
//  EuroVanillaPricer
//
//  Created by Antoine Perrin on 6/20/21.
//

#ifndef Greeks_h
#define Greeks_h

#include "AssetObject.h"
#include "OptionObject.h"
double delta( Option option,Asset asset);
double gamma( Option option,Asset asset);
double vega( Option option,Asset asset);
double rho( Option option,Asset asset);
double theta( Option option,Asset asset);
#endif /* Greeks_h */
