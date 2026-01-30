class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        int id = -1;
        TrieNode() {
            fill(begin(children), end(children), nullptr);
        }
    };
    void insert(TrieNode* root, const string& s, int id) {
        TrieNode* node = root;
        for (char c : s) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->id = id;
    }
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        unordered_map<string, int> strToId;
        int idCounter = 0;
        
        for (const string& s : original) {
            if (strToId.find(s) == strToId.end()) strToId[s] = idCounter++;
        }
        for (const string& s : changed) {
            if (strToId.find(s) == strToId.end()) strToId[s] = idCounter++;
        }

        int numNodes = strToId.size();
        const long long INF = 1e15;
        vector<vector<long long>> dist(numNodes, vector<long long>(numNodes, INF));

        for (int i = 0; i < numNodes; ++i) dist[i][i] = 0;

        for (size_t i = 0; i < original.size(); ++i) {
            int u = strToId[original[i]];
            int v = strToId[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < numNodes; ++k) {
            for (int i = 0; i < numNodes; ++i) {
                if (dist[i][k] == INF) continue;
                for (int j = 0; j < numNodes; ++j) {
                    if (dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        TrieNode* root = new TrieNode();
        for (const string& s : original) {
            insert(root, s, strToId[s]);
        }

        int n = source.length();
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            if (dp[i] == INF) continue;

            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            TrieNode* node = root;
            for (int j = i; j < n; ++j) {
                int idx = source[j] - 'a';
                if (!node->children[idx]) break;
                node = node->children[idx];

                if (node->id != -1) {
                    int len = j - i + 1;
                    string subTarget = target.substr(i, len);
                    
                    if (strToId.count(subTarget)) {
                        int u = node->id;
                        int v = strToId[subTarget];
                        
                        if (dist[u][v] < INF) {
                            dp[i + len] = min(dp[i + len], dp[i] + dist[u][v]);
                        }
                    }
                }
            }
        }
        return dp[n] >= INF ? -1 : dp[n];
    }
};