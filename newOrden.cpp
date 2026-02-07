#include"orderbook.hpp"

void newOrder(int actualId)
{
    OrderBook orderBook{};
    while (true)
    {
        std::cout<<"Quiere vender o comprar?"<<'\n';
        std::cout<<"1. Comprar"<<'\n';
        std::cout<<"2. Vender"<<'\n';
        std::cout<<"3. Ver book"<<'\n';
        std::cout<<"4. Cerrar"<<'\n';

        int opcion{};
        std::cin>>opcion;

        if (opcion == 1)
        {
            std::cout<<"Inserte precio y cantidad en ese orden separados."<<'\n';
            double precio{};
            int cantidad{};
            std::cin>>precio>>cantidad;
            orderType orden{precio,actualId,Side::BUY,cantidad,cantidad};
            actualId+=1;
            orderBook.findBuy(orden);

        }
        else if (opcion == 2)
        {
            std::cout<<"Inserte precio y cantidad en ese orden separados."<<'\n';
            double precio{};
            int cantidad{};
            std::cin>>precio>>cantidad;
            orderType orden{precio,actualId,Side::SELL,cantidad,cantidad};
            actualId+=1;
            orderBook.findSell(orden);
        }
        else if (opcion == 3)
        {
            orderBook.printBook();
        }
        else if (opcion == 4)
        {
            std::cout<<'\n';
            std::cout<<"Hasta luego.."<<'\n';
            break;
        }
        else
        {
            std::cout<<"Inserte una opcion valida.."<<'\n';
        }
    }
    return;
}

