/*СОЗДАНИЕ ИЕРАРХИИ КЛАССОВ НА ОСНОВЕ АБСТРАКТНОГО
БАЗОВОГО КЛАССА «ГЕОМЕТРИЧЕСКИЙ ОБЪЕКТ» Класс «Куб» (Cub). Создать объект класса и вычислить площадь грани, полную
поверхность объекта, объем
железного куба, используя формулы:

S=a^2, S=4a^2, S =2S+S*/

#include <iostream>
#include <Windows.h>
using namespace std;

class GeometricObject {
public:
   
    virtual int square() = 0;
    virtual int surface_area() = 0;
    virtual int volume() = 0;
};

class Cub : public GeometricObject {
private:
    int a;

public:
   
    Cub(int side) {
        a = side;
    }

    int square() override {
        return a * a;
    }

   
    int surface_area() override {
        return 4 * square();
    }

   
    int volume() override {
        return square() * a;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   
    Cub cube(5);

  
    int face_area = cube.square();
    cout << "Площадь грани: " << face_area << endl;

   
    int surface_area = cube.surface_area();
    cout << "Полная поверхность: " << surface_area << endl;

   
    int volume = cube.volume();
    cout << "Объем: " << volume << endl;

    return 0;
}
