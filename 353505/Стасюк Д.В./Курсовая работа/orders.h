#ifndef ORDERS_H
#define ORDERS_H
#include "QtCore"
#include <vector>

struct Order {
    std::string id;
    std::string customerName;
    std::string modelPath;
    std::string material;
    int price;
    float volume;
    QDate date;
};

class Orders
{
private:
    Order parse_record(std::string str);

public:
    Orders();
    std::vector<Order> d;
    void load_from_file(QString file_path);
};

#endif // ORDERS_H
