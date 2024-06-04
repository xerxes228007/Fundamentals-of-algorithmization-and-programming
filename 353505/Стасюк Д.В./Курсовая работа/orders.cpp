#include "orders.h"
#include <fstream>

Orders::Orders() {}

Order Orders::parse_record(std::string str) {
    std::vector<std::string> vect;
    std::string delimiter = ";";

    std::stringstream ss(str);
    size_t pos = 0;
    std::string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        vect.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    Order o;
    o.id = vect[0];
    o.customerName = vect[1];
    o.modelPath  = vect[2];
    o.material = vect[3];
    o.price = std::stoi(vect[4]);
    o.volume = std::stof(vect[5]);
    o.date = QDate::fromString(QString::fromStdString(vect[6]),"yyyy-MM-dd");

    return o;
}

void Orders::load_from_file(QString file_path) {
    d.clear();
    std::ifstream infile(file_path.toStdString());
    std::string line;
    while (std::getline(infile, line))
    {
        d.push_back(parse_record(line));
    }
}
