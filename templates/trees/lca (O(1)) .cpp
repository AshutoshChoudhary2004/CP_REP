struct RMQ{

    int n, logn;
    vi a;
    vvi m;
    void build(){
        fr(i, n) m[i][0] = i;
        for (int bit = 1; bit < logn; ++ bit){
            for (int i = 0; i + (1 << bit) - 1 < n; ++ i){
                int idx1 = m[i][bit - 1];
                int idx2 = m[i + (1 << (bit - 1))][bit - 1];
                m[i][bit] = a[idx1] < a[idx2] ? idx1 : idx2;
            }
        }
    }

    void init(int _n, vi _a){
        n = _n;
        a = _a;
        logn = ceil(log2(n)) + 1;
        m.resize(n, vi(logn, 0));
        build();
    }

    int query(int l, int r){
        int len = r - l + 1;
        int val = 31 - __builtin_clz(len);
        int idx1 = m[l][val];
        int idx2 = m[r - (1 << val) + 1][val];
        return a[idx1] < a[idx2] ? idx1 : idx2; 
    }
};

struct Tree{
    int n;
    vvi g;
    vi id;
    vi level;
    vi m;
    int cnt;
    bool dfs_done;
    RMQ rmq;
    void init(int _n){
        n = _n;
        g.resize(n);
        m.assign(2 * n - 1, 2 * n);
        id.resize(2 * n - 1);
        level.resize(2 * n - 1);
        cnt = -1;
        dfs_done = false;
    }

    void add_edge(int u, int v){
        g[u].pb(v);
        g[v].pb(u);
    }

    void dfs(int u, int p, int cur){
        level[++ cnt] = cur;
        id[cnt] = u;
        m[u] = min(cnt, m[u]);
        for (int v : g[u]){
            if (v != p){
                dfs(v, u, cur + 1);
                id[++ cnt] = u;
                level[cnt] = cur;
            }
        }
    }
    
    int lca(int u, int v){
        if (!dfs_done){
            dfs(0, -1, 0);
            dfs_done = true;
            rmq.init(2 * n - 1, level);
        }
        if (m[u] > m[v]) swap(u, v);
        return id[rmq.query(m[u], m[v])];
    }
};
