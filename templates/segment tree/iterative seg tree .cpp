/*
this code is for max, to change:
  change func on line 7
  change default value on line 9
*/
ll func(ll a, ll b){
    return max(a, b);
}
ll default_value = -(ll)(1e18);

struct SegmentTree{
    int n;
    vl seg;

    void init(int _n){
        n = _n;
        seg.resize(2 * n, 0); 
    }
    void update(int i, ll val){
        i += n;
        seg[i] += val; 
        while ((i >>= 1) > 0){
            seg[i] = func(seg[i << 1], seg[i << 1 | 1]);
        }
    }
    ll query(int l, int r){
        ll res = default_value;
        l += n;
        r += n;
        while (l <= r){
            if (l & 1){
                res = func(res, seg[l ++]);
            }
            if (r % 2 == 0){
                res = func(res, seg[r --]);
            }
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
    void set_value(int i, ll val){
        update(i, val - query(i, i));
    }
};
