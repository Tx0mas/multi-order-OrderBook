enum class Side
{
    BUY,
    SELL,
    NONE,
};

struct orderType
{
    double price{};
    int id{};
    Side side{};
    int quantity{};
    int remainder{};

    orderType(double p, int i, Side s, int q, int r)
    :price{p},id{i},side{s},quantity{q},remainder{r}
    {}
    orderType()
    :price{},id{},side{Side::NONE},quantity{},remainder{}
    {}
};

