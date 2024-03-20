/*
Returns value of max flow
Time Complexity : O(E * max_flow)

uses adjacency matrix
*/

struct MaxFlow {
    int n;
    vector<vector<ll>> g;
    vector<bool> vis;

    void init(int _n) {
        n = _n;
        g.assign(n, vector<ll>(n, 0));
        vis.assign(n, false);
    }

    void add_edge(int u, int v, ll x) {
        g[u][v] += x;
    }

    ll dfs(int u, ll cur) {
        if (u == n - 1) return cur;
        vis[u] = true;
        for (int v = 0; v < n; ++v) {
            if (!vis[v] && g[u][v]) {
                ll val = dfs(v, min(cur, g[u][v]));
                if (val > 0) {
                    g[u][v] -= val;
                    g[v][u] += val;
                    return val;
                }
            }
        }
        return 0LL;
    }

    ll max_flow() {
        ll cur = -1;
        ll res = 0;
        while (cur) {
            cur = dfs(0, INT_MAX);
            res += cur;
            fill(vis.begin(), vis.end(), false);
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
    cout << obj.max_flow();
}
