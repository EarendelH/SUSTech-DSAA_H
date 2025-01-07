#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

double f(double x, double a, double b, double c, double d) {
    return a * x + b * log(x) - c / x + d;
}

int main() {
    double y, a, b, c, d;
    cin >> y >> a >> b >> c >> d;

    double left = 1, right = 1e9;
    double gap = 1e-7;
    int L = -1, R = -1;
    bool flag = false;

    while (right - left > gap) {
        double mid = (left + right) / 2;
        double res = f(mid, a, b, c, d);
        if (fabs(res - y) < gap) {
            flag = true;
            L = static_cast<int>(mid * 100);
            R = L + 1;
            break;
        }
        if (res > y) {
            right = mid;
        } else {
            left = mid;
        }
    }
    if(a==0&&b==0&&c==0&&y==d)
    {
        cout<<"NOT UNIQUE"<<endl;
        return 0;
    }

    if (!flag) {
        cout << "NO ANSWER" << endl;
    } else {
        cout << L << endl;
    }

    return 0;
}