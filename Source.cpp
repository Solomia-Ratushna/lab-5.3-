#include <iostream>
#include <cmath>
using namespace std;
double h(const double x);
int main()
{
    double rp, rk, z;
    int n;
    cout << "rp = "; cin >> rp;
    cout << "rk = "; cin >> rk;
    cout << "n = "; cin >> n;
    double dr = (rk - rp) / n;
    double r = rp;
    while (r <= rk)
    {
        z = h(1 + sqrt(r)) + pow(h(1 + r + h(r) * h(r)), 2);
        cout << r << " " << z << endl;
        r += dr;
    }
    return 0;
}
double h(const double x)
{
    if (abs(x) >= 1)
        return (1 + cos(x)) / (exp(-2.0 * x));
    else
    {
        double S = 0;
        int n = 0;
        double a = x;
        S = a;
        do
        {
            n++;
            double R = (x * x * x * 1.0) / (27.0 * n * n * n * 1.0 - 3.0 * n);
            a *= R;
            S += a;
        } while (n < 5);
        return S;
    }
}