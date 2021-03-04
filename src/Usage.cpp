#include "Usage.hpp"
#include <iostream>

namespace src
{
Usage::Usage(char s, std::shared_ptr<IFactory> factory) :
    ptr(factory->create(s))
{

}

void Usage::doSmth(double a, double b)
{
    auto ret = ptr->calculate(a,b);
    std::cout << "Returning: " << ret << std::endl;
}
}