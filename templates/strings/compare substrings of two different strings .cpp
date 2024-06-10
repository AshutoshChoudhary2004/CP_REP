class StringComp {
private:
    string s1, s2;
    vector<unsigned long long> hash1a, hash1b, hash2a, hash2b, p1_powers, p2_powers;
    unsigned long long p1 = 31, p2 = 37;
    unsigned long long md1 = 1e9 + 7, md2 = 1e9 + 9;

    unsigned long long modPow(unsigned long long base, unsigned long long exp, unsigned long long modulus) {
        base %= modulus;
        unsigned long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % modulus;
            base = (base * base) % modulus;
            exp /= 2;
        }
        return result;
    }

    void precomputePowers(int maxLen) {
        p1_powers.resize(maxLen + 1);
        p2_powers.resize(maxLen + 1);

        p1_powers[0] = 1;
        p2_powers[0] = 1;
        for (int i = 1; i <= maxLen; i++) {
            p1_powers[i] = (p1_powers[i - 1] * p1) % md1;
            p2_powers[i] = (p2_powers[i - 1] * p2) % md2;
        }
    }

public:
    void init(const string& str1, const string& str2) {
        s1 = str1;
        s2 = str2;

        int n1 = s1.length(), n2 = s2.length();
        int maxLen = max(n1, n2);
        precomputePowers(maxLen);

        hash1a.resize(n1 + 1);
        hash1b.resize(n1 + 1);
        hash2a.resize(n2 + 1);
        hash2b.resize(n2 + 1);

        hash1a[0] = hash1b[0] = 0;
        for (int i = 0; i < n1; i++) {
            hash1a[i + 1] = (hash1a[i] * p1 + s1[i]) % md1;
            hash1b[i + 1] = (hash1b[i] * p2 + s1[i]) % md2;
        }

        hash2a[0] = hash2b[0] = 0;
        for (int i = 0; i < n2; i++) {
            hash2a[i + 1] = (hash2a[i] * p1 + s2[i]) % md1;
            hash2b[i + 1] = (hash2b[i] * p2 + s2[i]) % md2;
        }
    }

    bool is_equal(int l1, int r1, int l2, int r2) {
        int len = r1 - l1 + 1;
        if (len != (r2 - l2 + 1)) {
            return false;
        }

        unsigned long long hash1a_s1 = (hash1a[r1 + 1] + md1 - (hash1a[l1] * p1_powers[len] % md1)) % md1;
        unsigned long long hash1a_s2 = (hash2a[r2 + 1] + md1 - (hash2a[l2] * p1_powers[len] % md1)) % md1;
        unsigned long long hash1b_s1 = (hash1b[r1 + 1] + md2 - (hash1b[l1] * p2_powers[len] % md2)) % md2;
        unsigned long long hash1b_s2 = (hash2b[r2 + 1] + md2 - (hash2b[l2] * p2_powers[len] % md2)) % md2;

        return (hash1a_s1 == hash1a_s2) && (hash1b_s1 == hash1b_s2);
    }
};
