#include "NumberWithUnits.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <map>
#include <iostream>
#include <cassert>

using namespace ariel;
using namespace std;

map<string, map<string, double>>  NumberWithUnits::NumberWithUnits::NumberWithUnits::unitsMap;
void NumberWithUnits::read_units(ifstream &file)
{
    // cout << "hey";
    string line;
    string strNum = "";
    string firstUnit = "";
    string secondUnit = "";
    int countWords = -1;
    string wordsArray [3];
   
    if (file.is_open())
    {
        while (getline(file, line)) //for every live
        {
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
            NumberWithUnits::unitsMap[string(wordsArray[0])][string(wordsArray[2])] = amount;
            // cout << "first Unit " << wordsArray[0] << "\n";
            // cout << "number " << wordsArray[1] << "\n";
            // cout << "second unit " << wordsArray[2] << "\n"; 

        }
    }

    file.close();
    //  cout << "first Unit " << wordsArray[0] << "\n";
    //  cout << "second unit " << wordsArray[2] << "\n"; 
   // cout << "walla! " <<NumberWithUnits::unitsMap[wordsArray[0]][wordsArray[2]] << "\n";
    // string f= firstUnit;
    // cout << "a" << f << "a" << "\n";
    // string s= secondUnit;
  //   cout << "walla! " <<NumberWithUnits::unitsMap["km"][string("m")] << "\n";

    // cout << firstUnit==secondUnit;
}

//calc operators:
NumberWithUnits NumberWithUnits::operator+(NumberWithUnits num)
{   
  //  cout << "walla! " << NumberWithUnits::unitsMap["km"]["m"] << "\n";
    double convert = convertAmount(num._unit, this->_unit);
    cout << "conv is " << convert << "\n";
    return NumberWithUnits(_amount + (num._amount * convert), _unit);
}
NumberWithUnits NumberWithUnits::operator-(NumberWithUnits &num)
{
    double convert = convertAmount(num._unit, this->_unit);
    return NumberWithUnits(_amount - num._amount * convert, _unit);
}

// comparison operators
bool NumberWithUnits::operator==(NumberWithUnits num) const
{
    double convert = convertAmount(this->_unit, num._unit);
    if (_amount == num._amount * convert)
    {
        return true;
    }
    return false;
}

bool NumberWithUnits::operator>(NumberWithUnits &num) const
{
    double convert = convertAmount(num._unit, this->_unit);
    if (_amount < num._amount * convert)
    {
        return true;
    }
    return false;
}
bool NumberWithUnits::operator>=(NumberWithUnits &num) const
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
bool NumberWithUnits::operator<(NumberWithUnits &num) const
{
    double convert = convertAmount(num._unit, this->_unit);
    if (_amount < num._amount * convert)
    {
        return true;
    }
    return false;
}
bool NumberWithUnits::operator<=(NumberWithUnits &num) const
{
    if (*this == num || *this < num)
    {
        return true;
    }
    return false;
}
bool NumberWithUnits::operator!=(NumberWithUnits &num) const
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
    getline(cin, str, {});
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str.at(i) != ' ')
        {
            if (readNum == false)
            {
                readNum = true;
                while (str.at(i) != ' ')
                {
                    strNum = strNum + str.at(i);
                    i++;
                }
            }
            if (readNum == true && str.at(i) != '[' && str.at(i) != ']')
            {
                unit = unit + str.at(i);
            }
        }
    }
    double amount = std::stod(strNum);
    num._amount = amount;
    num._unit = unit;
    return input;
}

double NumberWithUnits::convertAmount(string unit, string toUnit)
{
    cout << unit << "\n";
    cout << toUnit << "\n";
    // cout << "walla! " <<NumberWithUnits::unitsMap.at("km").at("m") << "\n";
    if (NumberWithUnits::unitsMap.find(unit) != NumberWithUnits::unitsMap.end())
    {
        if (NumberWithUnits::unitsMap[unit].find(toUnit) != NumberWithUnits::unitsMap[unit].end())
        {
            return (NumberWithUnits::unitsMap[unit][toUnit]);
        }
    }
    else
    {
        if (NumberWithUnits::unitsMap.find(toUnit) != NumberWithUnits::unitsMap.end())
        {
            if (NumberWithUnits::unitsMap[toUnit].find(unit) != NumberWithUnits::unitsMap[toUnit].end())
            {
                return (1 / NumberWithUnits::unitsMap[toUnit][unit]);
            }
        }
        else
        {
            // throw exception(); //not known conversion
        }
    }
    return 0;
}
