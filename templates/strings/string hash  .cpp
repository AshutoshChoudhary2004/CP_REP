constexpr uint64_t MOD = (1ULL << 61) - 1;
const uint64_t base = rng() % (MOD / 3) + MOD / 3;
constexpr int N = 2e5 + 10;
uint64_t base_pow[N];

int64_t modmul(uint64_t a, uint64_t b){
    uint64_t l1 = (uint32_t)a, l2 = (uint32_t)b, h1 = a >> 32, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + h1 * l2, h = h1 * h2;
    uint64_t res = (l & MOD) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    res = (res & MOD) + (res >> 61);
    res = (res & MOD) + (res >> 61);
    return res - 1;
}

void calculate_power(){
    base_pow[0] = 1;
    for (int i = 1; i < N; ++ i){
        base_pow[i] = modmul(base_pow[i - 1], base);
    }
}

struct StringHash{
    int n;
    vector<int64_t> p, s;
    void init(string str){
        if (!base_pow[0]) calculate_power();
        n = str.size();
        p.resize(n, 0);
        s.resize(n, 0);
        for (int i = 0; i < n; ++ i){
            p[i] = modmul(i ? p[i - 1] : 0, base) + str[i] + 997;
            if (p[i] >= MOD) p[i] -= MOD;
        }
        for (int i = n - 1; i >= 0; -- i){
            s[i] = modmul(i != n - 1 ? s[i + 1] : 0, base) + str[i] + 997;
            if (s[i] >= MOD) s[i] -= MOD;
        }
    }
    uint64_t get_hash(int l, int r){
        int64_t res = p[r] - modmul(l ? p[l - 1] : 0, base_pow[r - l + 1]);
        return res < 0 ? res + MOD : res; 
    }
    uint64_t get_rev_hash(int l, int r){
        int64_t res = s[l] - modmul(r != n - 1 ? s[r + 1] : 0, base_pow[r - l + 1]);
        return res < 0 ? res + MOD : res;
    }
};

int main(){
    StringHash hash;
    hash.init("racecar");
    assert(hash.get_hash(0, 6) == hash.rev_hash(0, 6));
    assert(hash.get_hash(1, 5) != hash.rev_hash(0, 4));
    assert(hash.get_hash(1, 1) == hash.rev_hash(5, 5));
    assert(hash.get_hash(1, 1) != hash.rev_hash(5, 6));
    assert(hash.get_hash(2, 4) == hash.rev_hash(2, 4));
    return 0;
}
