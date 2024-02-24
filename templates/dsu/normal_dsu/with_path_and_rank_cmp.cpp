/*

dsu using path and rank compression
time complexity : O(5) for each dsu operation

*/

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
