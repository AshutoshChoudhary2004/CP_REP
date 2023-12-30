/*

## IMP POINTS : 

1) does not work when a or b == 0
2) works for even negative values of a and b 


## HOW TO USE

if x, y are the solutions then all infinite solutions are  
x0, yo and g(gcd) can be declared as variables and passed to the function (find any solution)

x = x0 + k * (b / g)
y = y0 - k * (a / g)


 and k can be -inf to inf
*/


/////////////////////////////////////////////////////////////////////////////
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
/////////////////////////////////////////////////////////////////////////////
