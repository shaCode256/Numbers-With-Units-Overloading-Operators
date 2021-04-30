#include "NumberWithUnits.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <map>
#include <iostream>
#include <cassert>
#include <math.h>
using namespace ariel;
using namespace std;

double epsilon= 0.001;

map<string, map<string, double>>  NumberWithUnits::NumberWithUnits::NumberWithUnits::unitsMap;
void NumberWithUnits::read_units(ifstream &file)
{
    string line;
    string strNum = "";
    string firstUnit = "";
    string secondUnit = "";
    int countWords = -1;
    string wordsArray [3];
   
    if (file.is_open())
    {
        while (getline(file, line)) //for every line
        {
            // 1 km = 1000 m
            countWords=-1;
            for (size_t i = 2; i < line.length(); i++)
            {
                if (line.at(i)!= ' ' && line.at(i)!= '='){
                    countWords++;
                    wordsArray[countWords]= "";
                    while( i < line.length() && line.at(i)!= ' ' ){
                     wordsArray[countWords]+= line.at(i);
                    i++;
                    }
                }
            }
            double amount = std::stod(wordsArray[1]);
            string firstUnit= string(wordsArray[0]);
            string secondUnit= string(wordsArray[2]);
            NumberWithUnits::unitsMap[firstUnit][secondUnit] = amount;
            NumberWithUnits::unitsMap[secondUnit][firstUnit] = 1/amount;
            for(auto &map : unitsMap[firstUnit]){
                double value= unitsMap[secondUnit][firstUnit]* map.second;
                unitsMap[secondUnit][map.first]= value;
                unitsMap[map.first][secondUnit]= 1/value;
            }
            for(auto &map : unitsMap[secondUnit]) {
                double value = unitsMap[firstUnit][secondUnit] * map.second;
                unitsMap[firstUnit][map.first] = value;
                unitsMap[map.first][firstUnit] = 1/value;
            }
        }
    }
    file.close();
}

//calc operators:
NumberWithUnits NumberWithUnits::operator+(NumberWithUnits num)
{     
    double convert = convertAmount(num._unit, this->_unit);
    return NumberWithUnits(_amount + (num._amount * convert), _unit);
}
NumberWithUnits NumberWithUnits::operator-(NumberWithUnits &num)
{
    double convert = convertAmount(num._unit, this->_unit);
    return NumberWithUnits(_amount - num._amount * convert, _unit);
}

// comparison operators
bool NumberWithUnits::operator==(const NumberWithUnits num) const
{
    double convert = convertAmount(num._unit, this->_unit);
    double converted= num._amount * convert;
    return abs(_amount - converted) < epsilon;
}

bool NumberWithUnits::operator>( const NumberWithUnits &num) const
{
    double convert = convertAmount(num._unit, this->_unit);
    if (_amount > num._amount * convert)
    {
        return true;
    }
    return false;
}
bool NumberWithUnits::operator>=(const NumberWithUnits &num) const
{
    if (*this == num || *this > num)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool NumberWithUnits::operator<(const NumberWithUnits &num) const
{
    double convert = convertAmount(num._unit, this->_unit);
    if (_amount < num._amount * convert)
    {
        return true;
    }
    return false;
}
bool NumberWithUnits::operator<=(const NumberWithUnits &num) const
{
    if (*this == num || *this < num)
    {
        return true;
    }
    return false;
}
bool NumberWithUnits::operator!=(const NumberWithUnits &num) const
{
    if (*this == num)
    {
        return false;
    }
    else
    {
        return true;
    }
}

//ostream operations
ostream &ariel::operator<<(ostream &output, const NumberWithUnits &num)
{
    return (output << num._amount << '[' << num._unit << ']');
}

istream &ariel::operator>>(istream &input, NumberWithUnits &num)
{
    string str;
    string strNum;
    string unit;
    bool readNum = false;
    getline(input, str, {});
    for (size_t i = 0; i < str.length(); i++)
    {
        //   {"     700[ kg ]"};
        if (str.at(i) != ' ')
        {
            if (readNum == false) //if you didn't reach the number yet
            {
                readNum = true; //you just did reach the num
                while (str.at(i) != ' ' && str.at(i)!= '[') //as long as you keep reading the number
                {
                    strNum = strNum + str.at(i);
                    i++;
                }
            }
            if (readNum == true && str.at(i) != '[' && str.at(i) != ']' && str.at(i)!= ' ')
            {
                unit = unit + str.at(i);
            }
        }
    }
    double amount = std::stod(strNum);
    if(NumberWithUnits::unitsMap.find(unit)!=NumberWithUnits::unitsMap.end()){ //if there is a unit like that and amount is a number
    num._amount = amount;
    num._unit = unit;
    }
    else{
        throw exception();
    }
    // num._amount = amount;
    // num._unit = unit;
    return input;
}

double NumberWithUnits::convertAmount(string unitFrom, string unitTo)
{
    if (NumberWithUnits::unitsMap.find(unitFrom) != NumberWithUnits::unitsMap.end())
    {
        if (NumberWithUnits::unitsMap[unitFrom].find(unitTo) != NumberWithUnits::unitsMap[unitFrom].end())
        {
            return (NumberWithUnits::unitsMap[unitFrom][unitTo]);
        }
        else
        {
             throw exception(); //not known conversion
        }
    }
        else
        {
             throw exception(); //not known conversion
        }
    return 0;
}
