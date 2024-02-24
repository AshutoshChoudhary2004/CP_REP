struct DSU {
    vector<int> par, sz
    vector<ll> d;
    
    void init(int n) {
        par.resize(n);
        sz.assign(n, 1);
        d.assign(n, 0LL);
        for (int i = 0; i < n; i++)
            par[i] = i;
    }
    
    int find(int x) {
        if (x == par[x])
            return x;
        int p = find(par[x]);
        d[x] += d[par[x]];
        par[x] = p;
        return p;
    }
    //returns true if the given relation is valid / consistent
    bool unite(int x, int y, ll r) {
        int xx = find(x);
        int yy = find(y);
        if (xx == yy) {
            //we already have a relation return true if the ans for x, y matches r
            return d[x] - d[y] == r;
        }
        if (sz[xx] > sz[yy]) {
            swap(x, y), swap(xx, yy);
            //write code to
            //change the value of r, acc to the question, i.e relation
            //was given for u -> v, what will will be the relation for v -> u
        }
        par[xx] = yy;
        d[xx] = r + d[y] - d[x];
        sz[yy] += sz[xx]; 
        return true;
    }
};
