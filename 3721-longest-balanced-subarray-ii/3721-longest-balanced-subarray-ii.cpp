class Solution {
    vector<int> min_val;
    vector<int> max_val;
    vector<int> lazy;
    int n;

    void push(int node) {
        if (lazy[node] != 0) {
            min_val[2 * node] += lazy[node];
            max_val[2 * node] += lazy[node];
            lazy[2 * node] += lazy[node];
            
            min_val[2 * node + 1] += lazy[node];
            max_val[2 * node + 1] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
            
            lazy[node] = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, int val) {
        if (l > end || r < start) return;
        if (l <= start && end <= r) {
            min_val[node] += val;
            max_val[node] += val;
            lazy[node] += val;
            return;
        }
        push(node);
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        min_val[node] = min(min_val[2 * node], min_val[2 * node + 1]);
        max_val[node] = max(max_val[2 * node], max_val[2 * node + 1]);
    }

    int query(int node, int start, int end, int r_limit) {
        if (start > r_limit) return -1;
        if (min_val[node] > 0 || max_val[node] < 0) return -1;
        if (start == end) return start;
        
        push(node);
        int mid = (start + end) / 2;
        int res = query(2 * node, start, mid, r_limit);
        if (res != -1) return res;
        return query(2 * node + 1, mid + 1, end, r_limit);
    }

public:
    int longestBalanced(vector<int>& nums) {
        n = nums.size();
        min_val.assign(4 * n, 0);
        max_val.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        
        vector<int> last_pos(100005, -1);
        int max_len = 0;

        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            int prev = last_pos[val];
            
            int diff = (val % 2 == 0) ? 1 : -1;
            update(1, 0, n - 1, prev + 1, i, diff);
            
            last_pos[val] = i;
            
            int l = query(1, 0, n - 1, i);
            if (l != -1) {
                max_len = max(max_len, i - l + 1);
            }
        }
        
        return max_len;
    }
};