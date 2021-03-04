#pragma once

#include "IFactory.hpp"
#include <gmock/gmock.h>

class FactoryMock : public src::IFactory
{
public:
    MOCK_METHOD1(create, std::unique_ptr<src::IItem>(char a));
};