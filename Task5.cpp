#include <cmath>
#include <ctime>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;//стандартное пространство имен
class Exc1 {

};
class Exc2
{
private:
    std::string m_error;

public:
    Exc2(std::string error)
        : m_error(error)
    {
    }

    const char* getError() { return m_error.c_str(); }
};
class Exc3 :public std::invalid_argument {
public:
    float x;
    float  y;
    Exc3(string str, float a, float b) :invalid_argument(str) {
        x = a;
        y = b;
    }

};
float func1(float x1, float y1, float a, float b, float c) {
    float d = abs(a * x1 + b * y1 + c) / pow(a * a + b * b, 0.5);
    return d;
}
float func2(float x1, float y1, float a, float b, float c) {
    if (a == 0 && b == 0)
        throw - 1;
    float d = abs(a * x1 + b * y1 + c) / pow(a * a + b * b, 0.5);
    return d;
}
float func3(float x1, float y1, float a, float b, float c) {
    if (a == 0 && b == 0)
        throw std::invalid_argument("a and b are null");
    float d = abs(a * x1 + b * y1 + c) / pow(a * a + b * b, 0.5);
    return d;
}
float func4(float x1, float y1, float a, float b, float c) {
    if (a == 0 && b == 0)
        throw Exc1();
    float d = abs(a * x1 + b * y1 + c) / pow(a * a + b * b, 0.5);
    return d;
}
float func5(float x1, float y1, float a, float b, float c) {
    if (a == 0 && b == 0)
        throw Exc2("a and b are null");
    float d = abs(a * x1 + b * y1 + c) / pow(a * a + b * b, 0.5);
    return d;
}
float func6(float x1, float y1, float a, float b, float c) {
    if (a == 0 && b == 0)
        throw Exc3("a and b are null", x1, y1);
    float d = abs(a * x1 + b * y1 + c) / pow(a * a + b * b, 0.5);
    return d;
}
int main() {
    setlocale(LC_ALL, "Russian");//русский в консоли
    float x, y, a, b, c;
    cout << "введите x,y, a,b,c: " << endl;
    cin >> x >> y >> a >> b >> c;
    cout << func1(x, y, a, b, c) << endl;
    try {
        cout << func2(x, y, a, b, c) << endl;
    }
    catch (int e) {
        cout << "exception " << e << endl;
    }
    try {
        cout << func3(x, y, a, b, c) << endl;
    }
    catch (std::invalid_argument e) {
        cout << "exception " << e.what() << endl;
    }
    try {
        cout << func4(x, y, a, b, c) << endl;
    }
    catch (Exc1 e) {
        cout << "exception " << endl;
    }
    try {
        cout << func5(x, y, a, b, c) << endl;
    }
    catch (Exc2 e) {
        cout << "exception " << e.getError() << endl;
    }
    try {
        cout << func6(x, y, a, b, c) << endl;
    }
    catch (Exc3 e) {
        cout << "exception " << e.what() << endl;
    }
    return 0;
} 