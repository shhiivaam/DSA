#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

// Represents a pair (edge) with its original 1-based index
struct Edge {
    int u, v, id;
};

// Disjoint Set Union (DSU) for finding connected components
struct DSU {
    std::vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        std::iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

// Represents an interval [s, e] corresponding to a component
struct Interval {
    int s, e, comp_id;
};

// Finds a spanning tree for a chosen component using BFS
void find_spanning_tree(int start_node, const std::vector<std::vector<std::pair<int, int>>>& adj,
                        std::vector<bool>& visited, std::vector<int>& result_indices) {
    std::vector<int> q;
    q.push_back(start_node);
    visited[start_node] = true;

    int head = 0;
    while(head < q.size()){
        int u = q[head++];
        for(auto& edge : adj[u]){
            int v = edge.first;
            int edge_id = edge.second;
            if(!visited[v]){
                visited[v] = true;
                result_indices.push_back(edge_id);
                q.push_back(v);
            }
        }
    }
}


void solve() {
    int n;
    std::cin >> n;
    std::vector<Edge> edges(n);
    int max_coord = 0;
    std::vector<int> all_nodes_vec;
    for (int i = 0; i < n; ++i) {
        std::cin >> edges[i].u >> edges[i].v;
        edges[i].id = i + 1;
        max_coord = std::max({max_coord, edges[i].u, edges[i].v});
        all_nodes_vec.push_back(edges[i].u);
        all_nodes_vec.push_back(edges[i].v);
    }

    std::sort(all_nodes_vec.begin(), all_nodes_vec.end());
    all_nodes_vec.erase(std::unique(all_nodes_vec.begin(), all_nodes_vec.end()), all_nodes_vec.end());

    DSU dsu(max_coord);
    for (const auto& edge : edges) {
        dsu.unite(edge.u, edge.v);
    }

    std::map<int, std::vector<int>> comp_nodes;
    for(int node : all_nodes_vec){
        comp_nodes[dsu.find(node)].push_back(node);
    }

    std::vector<Interval> intervals;
    for (auto const& [root, nodes] : comp_nodes) {
        if (nodes.empty()) continue;
        int min_v = nodes[0], max_v = nodes[0];
        for (size_t i = 1; i < nodes.size(); ++i) {
            min_v = std::min(min_v, nodes[i]);
            max_v = std::max(max_v, nodes[i]);
        }
        intervals.push_back({min_v, max_v, root});
    }

    if (intervals.empty()) {
        std::cout << 0 << std::endl << std::endl;
        return;
    }

    std::sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
        if (a.s != b.s) return a.s < b.s;
        return a.e < b.e;
    });

    int m = intervals.size();
    std::vector<long long> dp(m + 1, 0);
    std::vector<int> parent(m + 1, 0);

    for (int i = m - 1; i >= 0; --i) {
        dp[i] = dp[i + 1];
        parent[i] = i + 1;

        int end_point = intervals[i].e;
        for (int j = i + 1; j < m; ++j) {
            if (intervals[j].s <= end_point) {
                end_point = std::max(end_point, intervals[j].e);
            }
        }
        
        auto it = std::upper_bound(intervals.begin() + i, intervals.end(), end_point, 
                                   [](int val, const Interval& iv){ return val < iv.s; });
        int k = std::distance(intervals.begin(), it);
        
        long long current_val = (long long)end_point - intervals[i].s + dp[k];

        if (current_val > dp[i]) {
            dp[i] = current_val;
            parent[i] = -k;
        }
    }

    std::vector<int> block_starts;
    int curr = 0;
    while(curr < m) {
        if(parent[curr] <= 0) {
            block_starts.push_back(curr);
            curr = -parent[curr];
        } else {
            curr = parent[curr];
        }
    }

    std::vector<int> final_chosen_comp_ids;
    for(int start_idx : block_starts) {
        int end_point = intervals[start_idx].e;
        for (int j = start_idx + 1; j < m; ++j) {
            if (intervals[j].s <= end_point) {
                end_point = std::max(end_point, intervals[j].e);
            }
        }
        for (int j = start_idx; j < m; ++j) {
            if (intervals[j].s <= end_point) {
                final_chosen_comp_ids.push_back(intervals[j].comp_id);
            } else {
                break;
            }
        }
    }

    std::sort(final_chosen_comp_ids.begin(), final_chosen_comp_ids.end());
    final_chosen_comp_ids.erase(std::unique(final_chosen_comp_ids.begin(), final_chosen_comp_ids.end()), final_chosen_comp_ids.end());

    std::vector<std::vector<std::pair<int, int>>> adj(max_coord + 1);
    for (const auto& edge : edges) {
        if (std::binary_search(final_chosen_comp_ids.begin(), final_chosen_comp_ids.end(), dsu.find(edge.u))) {
            adj[edge.u].push_back({edge.v, edge.id});
            adj[edge.v].push_back({edge.u, edge.id});
        }
    }

    std::vector<int> result_indices;
    std::vector<bool> visited(max_coord + 1, false);
    for (int comp_id : final_chosen_comp_ids) {
        if (!comp_nodes[comp_id].empty()) {
            int start_node = comp_nodes[comp_id][0];
            if (!visited[start_node]) {
                 find_spanning_tree(start_node, adj, visited, result_indices);
            }
        }
    }

    std::cout << result_indices.size() << std::endl;
    for (size_t i = 0; i < result_indices.size(); ++i) {
        std::cout << result_indices[i] << (i == result_indices.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

