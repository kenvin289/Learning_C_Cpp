#include <iostream>

// Nếu đã khai báo rồi thì sẽ không cần phải dùng std:: nữa
// ex: std::cout -> cout
using namespace std;

int main()
{
    cout << "Hello World" << endl;
    cout << "Hello Again" << endl;
    cout << "HUHU" << endl;

    int a = 5;
    int b = 6;
    int c = a&b;
    int d = b&a;
    cout << c << endl << d << endl;

    return 1;
}