#pragma once

#include <iostream>
#include <string>

#include "Order.h"

#define MAX_NUM_ORDERS       1010000;
#define MAX_NUM_PRICE_LEVELS 100000;

typedef uint32_t order_size;
typedef uint32_t price_level;


typedef struct OrderEntry
{    
    order_size  size;
    OrderEntry* next;
} OrderEntry;

typedef struct PriceLevel
{
    OrderEntry* head;
    OrderEntry* tail;
} PriceLevel;

typedef struct BidAsk
{
    price_level bid;
    price_level ask;
} BidAsk;

/**
 * @brief 
 */
class OrderBook
{
private:
    PriceLevel *m_bids, *m_asks;
    price_level m_bid, m_ask;

    bool execute_trade();
public:
    OrderBook(uint32_t max_price_);

    BidAsk get_bid_ask() const;

    bool insert_order(Order order);

    bool cancel_order(uint64_t order_id);

    ~OrderBook();
};
