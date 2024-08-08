struct FenwickTree{
    int n;
    vl b1, b2;

    void init(int _n){
        n = _n;
        b1.resize(n + 1, 0);
        b2.resize(n + 1, 0);
    }
    void point_update(int idx, ll x, vl &b){
        for (int i = idx; i <= n; i += i & -i){
            b[i] += x;
        }
    }
    void update(int l, int r, ll x){
        point_update(l, x, b1);
        point_update(r + 1, -x, b1);
        point_update(l, x * (l - 1), b2);
        point_update(r + 1, -x * r, b2);
    }
    ll sum(int idx, vl &b){
        ll res = 0;
        for (int i = idx; i > 0; i -= i & -i){
            res += b[i];
        } 
        return res;
    }
    ll prefix_sum(int idx){
        return sum(idx, b1) * idx - sum(idx, b2);
    }
    ll query(int l, int r){
        return prefix_sum(r) - prefix_sum(l - 1);
    }
};
