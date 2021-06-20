//
//  OptionObject.h
//  EuroVanillaPricer
//
//  Created by Antoine Perrin on 6/19/21.
//

#ifndef OptionObject_h
#define OptionObject_h
#include <iostream>
class Option{
    
    //Create an european option
    private:
    std::string m_type;
    double m_timeMaturity;
    double m_strike;
    double m_marketQuote;
    double m_basis;
    
    
    public:
    //Constructor
    Option(std::string type,double timeMaturity,double strike, int basis);
    
    //Getters
    std::string type(){return m_type;};
    double timeMaturity(){return m_timeMaturity;};
    double strike(){return m_strike;};
    double marketQuote(){return m_marketQuote;};
    int basis(){return m_basis;};
    
    //Setters
    void setType(std::string);
    void setTimeMaturity(double);
    void setStrike(double);
    void setMarketQuote(double);
    void setBasis(int);

};

#endif /* OptionObject_h */
