#include "Factory.hpp"
#include "IItem.hpp"
#include "MinItem.hpp"
#include "MaxItem.hpp"

namespace src
{
Factory::ItemPtr Factory::create(char a)
{
    switch (a)
    {
        case 'm':
            return std::make_unique<MinItem>();
        case 'M':
            return std::make_unique<MaxItem>();
        default:
            throw std::runtime_error("Not valid sign");
    }
    return nullptr;
}
}