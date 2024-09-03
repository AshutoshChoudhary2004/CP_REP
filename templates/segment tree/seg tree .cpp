/*
Example given for range sum
whatever is the deafult value, is the default value in seg tree
if dont want that than use set_value to set value
*/
template <typename T, T (*combine)(T, T), T default_value>
struct SegmentTree{
    int n;
    vector<T> seg;

    void init(int _n){
        n = _n;
        seg.resize(4 * n, default_value); 
    }
    T query(int ind, int low, int high, int left, int right){
        if (low >= left && high <= right) return seg[ind];
        if (high < left || low > right) return default_value;
        int mid = (low + high) >> 1;
        return combine(query(2 * ind + 1, low, mid, left, right), query(2 * ind + 2, mid + 1, high, left, right));
    }
    void set_value(int ind, int low, int high, int idx, T x){
        if (low == high){
            seg[ind] = x;
            return;
        }
        int mid = (low + high) >> 1;
        if (idx >= low && idx <= mid){
            set_value(2 * ind + 1, low, mid, idx, x);
        }else set_value(2 * ind + 2, mid + 1, high, idx, x);
        seg[ind] = combine(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    void set_value(int i, T val){
        set_value(0, 0, n - 1, i, val);
    }

    T query(int l, int r){
        return query(0, 0, n - 1, l, r);
    }
};

ll combine(ll x, ll y){return x + y;}

int main() {
    
    SegmentTree<ll , combine, 0LL> tree;
    tree.init(n);
}
