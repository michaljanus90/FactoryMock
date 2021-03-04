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
            return std::make_shared<MinItem>();
        case 'M':
            return std::make_shared<MaxItem>();
        default:
            throw std::runtime_error("Not valid sign");
    }
    return nullptr;
}
}