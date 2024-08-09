/*
call start_dfs() to initialize, and call this after adding all the edges
*/

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

struct LCA{
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

struct Tree{
    int n;
    vvi g;
    vi start;
    vi finish;
    int cnt;
    FenwickTree tree;
    LCA tree_lca;

    void init(int _n){
        n = _n;
        g.resize(n);
        tree.init(2 * n); 
        tree_lca.init(n);
        start.resize(n, 0);
        finish.resize(n, 0);
        cnt = -1;
    }   
    void add_edge(int u, int v){
        g[u].pb(v);
        g[v].pb(u);
        tree_lca.add_edge(u, v);
    }
    void dfs(int u, int p){
        start[u] = ++ cnt;
        for (int v : g[u]){
            if (v != p){
                dfs(v, u);
            }
        }
        finish[u] = ++ cnt;
    }
    void start_dfs(int u){
        dfs(u, -1);
    }
    void update_node(int u, ll x){
        tree.update(start[u] + 1, x);
        tree.update(finish[u] + 1, - x);
    }
    void set_value_node(int u, ll x){
        tree.set_value(start[u] + 1, x);
        tree.set_value(finish[u] + 1, -x);
    }
    ll query_path(int u, int v){
        int lca = tree_lca.lca(u, v);
        ll val1 = tree.query(start[0] + 1, start[u] + 1);
        ll val2 = tree.query(start[0] + 1, start[v] + 1);
        ll val3 = tree.query(start[0] + 1, start[lca] + 1); 
        return val1 + val2 - 2 * val3 + tree.query(start[lca] + 1, start[lca] + 1);
    }
};
