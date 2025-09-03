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


#include <bits/stdc++.h>
using namespace std;

int gcdExtended(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int x1, y1;
    int g = gcdExtended(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

bool findAnySolution(int a, int b, int c, int &x, int &y, int &g) {
    g = gcdExtended(abs(a), abs(b), x, y);
    if (c % g != 0) return false;
    x *= c / g;
    y *= c / g;
    if (a < 0) x = -x;
    if (b < 0) y = -y;
    return true;
}

vector<pair<int,int>> findNSolutions(int a, int b, int c, int n) {
    int x0, y0, g;
    vector<pair<int,int>> sols;
    if (!findAnySolution(a, b, c, x0, y0, g)) return sols;

    for (int k = 0; k < n; k++) {
        long long x = x0 + 1LL * k * (b / g);
        long long y = y0 - 1LL * k * (a / g);
        sols.push_back({x, y});
    }
    return sols;
}

int main() {
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    auto sols = findNSolutions(a, b, c, n);
    if (sols.empty()) {
        cout << "No solution\n";
    } else {
        for (auto &p : sols) cout << p.first << " " << p.second << "\n";
    }
}
