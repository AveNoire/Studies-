#include <iostream>
#include <string>

class Tiles {
public:
    std::string brand;
    double size_h;
    double size_w;
    double price;

    void getData() {
        std::cout << "Бренд  " << brand << "  Высота  " << size_h << "  Ширина  " << size_w << "  Цена  " << price << std::endl;
    };


};

int main()
{
    setlocale(LC_ALL, "rus");
    Tiles one;
    one.brand = "Creto";
    one.size_h = 0.2;
    one.size_w = 2.4;
    one.price = 3.5;
    one.getData();

    Tiles two;
    two.brand = "KERAMA MARAZZI";
    two.size_h = 0.3;
    two.size_w = 2.8;
    two.price = 3.6;
    two.getData();
}
