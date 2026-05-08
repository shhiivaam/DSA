class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        int max_val = 0;
        for (int num : nums) {
            if (num > max_val) max_val = num;
        }
        
        int MAX_VAL = max_val + 1;
        if (MAX_VAL < 2) MAX_VAL = 2;
        vector<int> spf(MAX_VAL);
        for (int i = 0; i < MAX_VAL; i++) spf[i] = i;
        for (int i = 2; i * i < MAX_VAL; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j < MAX_VAL; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }
        vector<bool> prime_present(MAX_VAL, false);
        for (int num : nums) {
            if (num > 1 && spf[num] == num) {
                prime_present[num] = true;
            }
        }
        vector<vector<int>> prime_to_indices(MAX_VAL);
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int last_p = 0;
            while (x > 1) {
                int p = spf[x];
                if (p != last_p) {
                    if (prime_present[p]) {
                        prime_to_indices[p].push_back(i);
                    }
                    last_p = p;
                }
                x /= p; 
            }
        }
        vector<int> dist(n, -1);
        queue<int> q;
        vector<bool> prime_used(MAX_VAL, false);

        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == n - 1) return dist[u];
            if (u + 1 < n && dist[u + 1] == -1) {
                dist[u + 1] = dist[u] + 1;
                if (u + 1 == n - 1) return dist[u + 1];
                q.push(u + 1);
            }

            if (u - 1 >= 0 && dist[u - 1] == -1) {
                dist[u - 1] = dist[u] + 1;
                q.push(u - 1);
            }

            int p = nums[u];
            if (p > 1 && spf[p] == p && !prime_used[p]) {
                prime_used[p] = true;
                
                for (int v : prime_to_indices[p]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        if (v == n - 1) return dist[v];
                        q.push(v);
                    }
                }
            }
        }

        return -1;
    }
};