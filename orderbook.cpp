#include"orderbook.hpp"


void OrderBook::newOrder(orderType &order)
{
    if (order.side == Side::BUY)
    {
        m_bids[order.price].push(order);
    }
    else if (order.side == Side::SELL)
    {
        m_asks[order.price].push(order);
    }
}

void OrderBook::findBuy(orderType &order)
{
    while (!m_asks.empty() && m_asks.begin()->first<=order.price && order.remainder>0)
    {
        auto ordenAsksMin = m_asks.begin();
        auto &queueAsksMin = ordenAsksMin->second;
        //enocontro una cola de ordenes posible.
        //toqueteamos el remainder de las ordenes tanto de compra como de venta.
        while(!queueAsksMin.empty() && order.remainder>0) 
        {
            if (queueAsksMin.front().remainder >= order.remainder)
            {
                queueAsksMin.front().remainder-=order.remainder;
                order.remainder = 0; //para brekear y actualizar la orden de compra.
            }
            else
            {
                order.remainder-=queueAsksMin.front().remainder;
                queueAsksMin.pop();
            }
        }
        if (queueAsksMin.empty())
        {
            m_asks.erase(ordenAsksMin);
        }
    }
    if (order.remainder > 0)
    {
        //aun quiere seguir comprando pero no hay ninguna para el,
        //asi que pongo su orden en bids denuevo.
        m_bids[order.price].push(order);
    }
}


void OrderBook::findSell(orderType &order)
{
    //busco al comprador que compra mas caro.
    auto bidsOrder = m_bids.begin(); //(esta de mayor a menor)
    auto &queueBidsOrder = bidsOrder->second;
    while (!m_bids.empty() && m_asks.end()->first>=order.price && order.remainder>0)
    {
        auto selledOrder = queueBidsOrder.front();

        while(!queueBidsOrder.empty() && order.remainder>0) 
        {
            if (selledOrder.remainder >= order.remainder)
            {
                queueBidsOrder.pop();
                order.remainder=0;
            }
            else
            {
                order.remainder-=selledOrder.remainder;
                queueBidsOrder.pop();
            }
        }
        if (queueBidsOrder.empty())
        {
            m_bids.erase(bidsOrder);
        }
    }
    if (order.remainder>0)
    {
        m_asks[order.price].push(order);
    }
}

    
void OrderBook::printBook()
{
    std::cout<<'\n';
    std::cout<<"==========ASKS=========="<<'\n';
    for (auto &val : getAsks())
    {
        std::cout<<"PRECIO: "<<val.first<<" REMAINDER (FIRSTQ): "<<val.second.front().remainder<<'\n';
    }
    std::cout<<'\n';
    std::cout<<"==========BIDS=========="<<'\n';
    for (auto &val : getBids())
    {
        std::cout<<"PRECIO: "<<val.first<<" REMAINDER (FIRSTQ): "<<val.second.front().remainder<<'\n';
    }
    std::cout<<'\n';
    std::cout<<'\n';
}



