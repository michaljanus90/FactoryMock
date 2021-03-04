#pragma once

namespace src
{
class IItem
{
public:
    virtual ~IItem() = default;
    virtual double calculate(double a, double b) = 0;
};
}