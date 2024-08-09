/*
call start_dfs() to initialize, and call this after adding all the edges
*/

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
    vi level;
    vvi p;
    int logn;

    void init(int _n){
        n = _n;
        g.resize(n);
        tree.init(2 * n); 
        start.resize(n, 0);
        finish.resize(n, 0);
        level.resize(n, 0);
        logn = ceil(log2(n)) + 1;
        p.assign(n, vi(logn, -1));
        cnt = -1;
    }   
    void add_edge(int u, int v){
        g[u].pb(v);
        g[v].pb(u);
    }
    void dfs(int u){
        start[u] = ++ cnt;
        for (int v : g[u]){
            if (v != p[u][0]){
                level[v] = level[u] + 1;
                p[v][0] = u;
                dfs(v);
            }
        }
        finish[u] = ++ cnt;
    }
    int lca(int u, int v){
        if (level[u] < level[v]) swap(u, v);
        int dif = level[u] - level[v];
        fr(i, logn){
            if (dif & (1 << i)) u = p[u][i];
        }
        if (u == v) return u;
        for (int i = logn - 1; i >= 0; -- i){
            if (p[u][i] != p[v][i]){
                u = p[u][i];
                v = p[v][i];
            }
        }
        return p[u][0];
    }
    void start_dfs(int x){
        dfs(x);
        for (int i = 1; i < logn; ++ i){
            fr(u, n){
                int par = p[u][i - 1];
                p[u][i] = par != -1 ? p[par][i - 1] : -1;
            }
        }
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
        int par = lca(u, v);
        ll val1 = tree.query(start[0] + 1, start[u] + 1);
        ll val2 = tree.query(start[0] + 1, start[v] + 1);
        ll val3 = tree.query(start[0] + 1, start[par] + 1); 
        return val1 + val2 - 2 * val3 + tree.query(start[par] + 1, start[par] + 1);
    }
};
