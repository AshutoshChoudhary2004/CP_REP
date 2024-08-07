struct Tree{

    int n, logn;
    vvi g;
    vvi p;
    vi level;
    bool dfs_done;

    void init(int _n){
        n = _n;
        logn = ceil(log2(n)) + 1;
        g.resize(n);
        p.resize(n, vi(logn, -1));
        dfs_done = false;
        level.resize(n, 0);
    }

    void add_edge(int u, int v){
        g[u].pb(v);
        g[v].pb(u);
    }

    void dfs(int u){
        for (int v : g[u]){
            if (v != p[u][0]){
                p[v][0] = u;
                level[v] = level[u] + 1; 
                dfs(v);
            }
        }
    }

    int lca(int u, int v){
        if (!dfs_done){
            dfs(0);
            dfs_done = true;
            for(int i = 1; i < logn; ++ i){
                fr(u, n){
                    int par = p[u][i - 1];
                    p[u][i] = par != -1 ? p[par][i - 1] : -1;
                }
            }
        }

        if (level[u] < level[v]) swap(u, v);
        int dif = level[u] - level[v];
        fr(i, logn){
            if (dif & (1 << i)){
                u = p[u][i];
            }
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

}; 
