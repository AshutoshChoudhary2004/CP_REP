// can be used for min, max, gcd

template <typename T, T (*func)(T, T)>
struct RMQ{

    int n, logn;
    vector<T> a;
    vector<vector<T>> m;
    void build(){
        fr(i, n) m[i][0] = a[i];
        for (int bit = 1; bit < logn; ++ bit){
            for (int i = 0; i + (1 << bit) - 1 < n; ++ i){
                m[i][bit] = func(m[i][bit - 1], m[i + (1 << (bit - 1))][bit - 1]);
            }
        }
    }

    void init(int _n, vector<T> _a){
        n = _n;
        a = _a;
        logn = ceil(log2(n)) + 1;
        m.resize(n, vector<T>(logn));
        build();
    }

    ll query(int l, int r){
        int len = r - l + 1;
        int val = 31 - __builtin_clz(len);
        return func(m[l][val], m[r - (1 << val) + 1][val]);
    }
};

int func(int a, int b){return max(a, b);}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vi a(m);
    RMQ <int, func> tree;
    tree.init(m, a);
    
}
