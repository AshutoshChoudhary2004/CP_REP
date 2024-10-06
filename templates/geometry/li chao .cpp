/* 
f(x) = mx + c
Gives the max value of f(x)

### If want the max value : 

to add line : add_line(m, c)
max value = query (x)

### IF we want the min value : 

to add line : add_line(-m, -c)
min_value = - query(-x)

To initialize pass whatever is the min_x and max_x that you will query
Dont pass too big / small values of min_x and max_x otherwise you will get overflow
if we are getting wrong answer or we want to pass large min_x and max_x then use __int28

def_val : The default value of x, pass -1e18 or -1e9

*/
template<typename T, T min_x, T max_x, T def_val>
struct LiChao{
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
        else if (x < m) res = max(res, query(node -> left, l, m, x));
        return res;
    }    
    T query(T x){
        return query(root, min_x, max_x, x);
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
    void add_line(T m, T c){
        update(root, min_x, max_x, {m, c});
    }
};
