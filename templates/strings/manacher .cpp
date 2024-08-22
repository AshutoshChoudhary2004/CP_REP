/*

- returns the length of longest palindrome with centre as x, (odd or even)
- Can check if substring L .. R, is a palindrome or not
- if even centre is not a palindrome then get longest palindrome will return 0
  
Preprocessing : O(N)
Query : O(1)

Time Complexity Proof : 

we will always be on the right side of bounding box i.e (ind of current char will always be >= the mid point of bounding box)
because bounding box increases equally over left and right

if current character is in bounding box : 

    whenever we successfully expand the expansion starts from r, and r increases
    r can increase at max upto n therefore expnasion will be not more than n combined

else : 

    for any character if it is outside bounding box then value of r will be i - 1, because previous character will be a palindrome of len 1
    then in this case also r is expanding

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
        return get_longest_palindrome((l + r + 1) / 2, l % 2 != r % 2) >= r - l + 1;
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
