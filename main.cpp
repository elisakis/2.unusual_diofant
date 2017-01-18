#include <iostream>
#include <cmath>

using namespace std;

//поиск НОД (наибольшего общего делителя) по расширенному алгоритму Евклида
int gcd (int a, int b, int & x, int & y)
{
    if (a == 0)
    {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

void unusual_diofant(int a, int b, int c)
{
    //a*x + b*y = c
    if(a == 0 && b == 0)
    {
        if(c == 0)
            cout << "inf";
        else
            cout << "none";
        return;
    }

    if (a == 0 && b != 0)
        swap(a, b);

    if (b == 0)
    {
        // a*x + 0*y = c;  любой y
        if (c%a == 0 && c / a > 0)
            cout << "inf";
        else
            cout << "none";
        return;
    }

    if (a < 0 && b < 0)
    {
        a *= -1;
        b *= -1;
        c *= -1;
    }

    if (a < 0 && b > 0)
        swap(a, b);

    int x, y, g = gcd(a, b, x, y);
    // a*x + b*y = g; a > 0
    if (c % g != 0)
    {
        cout << "none";
        return;
    }

    int k = c/g;
    // одно решение: a*x*k + b*y*k = c
    x *= k; y *= k;

    // a*(x + b/g) + b*(y - a/g) = c;
    int p1 = b / g, p2 = -a / g;

    if (p1 > 0 && p2 > 0)
    {
        cout << "inf";
        return;
    }

    if (x < 0)
    {
        if (p1 < 0)
        {
            p1 *= -1;
            p2 *= -1;
        }
        while (x < 0)
        {
            x += p1;
            y += p2;
        }
    }

    if (y < 0)
    {
        if (p2 < 0)
        {
            p1 *= -1;
            p2 *= -1;
        }
        while (y < 0)
        {
            x += p1;
            y += p2;
        }
    }

    if (x < 0 || y < 0)
    {
        cout << "none";
        return;
    }

    while (x > 0 && y > 0)
    {
        cout << x << ' ' << y << endl;
        x += p1;
        y += p2;
    }
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    unusual_diofant(a, b, c);
    return 0;
}
