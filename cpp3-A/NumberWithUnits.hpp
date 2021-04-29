#pragma once
#include <string>
#include <stdexcept>
#include <map>
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>

namespace ariel
{
    using namespace std;

    class NumberWithUnits
    {

    private:
        double _amount;
        string _unit;
    public:
        // Constructor
        static map<string, map<string, double>> unitsMap;
        NumberWithUnits(const double &amount, const string &unit)
        {
            _amount = amount;
            _unit = unit;
        }

        // initalizing ("empty") constructor
        NumberWithUnits(){};

        static void read_units(ifstream &file);

        //calc operators:
        NumberWithUnits operator+()
        { //plus unary
            return NumberWithUnits(abs(_amount), _unit);
        }
        NumberWithUnits operator-()
        { // minus unary
            return NumberWithUnits(-1 * _amount, _unit);
        }
        NumberWithUnits operator+(NumberWithUnits num);
        NumberWithUnits &operator++()
        {
            _amount++;
            return *this;
        }
        const NumberWithUnits operator++(int) {
            return NumberWithUnits(_amount++, _unit);
        }
        NumberWithUnits &operator--()
        {
            _amount--;
            return *this;
        }
        const NumberWithUnits operator--(int) {
            return NumberWithUnits(_amount--, _unit);
        }
        static double convertAmount(string unit, string toUnit);
        NumberWithUnits operator-(NumberWithUnits &num);
        NumberWithUnits &operator-=(const NumberWithUnits &num){
            _amount = _amount- num._amount * convertAmount(num._unit, _unit);
            return *this;
        }
        NumberWithUnits &operator+=(const NumberWithUnits &num){
            _amount = _amount+ num._amount * convertAmount(num._unit, _unit);
            return *this;
        }
        friend const NumberWithUnits operator*(const int num, const NumberWithUnits &curr)
        {
            return NumberWithUnits(curr._amount * num, curr._unit);
        }
        friend const NumberWithUnits operator*(const double num, const NumberWithUnits &curr)
        {
            return NumberWithUnits(curr._amount * num, curr._unit);
        }
        friend const NumberWithUnits operator*(const NumberWithUnits &curr, const double num)
        {
            return NumberWithUnits(curr._amount * num, curr._unit);
        }
        // comparison operators
        bool operator>(NumberWithUnits &num) const;
        bool operator>=(NumberWithUnits &num) const;
        bool operator<(NumberWithUnits &num) const;
        bool operator<=(NumberWithUnits &num) const;
     //   bool operator==(NumberWithUnits& num1) const;
        bool operator!=(NumberWithUnits &num) const;
        bool operator==(NumberWithUnits num) const;

        //ostream operations
        friend ostream &operator<<(ostream &output, const NumberWithUnits &num);
        friend istream &operator>>(istream &input, NumberWithUnits &num);
    };
}