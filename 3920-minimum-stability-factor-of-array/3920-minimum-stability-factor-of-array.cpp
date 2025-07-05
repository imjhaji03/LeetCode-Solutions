class Solution {
private:
    vector<vector<long long>> st;
    vector<int> log_table;
    int n;

    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    void buildSparseTable(const vector<int>& nums) {
        n = nums.size();
        if (n == 0) return;
        
        log_table.resize(n + 1);
        log_table[1] = 0;
        for (int i = 2; i <= n; i++) {
            log_table[i] = log_table[i / 2] + 1;
        }

        int max_log = log_table[n];
        st.assign(n, vector<long long>(max_log + 1));

        for (int i = 0; i < n; i++) {
            st[i][0] = nums[i];
        }

        for (int k = 1; k <= max_log; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                st[i][k] = gcd(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
            }
        }
    }

    long long queryHCF(int l, int r) {
        if (l > r) return 0;
        int k = log_table[r - l + 1];
        return gcd(st[l][k], st[r - (1 << k) + 1][k]);
    }

    bool isPossible(int K, int maxC) {
        if (K > n) return true;

        int cost = 0;
        int i = 0;
        while (i <= n - K) {
            if (queryHCF(i, i + K - 1) >= 2) {
                cost++;
                i += K;
            } else {
                i++;
            }
        }
        return cost <= maxC;
    }

public:
    int minStable(vector<int>& nums, int maxC) {
        buildSparseTable(nums);
        
        int low = 0, high = nums.size(), ans = nums.size();
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(mid + 1, maxC)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};