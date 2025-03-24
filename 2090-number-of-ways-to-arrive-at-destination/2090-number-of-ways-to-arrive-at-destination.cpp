class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<list<pair<int, int>>> edges(n);
        for (const auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            edges[u].push_back({v, time});
            edges[v].push_back({u, time});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        vector<long long> distances(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        const int mod = 1e9 + 7;

        distances[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [currDistance, node] = pq.top();
            pq.pop();

            if (currDistance > distances[node])
                continue;

            for (const auto& [nextNode, travelTime] : edges[node]) {
                long long newDist = currDistance + (long long)travelTime;

                if (newDist < distances[nextNode]) {
                    distances[nextNode] = newDist;
                    pq.push({newDist, nextNode});
                    ways[nextNode] = ways[node];
                }

                else if (newDist == distances[nextNode]) {
                    ways[nextNode] = (ways[nextNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};