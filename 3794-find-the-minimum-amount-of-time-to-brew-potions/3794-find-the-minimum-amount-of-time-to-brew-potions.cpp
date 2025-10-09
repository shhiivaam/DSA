class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        if (m == 0) {
            return 0;
        }
        vector<long long> p(n);
        p[0] = skill[0];
        for (int i = 1; i < n; ++i) {
            p[i] = p[i - 1] + skill[i];
        }
        long long startTime = 0;
        for (int j = 1; j < m; ++j) {
            long long m_prev = mana[j - 1];
            long long m_curr = mana[j];
            
            long long delta = p[0] * m_prev;
            for (int i = 1; i < n; ++i) {
                delta = max(delta, p[i] * m_prev - p[i - 1] * m_curr);
            }
            startTime += delta;
        }
        return startTime + p[n - 1] * (long long)mana.back();
    }
};