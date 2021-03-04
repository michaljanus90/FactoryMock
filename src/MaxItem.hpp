#pragma once
#include "IItem.hpp"

namespace src
{
class MaxItem : public IItem
{
public:
    MaxItem() = default;
    double calculate(double a, double b) override;
};
}