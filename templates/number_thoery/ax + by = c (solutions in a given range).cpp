/*

1. this gives the count of solutions in the given range
2. and to find the solutions use range of minK and maxK

*/
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll gcd(ll a, ll b, ll &x0, ll &y0){

    if (b == 0){
        x0 = 1;
        y0 = 0;
        return a;
    }
    ll x1, y1;
    ll g = gcd(b, a % b, x1, y1);
    x0 = y1;
    y0 = x1 - (a / b) * y1;
    return g;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g){

    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) return false;
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 *= -1;
    if (b < 0) y0 *= -1;
    return true;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll ans = 0;
    ll a, b, c, x1, x2, y1, y2, g, x0, y0;
    cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
    c *= -1;
    if (!a && !b){
        if (!c) ans = (x2-x1+1) * (y2-y1+1);
    } 
    else if (!a){
        ans = !(c % b) && c / b >= y1 && c / b <= y2;
    }
    else if (!b){
        ans = !(c % a) && c / a >= x1 && c / a <= x2;
    }
    else if (find_any_solution(a, b, c, x0, y0, g)){
        ll mink1, maxk1, mink2, maxk2;
        if (b > 0){
            mink1 = ceil((x1 - x0) * 1.0 * g / b);
            maxk1 = floor((x2 - x0) * 1.0  * g / b);
        }else{
            mink1 = ceil((x2 - x0) * 1.0  * g / b);
            maxk1 = floor((x1 - x0) * 1.0 * g / b);
        }
        if (a > 0){
            maxk2 = floor(-1 * (y1 - y0) * 1.0 * g / a);
            mink2 = ceil(-1 * (y2 - y0) * 1.0 * g / a);
        }else{
            mink2 = ceil(-1 * (y1 - y0) * 1.0 * g / a);
            maxk2 = floor(-1 * (y2 - y0) * 1.0 * g / a);
        }
        ll mink = max(mink1, mink2);
        ll maxk = min(maxk1, maxk2);
        if (mink <= maxk) ans = maxk - mink + 1;
    }
    cout << ans << "\n";
}   
