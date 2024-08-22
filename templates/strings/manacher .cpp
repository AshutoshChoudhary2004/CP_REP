/*

- returns the length of longest palindrome with centre as x, (odd or even)
- Can check if substring L .. R, is a palindrome or not
  
Preprocessing : O(N)
Query : O(1)

*/

struct Manacher{
    vi p;
    string s;
    int n;
    void run_manacher(){
        int l = -1, r = 1;
        fr(i, n){
            p[i] = max(0, min(r - i, l + r - i >= 0 ? p[l + r - i] : 0));
            while (i + p[i] < n && i - p[i] >= 0 && s[i - p[i]] == s[i + p[i]]) ++ p[i];
            if (i + p[i] > r){
                r = i + p[i];
                l = i - p[i];
            }
        }
    }
    // if want longset palindrome between i and i + 1, call get_longest(i + 1, true)
    int get_longest_palindrome(int centre, bool is_even){
        int i = 2 * centre + (!is_even);
        return p[i] - 1;
    }
    bool is_palindrome(int l, int r){
        return get_longest((l + r + 1) / 2, l % 2 != r % 2) >= r - l + 1;
    }

    void init(string str){
        for (char it : str){
            s += string("#") + it;
        }
        s += "#";
        n = si(s);
        p.assign(n, 1);
        run_manacher();
    }
};
