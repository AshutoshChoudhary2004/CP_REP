/*
Returns value of max flow
Time Complexity : O(E * max_flow)

space : O(V ^ 2)
*/

struct MaxFlow {
    int n;
    vvl c;
    vvi g;
    vector<bool> vis;

    void init(int _n) {
        n = _n;
        c.assign(n, vl(n, 0));
        g.resize(n);
        vis.assign(n, false);
    }

    void add_edge(int u, int v, ll x) {
        c[u][v] += x;
        g[u].pb(v);
        g[v].pb(u);
    }

    ll dfs(int u, ll cur, int t) {
        if (u == t) return cur;
        vis[u] = true;
        for (int v : g[u]){
            if (!vis[v] && c[u][v]) {
                ll val = dfs(v, min(cur, c[u][v]), t);
                if (val > 0) {
                    c[u][v] -= val;
                    c[v][u] += val;
                    return val;
                }
            }
        }
        return 0LL;
    }

    ll max_flow(int s, int t) {
        ll cur = -1;
        ll res = 0;
        fr(i, n){
            get_unique(g[i]); 
        }
        while (cur) {
            cur = dfs(s, INT_MAX, t);
            res += cur;
            fill(all(vis), false);
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    MaxFlow obj;
    obj.init(n);
    fr(i, m){
        int u, v, x;
        cin >> u >> v >> x;
        -- u, -- v;
        obj.add_edge(u, v, x);
    }
    cout << obj.max_flow(0, n - 1);
}
