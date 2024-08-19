// can be used for min, max, gcd

struct RMQ{

    int n, logn;
    vl a;
    vvl m;
    void build(){
        fr(i, n) m[i][0] = a[i];
        for (int bit = 1; bit < logn; ++ bit){
            for (int i = 0; i + (1 << bit) - 1 < n; ++ i){
                m[i][bit] = min(m[i][bit - 1], m[i + (1 << (bit - 1))][bit - 1]);
            }
        }
    }

    void init(int _n, vl _a){
        n = _n;
        a = _a;
        logn = ceil(log2(n)) + 1;
        m.resize(n, vl(logn, 0));
        build();
    }

    ll query(int l, int r){
        int len = r - l + 1;
        int val = 31 - __builtin_clz(len);
        return min(m[l][val], m[r - (1 << val) + 1][val]);
    }
};
