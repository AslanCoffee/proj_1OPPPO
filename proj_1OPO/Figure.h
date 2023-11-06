#pragma once
#include <string>

class Figure {
private:
    double density;
    std::string owner;

public:
    Figure(double d, const std::string& o);
    double getDensity() const;
    std::string getOwner() const;
    virtual void print() const;
    virtual bool matchesCondition(const std::string& condition) const;
    virtual ~Figure();
};