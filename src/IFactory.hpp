#pragma once
#include <memory>

namespace src
{
class IItem;

class IFactory
{
public:
    using ItemPtr = std::shared_ptr<IItem>; 
    virtual ~IFactory() = default;
    virtual ItemPtr create(char a) = 0;
};
}