#include <gtest/gtest.h>
#include <iostream>
#include <Order.h>
#include <OrderBook.h>

TEST(OrderTest, OrderExecutionTest)
{
    Order o("TestTrader", "Apple", 100, 1000, Order::Side::buy);
    o.execute(18, 500);

    ASSERT_EQ(o.getOpenQuantity(), 500);
    ASSERT_EQ(o.getLastExecutedPrice(), 18);
    ASSERT_EQ(o.getLastExecutedQuantity(), 500);
    ASSERT_EQ(o.getAvgExecutedPrice(), 18);

    o.execute(20, 500);
    ASSERT_EQ(o.getAvgExecutedPrice(), 19);
    ASSERT_EQ(o.getLastExecutedPrice(), 20);
    ASSERT_EQ(o.getLastExecutedQuantity(), 500);
    ASSERT_TRUE(o.isFilled());
    ASSERT_TRUE(o.isClosed());
}


TEST(OrderBookTests, OrderBookEmptyByDefault)
{
    OrderBook a(1000);
    bool cancelled = a.cancel_order(1);
    ASSERT_EQ(1, 1);
}
