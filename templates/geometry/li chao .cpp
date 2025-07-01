/* 

TC : log2(max_x - min_x)

f(x) = mx + c
Gives the max value of f(x)

### If want the max value : 

to add line : add_line(m, c)
max value = query (x)

### IF we want the min value : 

to add line : add_line(-m, -c)
min_value = - query(x)

def_val : The default value of x

To initialize pass whatever is the min_x and max_x that you will query

if ans <= 1e18 or f(x) <= 1e18 then use ll, and defVal = -1e18
if ans > 1e18 or f(x) > 1e18 then use __int128 and defVal = -1e36


def_val : The default value of x, pass -1e18 or -1e9

min_x : the min value of x that you will query
max_x : the max value of x that you will query

we dont need exact values of min_x and max_x upper bound is fine
for eg if min_x is -1e3 you can pass -1e5
and if max_x is around 1e5 you can pass 1e6

TC will be same, but don't pass veryyy big values, otherwise it might overflow

works any type of functions such that each two only intersect atmost once

EXPLANATION : 

Each node / line gives the best resuklt for x = mid point of the range of that node

Query : 
1) first we consider this line / node to best for given x
2) but we no, that the line / node whose mid value is x, will be the best result
3) so we move towards that line / node

Update: (use this image for reference : https://cp-algorithms.com/geometry/li_chao_vertex.png)
1) if the value of f(l) is higher for current line then we swap it
2) so now the new line will always be the green one
3) now the new line beats current line on the left, we check if it also beats the current line on the right
   if yes then the new line beats the current line everywhere, so ne need of current line, we save new line 
   in current node and return
4) else we need to keep the line that gives best result for the mid point of this range on this node
5) if new line gives better result than current line on mid, it means mid is to the left of intersection,
    so we save new line in current node, but the current line can still give better result to the right of 
    intersection, so we call to the right and pass current line
6) else it means current line gives better result for mid, which means current mid point is to the right of
   intersection, so we call to the left and pass new line
*/

template<typename T, T min_x, T max_x, T def_val>
struct Lichao{
    struct Line{
        T m, c;
        inline T eval(T x){
            return m * x + c;
        }
    };
    struct Node{
        Line line = {0, def_val};
        Node* left = NULL, *right = NULL;
    };
    Node* root = new Node();
    T query(Node* node, T l, T r, T x){
        if (!node) return def_val;
        T res = node -> line.eval(x);
        T m = (l + r) >> 1;
        if (x > m) res = max(res, query(node -> right, m + 1, r, x));
        else res = max(res, query(node -> left, l, m, x));
        return res;
    }
    void update(Node* node, T l, T r, Line new_line){
        if (node -> line.eval(l) >= new_line.eval(l)) swap(node -> line, new_line);
        if (new_line.eval(r) >= node -> line.eval(r)){
            node -> line = new_line;
            return;
        }
        T m = (l + r) >> 1;
        if (new_line.eval(m) >= node -> line.eval(m)){
            if (!node -> right) node -> right = new Node();
            update(node -> right, m + 1, r, node -> line);
            node -> line = new_line;
        }else{
            if (!node -> left) node -> left = new Node();
            update(node -> left, l, m, new_line);
        }
    }
    T query(T x){
        return query(root, min_x, max_x, x);
    }
    void add_line(T m, T c){
        update(root, min_x, max_x, {m, c});
    }
};

