#include "gtest/gtest.h"
// #include "gmock/gmock.h"
#include "Usage.hpp"
#include "ItemMock.hpp"
#include "FactoryMock.hpp"
#include <memory>

using testing::StrictMock;
using namespace src;

using ItemMockPtr = std::shared_ptr<ItemMock>;
using FactoryMockPtr = std::shared_ptr<FactoryMock>;

class MyTC : public testing::Test
{
public:
    MyTC():
        factoryMock(std::make_shared<FactoryMock>()),
        itemMock(std::make_shared<ItemMock>())
    {
        expectCall();
        sut = std::make_unique<Usage>('m', factoryMock);
    }

    void expectCall()
    {
        EXPECT_CALL(*factoryMock, create(testing::_))
            .WillOnce(testing::Return(itemMock));
        
    }
protected:
    std::unique_ptr<src::Usage> sut;
    FactoryMockPtr factoryMock;
    ItemMockPtr itemMock;
};

TEST_F(MyTC, simpleTest)
{
    EXPECT_CALL(*itemMock, calculate(10.7, 20.4))
        .WillOnce(testing::Return(10.7));
    sut->doSmth(10.7, 20.4);
    EXPECT_EQ(10.7, 10.7);
}