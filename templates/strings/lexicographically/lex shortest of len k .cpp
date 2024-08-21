/*
Functions : 
  - get lexicographically shortest string of len exactly k
  - get lexicographically shortest string of len atleast k
*/

struct Lexi{
    int n, k;
    string s;
    string res; 
    bool flag = true;
    void init(string &_s, int _k){
        s = _s;
        k = _k;
        n = s.size();
        res = "";
    }
    void solve(){
        flag = false;
        for (int i = 0; i < n; ++ i){
            while (res.size() && (res.size() + n - i - 1 >= k && s[i] < res.back())){
                res.pop_back();
            }
            res += s[i];
        }
    }
    string get_atleast_k(){
        if (flag) solve();
        return res;
    }
    string get_exactly_k(){
        if (flag) solve();
        return res.substr(0, k);
    }
};
