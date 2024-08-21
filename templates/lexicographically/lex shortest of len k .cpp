template <typename T>
struct Lexi {
    int n, k;
    T s;
    T res; 
    bool flag = true;

    void init(T &_s, int _k) {
        s = _s;
        k = _k;
        n = s.size();
        res.clear();
    }

    void solve() {
        flag = false;
        for (int i = 0; i < n; ++i) {
            while (res.size() && (res.size() + n - i - 1 >= k && s[i] < res.back())) {
                res.pop_back();
            }
            res.push_back(s[i]);
        }
    }

    T get_atleast_k() {
        if (flag) solve();
        return res;
    }

    T get_exactly_k() {
        if (flag) solve();
        return T(res.begin(), res.begin() + k);
    }
};

int main() {
    Lexi<string> lexiStr;
    string s = "bacd";
    lexiStr.init(s, 2);
    string res1 = lexiStr.get_exactly_k(); // "ac"
    string res2 = lexiStr.get_atleast_k(); // "acd"

    Lexi<vector<int>> lexiVec;
    vector<int> v = {3, 1, 2, 4};
    lexiVec.init(v, 2);
    vector<int> res3 = lexiVec.get_exactly_k(); // {1, 2}
    vector<int> res4 = lexiVec.get_atleast_k(); // {1, 2, 4}

    return 0;
}
