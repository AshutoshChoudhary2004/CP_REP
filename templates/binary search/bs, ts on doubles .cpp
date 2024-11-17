//binary search

ld s = 0, e = 1e18, res = a[0];
ld val = (ld)1e-10;
while(s <= e){
    ld m = (s + e) * 1.0 / 2;
    auto cur = ok(m);
    if (cur.F >= cur.S){
        e = m - val;
        res = cur.F;
    }else s = m + val;
}
 cout << fixed << setprecision(12) << res << "\n";

//parabola

ld s = 0, e = 1e9, res = 1e18;

ld val = (ld)1e-10;

while(s <= e){

    ld m = (s + e) * 1.0 / 2;
    ld cur = get(m);
    
    if (cur <= get(m - val * 10)){
        res = m;
        s = m + val;
    }else e = m - val;

}

cout << fixed << setprecision(12) << res << "\n";
