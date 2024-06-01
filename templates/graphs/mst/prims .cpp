/*

1) use init function to specify the total number of nodes
2) use add_edge function to add edges 

get_mst() returns {total weight of mst, edges in the mst}

*/

struct MST{

    int n;
    vector<vpll> g;
    void init(int _n){
        n = _n;
        g.resize(n);
    }
    void add_edge(int u, int v, ll w){
        g[u].pb(mp(v, w));
        g[v].pb(mp(u, w));
    }
    pair<ll, vvl> get_mst(){
        vector<bool> vis(n, false); 
        priority_queue<vl, vvl, greater<vl>> pq;
        pq.push({0, 0, -1});
        ll res = 0;
        vvl ans; 
        while (si(pq)){
            auto x = pq.top(); pq.pop();
            if (vis[x[1]]) continue;
            vis[x[1]] = true;
            if (x[2] != -1) ans.pb({x[2], x[1], x[0]});
            res += x[0];
            for (auto it : g[x[1]]){
                if (!vis[it.F]){
                    pq.push({it.S, it.F, x[1]});
                }
            }
        }
        return mp(res, ans);
    }
};
