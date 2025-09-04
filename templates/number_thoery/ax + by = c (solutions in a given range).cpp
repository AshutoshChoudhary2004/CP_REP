/*

1. this gives the count of solutions in the given range
2. and to find the solutions use range of minK and maxK

*/

ll floor_div(ll x, ll y) {
    assert(y != 0);
    if (y < 0) {
        y = -y;
        x = -x;
    }
    if (x >= 0) return x / y;
    return (x - y + 1) / y;
}

ll ceil_div(ll x, ll y) {
    assert(y != 0);
    if (y < 0) {
        y = -y;
        x = -x;
    }
    if (x >= 0) return (x + y - 1) / y;
    return x / y;
}

void ashuhua() {
    ll a, b, c, x1, x2, y1, y2;
    cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
    c *= -1;
    if (a == 0 || b == 0){
        if (a == 0 && b == 0) cout << (c == 0 ? (x2 - x1 + 1) * (y2 - y1 + 1) : 0);
        else if (a == 0) cout << (c % b == 0 && c / b >= y1 && c / b <= y2);
        else if (b == 0) cout << (c % a == 0 && c / a >= x1 && c / a <= x2);
        return;
    }
    ll g, x0, y0;
    auto getSolution = [&](){
        auto gcd = [&](auto&& gcd, ll a, ll b, ll& x0, ll& y0) -> ll  {
            if (b == 0){
                x0 = 1;
                y0 = 0;
                return a;
            }
            ll x1, y1;
            ll g = gcd(gcd, b, a % b, x1, y1);
            x0 = y1;
            y0 = x1 - (a / b) * y1;
            return g;
        };
        g = gcd(gcd, abs(a), abs(b), x0, y0);
        if (c % g) return false;
        x0 *= c / g;
        y0 *= c / g;
        if (a < 0) x0 *= -1;
        if (b < 0) y0 *= -1;
        return true;
    };
    if (!getSolution()){
        cout << 0;
        return;
    }
    auto get = [&](ll x, ll b, ll mn, ll mx) -> vl {
        ll val1 = mn - x, val2 = mx - x;
        if (b > 0) {
            return {ceil_div(val1, b), floor_div(val2, b)}; 
        } else {
            return {ceil_div(val2, b), floor_div(val1, b)};
        }
    };  
    vl res1 = get(x0, b / g, x1, x2);
    vl res2 = get(y0, - a / g, y1, y2);
    cout << max(0LL, min(res2[1], res1[1]) - max(res2[0], res1[0]) + 1);
}

