#pragma once
#include <string>
#include <sstream>

class Figure {
private:
    double density;
    std::string owner;

public:
    Figure(double d, const std::string& o);
    double getDensity() const;
    std::string getOwner() const;
    bool isNumber_D(char& op, double& x, std::istringstream& iss) const;
    float Switch_haha(char op, double atribute, double value) const;
    virtual void print() const;
    virtual bool matchesCondition(const std::string& condition) const;
    virtual ~Figure();
};