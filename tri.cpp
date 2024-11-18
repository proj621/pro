#include <iostream>

using namespace std;

void findTriangleType(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        cout << "Invalid triangle-> sides must be positive.\n";
        return;
    }
    if (a + b <= c || a + c <= b || b + c <= a) {
        cout << "Invalid triangle->does not satisfy triangle inequality.\n";
        return;
    }
    if (a == b && b == c) {
        cout << "Equilateral triangle\n";
    } else if (a == b || b == c || a == c) {
        cout << "Isosceles triangle\n";
    } else {
        cout << "Scalene triangle\n";
    }
}

int main() {
    double a, b, c;
    cout << "Enter the lengths of the three sides of the triangle: ";
    cin >> a >> b >> c;

    findTriangleType(a, b, c);

    return 0;
}
