#pragma once
// #include "IFactory.hpp"
#include "Factory.hpp"
#include "IItem.hpp"
#include <memory>

namespace src
{
class IItem;

class Usage
{
public:
    Usage(char s = 'm', std::shared_ptr<IFactory> factory = std::make_shared<Factory>());

    void doSmth(double a, double b);
private:
    Factory::ItemPtr ptr;
};
}