/*
Problem: Shortest Path With At Most K Consecutive Identical Characters
Link: https://leetcode.com/problems/shortest-path-with-at-most-k-consecutive-identical-characters/
Contest: Weekly Contest 507
Difficulty: Hard
Approach: Dijkstra, Graph
Time Complexity: O(E log V)
Note:
    
*/
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int,int>>> g(n);

        for (auto &e : edges) {
            g[e[0]].push_back({e[1], e[2]});
        }

        const long long INF = 1e18;

        vector<vector<long long>> dis(n, vector<long long>(k + 1, INF));

        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > pq;

        dis[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, c] = pq.top();
            pq.pop();

            if (d != dis[u][c]) continue;

            for (auto &[v, w] : g[u]) {
                int nc = (labels[v] == labels[u]) ? c + 1 : 1;

                if (nc > k) continue;

                long long nd = d + w;

                if (nd < dis[v][nc]) {
                    dis[v][nc] = nd;
                    pq.push({nd, v, nc});
                }
            }
        }

        long long ans = INF;

        for (int i = 1; i <= k; i++) {
            ans = min(ans, dis[n - 1][i]);
        }

        return ans == INF ? -1 : ans;
    }
};