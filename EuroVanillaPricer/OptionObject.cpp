//
//  OptionObject.cpp
//  EuroVanillaPricer
//
//  Created by Antoine Perrin on 6/19/21.
//

#include "OptionObject.h"

#include <iostream>


Option::Option(std::string type,double timeMaturity,double strike, int basis){
    setType(type);
    setTimeMaturity(timeMaturity);
    setStrike(strike);
    setBasis(basis);
    
}

void Option::setType(std::string value){
    if (value == "c") {
        m_type = value;
    }else if (value == "p"){
        m_type = value;
    }else{
        std::cout<<"Value must be c for call or p for put"<<std::endl;
    }
        
}
void Option::setTimeMaturity(double timeMaturity){
    m_timeMaturity = timeMaturity;
    }

void Option::setStrike(double strike){
    m_strike = strike;
    }

void Option::setMarketQuote(double marketQuote){
    m_marketQuote = marketQuote;
    }
void Option::setBasis(int basis){
    m_basis = basis;
    }
