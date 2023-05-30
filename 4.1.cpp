/*Создать базовый класс «Вектор на плоскости». Элементы класса: поля,
задающие координаты точки (статус доступа protected), определяющей конец
вектора (начало вектора находится в точке с координатами 0; 0); конструктор
для инициализации полей; функция для вычисления длины вектора, функция
для печати полей и длины вектора. Создать производный класс «Вектор в
трехмерном пространстве». Элементы класса: дополнительное поле, задающее
дополнительную координату; конструктор для инициализации полей;
переопределенная функция для вычисления длины вектора; переопределенная
функция для печати полей и длины вектора. Создать по одному объекту
каждого из классов. Показать вызов созданных функций. При переопределении
функций обеспечить*/
#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

class Vector2D {
protected:
    double x, y;
public:
    Vector2D(double _x, double _y) : x(_x), y(_y) {}
    double length() const {
        return sqrt(x * x + y * y);
    }
    void print() const {
        cout << "Координаты: (" << x << ", " << y << ")" << endl;
        cout << "Длина вектора: " << length() << endl;
    }
};

class Vector3D : public Vector2D {
private:
    double z;
public:
    Vector3D(double _x, double _y, double _z) : Vector2D(_x, _y), z(_z) {}
    double length() const {
        return sqrt(x * x + y * y + z * z);
    }
    void print() const {
        cout << "Координаты: (" << x << ", " << y << ", " << z << ")" << endl;
        cout << "Длина вектора: " << length() << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Vector2D vec2d(3, 4);
    vec2d.print();

    Vector3D vec3d(1, 2, 3);
    vec3d.print();

    return 0;
}