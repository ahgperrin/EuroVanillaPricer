//
//  OptionObject.cpp
//  EuroVanillaPricer
//
//  Created by Antoine Perrin on 6/19/21.
//

#include "OptionObject.h"

#include <iostream>


Option::Option(std::string type,double time_maturity,double strike, int basis){
    set_type(type);
    set_ttm(time_maturity);
    set_strike(strike);
    set_basis(basis);
    
}

void Option::set_type(std::string value){
    if (value == "c") {
        m_type = value;
    }else if (value == "p"){
        m_type = value;
    }else{
        std::cout<<"Value must be c for call or p for put"<<std::endl;
    }
        
}
void Option::set_ttm(double time_maturity){
    m_time_maturity = time_maturity;
    }

void Option::set_strike(double strike){
    m_strike =strike;
    }

void Option::set_market_quote(double market_quote){
    m_market_quote =market_quote;
    }
void Option::set_basis(int basis){
    m_basis =basis;
    }
