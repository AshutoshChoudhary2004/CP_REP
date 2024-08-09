struct FenwickTree{
    
    int n;
    vl b;

    void init(int _n){
        n = _n;
        b.resize(n + 1, 0);
    }
    void point_update(int ind, ll val){
        for (int i = ind; i <= n; i += i & -i){
            b[i] += val;
        }
    }
    void update(int l, int r, ll x){
        point_update(l + 1, x);
        point_update(r + 1 + 1, -x);
    }
    ll query(int idx){
        ll res = 0;
        for (int i = idx + 1; i > 0; i -= i & -i){
            res += b[i];
        }
        return res;
    }
    void set_value(int idx, ll val){
        update(idx, idx, val - query(idx));
    }
};
