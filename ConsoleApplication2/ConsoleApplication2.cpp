#include <iostream>
#include <cmath>

using namespace std;

class vector3D
{
private:
    double x, y, z;

public:
    // 1. Конструктор без параметрів
    vector3D()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    // 2. Конструктор з трьома параметрами
    vector3D(double x1, double y1, double z1)
    {
        x = x1;
        y = y1;
        z = z1;
    }

    // 3. Конструктор копіювання
    vector3D(const vector3D& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
    }

    // Виведення координат вектора
    void print() const
    {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }

    // Додавання векторів
    vector3D operator+(const vector3D& v) const
    {
        return vector3D(x + v.x, y + v.y, z + v.z);
    }

    // Віднімання векторів
    vector3D operator-(const vector3D& v) const
    {
        return vector3D(x - v.x, y - v.y, z - v.z);
    }

    // Скалярний добуток двох векторів
    double operator*(const vector3D& v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }

    // Множення вектора на скаляр
    vector3D operator*(double k) const
    {
        return vector3D(x * k, y * k, z * k);
    }

    // Порівняння векторів
    bool operator==(const vector3D& v) const
    {
        return x == v.x && y == v.y && z == v.z;
    }

    bool operator!=(const vector3D& v) const
    {
        return !(*this == v);
    }

    // Обчислення довжини вектора
    double length() const
    {
        return sqrt(x * x + y * y + z * z);
    }

    // Порівняння довжин векторів
    bool operator>(const vector3D& v) const
    {
        return length() > v.length();
    }

    bool operator<(const vector3D& v) const
    {
        return length() < v.length();
    }

    bool operator>=(const vector3D& v) const
    {
        return length() >= v.length();
    }

    bool operator<=(const vector3D& v) const
    {
        return length() <= v.length();
    }
};

// Множення скаляра на вектор
vector3D operator*(double k, const vector3D& v)
{
    return v * k;
}

int main()
{
    // Створення векторів за допомогою різних конструкторів
    vector3D A;              // конструктор без параметрів
    vector3D B(3, 4, 5);     // конструктор з параметрами
    vector3D C(B);           // конструктор копіювання

    cout << "Vector A = ";
    A.print();
    cout << endl;

    cout << "Vector B = ";
    B.print();
    cout << endl;

    cout << "Vector C = ";
    C.print();
    cout << endl;

    // Додавання
    vector3D D = B + C;

    cout << "\nB + C = ";
    D.print();
    cout << endl;

    // Віднімання
    vector3D E = B - C;

    cout << "B - C = ";
    E.print();
    cout << endl;

    // Скалярний добуток
    double scalarProduct = B * C;

    cout << "B * C (scalar product) = ";
    cout << scalarProduct << endl;

    // Множення на скаляр
    vector3D F = B * 2;

    cout << "B * 2 = ";
    F.print();
    cout << endl;

    // Довжина вектора
    cout << "\nLength of B = ";
    cout << B.length() << endl;

    cout << "Length of C = ";
    cout << C.length() << endl;

    // Порівняння векторів
    cout << "\nComparison of vectors B and C:" << endl;

    if (B == C)
        cout << "B and C are equal." << endl;
    else
        cout << "B and C are not equal." << endl;

    // Порівняння довжин
    cout << "\nComparison of vector lengths:" << endl;

    if (B > C)
        cout << "Length of B is greater than length of C." << endl;
    else if (B < C)
        cout << "Length of B is smaller than length of C." << endl;
    else
        cout << "Lengths of B and C are equal." << endl;

    return 0;
}