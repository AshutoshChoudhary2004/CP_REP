/*

1) use init function to specify the total number of nodes
2) use add_edge function to add edges 

get_mst() returns {total weight of mst, edges in the mst}

*/

struct MST{
    struct DSU {
        vector<int> par, sz;
        
        void init(int n) {
            par.resize(n);
            sz.assign(n, 1);
            for (int i = 0; i < n; i++)
                par[i] = i;
        }

        int find(int x){
            if (x == par[x]) return x;
            return par[x] = find(par[x]);
        } 

        void unite(int x, int y){
            int xx = find(x);
            int yy = find(y);
            if (xx == yy) return;
            if (sz[xx] > sz[yy]) swap(xx, yy);
            par[xx] = yy;
            sz[yy] += sz[xx];
        }
    };

    int n;
    vvl edges;
    DSU dsu;
    void init(int _n){
        n = _n;
        dsu.init(n);
    }
    void add_edge(int u, int v, ll w){
        edges.pb({w, u, v});
    }
    pair<ll, vvl> get_mst(){
        sort(all(edges));
        ll res = 0;
        vvl ans;
        for (auto it : edges){
            if (dsu.find(it[1]) != dsu.find(it[2])){
                res += it[0];
                ans.pb({it[1], it[2], it[0]});
            }
            dsu.unite(it[1], it[2]);
        }
        return mp(res, ans); 
    }
};
