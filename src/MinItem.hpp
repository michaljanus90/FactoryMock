#pragma once
#include "IItem.hpp"

namespace src
{
class MinItem : public IItem
{
public:
    MinItem() = default;
    double calculate(double a, double b) override;
};
}