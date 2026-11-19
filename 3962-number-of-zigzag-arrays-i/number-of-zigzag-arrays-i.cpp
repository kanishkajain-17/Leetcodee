class Solution {
public:
    static constexpr int MOD = 1'000'000'007;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;                 // number of distinct values
        // up[v]   = ways ending at value (l+v) with last step UP
        // down[v]  = ways ending at value (l+v) with last step DOWN
        vector<long long> up(m, 1), down(m, 1);

        for (int i = 2; i <= n; ++i) {
            vector<long long> nup(m), ndown(m);

            // Last step UP into v: previous value u < v, arrived via DOWN.
            long long pref = 0;
            for (int v = 0; v < m; ++v) {
                nup[v] = pref;             // sum of down[u] for u < v
                pref += down[v];
                if (pref >= MOD) pref -= MOD;
            }

            // Last step DOWN into v: previous value u > v, arrived via UP.
            long long suff = 0;
            for (int v = m - 1; v >= 0; --v) {
                ndown[v] = suff;           // sum of up[u] for u > v
                suff += up[v];
                if (suff >= MOD) suff -= MOD;
            }

            up.swap(nup);
            down.swap(ndown);
        }

        long long ans = 0;
        for (int v = 0; v < m; ++v) {
            ans += up[v] + down[v];
            ans %= MOD;
        }
        return (int)ans;
    }
};