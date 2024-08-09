/*

  call decompose(0) to start
  size is passed as arg to solve tree function, which is the current size of the tree (component sizse)
  whose root we assume as centroid (u) and do a dfs to all nodes
  this dfs takes O(size) time
  the space used in solve_tree or dfs should not be more than component sizes

  to calculate stuff, do a dfs from solve_tree and find answser
  
  WHERE TO MAKE CHANGES : 
    - solve_tree func on line 43
    - dfs func on line 39
*/

int n;
const int N = 2e5 + 10;
vi g[N];
bool dead[N];
int sz[N];

void get_size(int u, int p = -1){
    sz[u] = 1;
    for (int v : g[u]){
        if (v != p && !dead[v]){
            get_size(v, u);
            sz[u] += sz[v];
        }
    }
}

int find_centroid(int u,int p, int size){
    for (int v : g[u]){
        if (!dead[v] && v != p && sz[v] > size / 2) return find_centroid(v, u, size);
    }
    return u;
}

void dfs(int u, int p){
    
}

ll solve_tree(int u, int size){
    //here size is the size of this current tree which we considered to be rooted at
    //centroid u
    // use this function to do a dfs from centroid to all nodes

    ll res = 0;
    for (int v : g[u]){
        if (!dead[v]){
            //call dfs on adjacent nodes of centroid
            dfs(v, u);
        }
    }
    return res;
}

ll decompose(int u){

    //this function calculates centroid then finds the answer for centroid and then 
    //decomposes the tree

    get_size(u);
    int centroid = find_centroid(u, -1, sz[u]);
    ll res = solve_tree(centroid, sz[u]);
    dead[centroid] = true;
    for (int v : g[centroid]){
        if (!dead[v]){
            res += decompose(v);
        }
    }
    return res;
}


//Example code to find count of all paths of length k

int n, k;
const int N = 2e5 + 10;
vi g[N];
bool dead[N];
int sz[N];
void get_size(int u, int p = -1){
    sz[u] = 1;
    for (int v : g[u]){
        if (v != p && !dead[v]){
            get_size(v, u);
            sz[u] += sz[v];
        }
    }
}
int find_centroid(int u,int p, int size){
    for (int v : g[u]){
        if (!dead[v] && v != p && sz[v] > size / 2) return find_centroid(v, u, size);
    }
    return u;
}
vi ar;
void dfs(int u, int p, int cur){
    ar.pb(cur);
    for (int v : g[u]){
        if (!dead[v] && v != p){
            dfs(v, u, cur + 1);
        }
    }
}
ll solve_tree(int u, int size){
    vl cnt(size, 0);
    cnt[0] = 1;
    ll res = 0;
    for (int v : g[u]){
        if (!dead[v]){
            dfs(v, u, 1);
            for (int it : ar){
                res += k - it < size && k - it >= 0 ? cnt[k - it] : 0;
            }
            for (int it : ar){
                ++ cnt[it];
            }
            ar.clear();
        }
    }
    return res;
}
ll decompose(int u){
    get_size(u);
    int centroid = find_centroid(u, -1, sz[u]);
    ll res = solve_tree(centroid, sz[u]);
    dead[centroid] = true;
    for (int v : g[centroid]){
        if (!dead[v]){
            res += decompose(v);
        }
    }
    return res;
}
