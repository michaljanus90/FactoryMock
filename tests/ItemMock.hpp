#pragma once

#include "IItem.hpp"
// #include <gmock/gmock.h>
#include "gmock/gmock.h"

class ItemMock : public src::IItem
{
public:
    MOCK_METHOD2(calculate, double(double a, double b));
};