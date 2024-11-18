#include <iostream>
#include <cmath>

using namespace std;

void findRoots(double a, double b, double c) {
    if (a == 0) {
        cout << "Not a quadratic equation (a must be non-zero).\n";
        return;
    }

    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Two distinct real roots: " << root1 << " and " << root2 << "\n";
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        cout << "One real root: " << root << "\n";
    } else {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << "Two complex roots: " << realPart << " ± " << imaginaryPart << "i\n";
    }
}

int main() {
    double a, b, c;
    cout << "Enter coefficients a, b, and c for the quadratic equation (ax^2 + bx + c = 0): ";
    cin >> a >> b >> c;

    findRoots(a, b, c);

    return 0;
}
