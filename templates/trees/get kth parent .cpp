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
    }

    void add_edge(int u, int v){
        g[u].pb(v);
        g[v].pb(u);
    }

    void dfs(int u){
        for (int v : g[u]){
            if (v != p[u][0]){
                p[v][0] = u;
                dfs(v);
            }
        }
    }

    int get_kth_parent(int u, int k){
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
        fr(i, logn){
            if (k & (1 << i)){
                if (u != -1){
                    u = p[u][i];
                }
            }
        }
        return u;
    }

}; 
