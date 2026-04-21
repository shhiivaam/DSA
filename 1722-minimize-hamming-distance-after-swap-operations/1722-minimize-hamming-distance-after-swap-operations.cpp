#include <vector>
#include <unordered_map>

using namespace std;

class DSU {
private:
    vector<int> parent;
public:
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); 
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootY] = rootX;
        }
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu(n);
        
        for (const auto& swap : allowedSwaps) {
            dsu.unite(swap[0], swap[1]);
        }
        
        unordered_map<int, unordered_map<int, int>> componentMap;
        
        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            componentMap[root][source[i]]++;
        }
        
        int hammingDistance = 0;
        
        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            int targetVal = target[i];
            
            if (componentMap[root][targetVal] > 0) {
                componentMap[root][targetVal]--;
            } else {
                hammingDistance++; 
            }
        }
        
        return hammingDistance;
    }
};