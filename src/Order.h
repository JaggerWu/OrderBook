#pragma once
#include <ostream>
#include <iomanip>
#include <string>

class Order
{
    friend std::ostream& operator<<(std::ostream& ostream, const Order& order);
public:
    enum Side { buy, sell };

    Order(const std::string trader_, const std::string symbol_, 
          uint32_t price_, uint32_t quantity_, Side side_):
        m_trader(trader_), m_symbol(symbol_), m_price(price_), m_quantity(quantity_), m_side(side_)
    {
        m_open_quantity = m_quantity;
        m_executed_quantity = 0;
        m_last_executed_price = 0;
        m_last_executed_quantity = 0;
        m_avg_executed_price = 0;
    }

    static Order* CreateOrder(
        const std::string trader_, const std::string symbol_, 
        uint32_t price_, uint32_t quantity_, Side side_)
    {
        return new Order(trader_, symbol_, price_, quantity_, side_);
    }

    bool isFilled() const
    {
        return m_quantity == m_executed_quantity;
    }

    bool isClosed() const
    {
        return m_open_quantity == 0;
    }

    virtual void execute(uint32_t price_, uint32_t quantity_)
    {
        m_avg_executed_price = ((m_avg_executed_price * m_executed_quantity) + (price_ * quantity_))
            / (quantity_ + m_executed_quantity);

        m_open_quantity -= quantity_;
        m_executed_quantity += quantity_;

        m_last_executed_price = price_;
        m_last_executed_quantity = quantity_;
    }

    const std::string getSymbol()               const { return m_symbol; }
    uint32_t          getPrice()                const { return m_price; }
    uint32_t          getQuantity()             const { return m_quantity; }
    uint32_t          getAvgExecutedPrice()     const { return m_avg_executed_price; }
    uint32_t          getExecutedQuantity()     const { return m_executed_quantity; }
    uint32_t          getLastExecutedQuantity() const { return m_last_executed_quantity; }
    uint32_t          getLastExecutedPrice()    const { return m_last_executed_price; }
    uint32_t          getOpenQuantity()         const { return m_open_quantity; }
    Side              getSide()                 const { return m_side; }

private:
    Side          m_side;
    uint64_t      m_order_id;
    std::string   m_trader;
    std::string   m_symbol;
    uint32_t      m_price;
    uint32_t      m_quantity;

    uint32_t      m_open_quantity;
    uint32_t      m_executed_quantity;
    uint32_t      m_last_executed_price;
    uint32_t      m_last_executed_quantity;
    uint32_t      m_avg_executed_price;
};

inline std::ostream& operator<<(std::ostream& ostream, const Order& order)
{
    return ostream
        << "Trader: "        << std::setw(10) << "," << order.m_trader
        << "Side: "          << std::setw(10) << "," << std::to_string(order.getSide())
        << "PRICE: "         << std::setw(10) << "," << order.getPrice()
        << "QUANTITY: "      << std::setw(10) << "," << order.getOpenQuantity()
        << "OPEN QUANTITY: " << std::setw(10) << "," << order.getOpenQuantity();
}
