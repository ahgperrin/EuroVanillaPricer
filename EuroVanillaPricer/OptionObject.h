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
    double m_time_maturity;
    double m_strike;
    double m_market_quote;
    
    
    public:
    //Constructor
    Option(std::string type,double time_maturity,double strike);
    
    //Getters
    std::string get_type(){return m_type;};
    double get_time_maturity(){return m_time_maturity;};
    double get_strike(){return m_strike;};
    double get_market_quote(){return m_market_quote;};
    
    //Setters
    void set_type(std::string);
    void set_ttm(double);
    void set_strike(double);
    void set_market_quote(double);

};

#endif /* OptionObject_h */
