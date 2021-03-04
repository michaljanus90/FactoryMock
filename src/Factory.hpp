#pragma once
#include "IFactory.hpp"

namespace src
{
class Factory : public IFactory
{
public:
    ItemPtr create(char a) override;
};
}