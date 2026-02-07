#include<queue>
#include<map>
#include<iostream>
#include"orderType.hpp"



class OrderBook
{
private:
    std::map<double,std::queue<orderType>> m_asks{}; //venta
    std::map<double,std::queue<orderType>,std::greater<double>> m_bids{}; //compra
public:

    void newOrder(orderType &order);
    void findBuy(orderType &order);
    void findSell(orderType &order);
    void printBook();

    int getQuantity(orderType &order) {return order.quantity;}
    int getRemainder(orderType &order) {return order.remainder;}

    std::map<double,std::queue<orderType>> getAsks() {return m_asks;}
    std::map<double,std::queue<orderType>,std::greater<double>> getBids() {return m_bids;}



};

