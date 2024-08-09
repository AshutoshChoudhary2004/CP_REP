struct FenwickTree{
    int n;
    vl b;

    void init(int _n){
        n = _n;
        b.resize(n + 1, 0);
    }
    void update(int idx, ll x){
        for (int i = idx; i <= n; i += i & -i) b[i] += x;
    }
    void set_value(int idx, ll x){
        update(idx, x - query(idx, idx));
    }
    ll sum(int idx){
        ll res = 0;
        for (int i = idx; i > 0; i -= i & -i) res += b[i];
        return res;
    }
    ll query(int l, int r){
        return sum(r) - sum(l - 1);
    }
};
