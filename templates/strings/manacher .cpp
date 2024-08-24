/*

- returns the length of longest palindrome with centre as x, (odd or even)
- Can check if substring L .. R, is a palindrome or not
- if even center is not a palindrome then get longest palindrome will return 0
- to check for even centre i, i + 1 call get_longest_palindrome(i, i + 1)
- to check for odd centre i call get_longest_palindrome(i, i)
  
Preprocessing : O(N)
Query : O(1)

----------------------------------------------------------------------------------------------------

Time Complexity Proof : 

we will always be on the right side of bounding box i.e (ind of current char will always be >= the mid point of bounding box)
because bounding box increases equally over left and right
If we are at index i, and we are expanding idex i then it means index i is the mid point of this bounding box, therefore
all the indexes ahead will be on the right side of the bounding box
As much as 'r' is increasing, we are expanding that much.

if current character is in bounding box : 

    whenever we successfully expand the expansion starts from r, and r increases
    r can increase at max upto n therefore expnasion will be not more than n combined

else : 

    for any character if it is outside bounding box then value of r will be i - 1, because previous character will be a palindrome of len 1
    then in this case also r is expanding from i 

*/

struct Manacher{
    int n;
    string s;
    vi p;
    void build(){
        int l = -1, r = -1;
        p.resize(n, 0);
        fr(i, n){
            if (r >= i) p[i] = min(r - i + 1, p[l + r - i]);
            while (i + p[i] < n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]]) ++ p[i]; 
            if (i + p[i] - 1 > r){
                r = i + p[i] - 1;
                l = i - p[i] + 1;
            }
        }
    }
    void init(string str){
        s = "";
        for (char it : str){
            s += string("#") + it;
        }
        s += "#"; 
        n = si(s);
        build();
    }
    int get_longest_palindrome(int l, int r){
        int ind = 2 * l + 1 + (l != r);
        return p[ind] - 1;
    }
    bool is_palindrome(int l, int r){
        int x = (l + r) / 2;
        int y = (r - l + 1) & 1 ? x : x + 1;
        return get_longest_palindrome(x, y) >= r - l + 1;
    }
};
