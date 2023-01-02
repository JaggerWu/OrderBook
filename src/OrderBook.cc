#include "OrderBook.h"

bool OrderBook::execute_trade()
{
    return false;
}

OrderBook::OrderBook(uint32_t max_price_)
{
}

BidAsk OrderBook::get_bid_ask() const
{
    return BidAsk();
}

bool OrderBook::insert_order(Order order)
{
    return false;
}

bool OrderBook::cancel_order(uint64_t order_id)
{
    return false;
}

OrderBook::~OrderBook()
{
}
