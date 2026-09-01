class Solution {
public:
        int prims(vector<vector<pair<int, int>>>& adj, int V) {

        vector<int> visited(V, false);
        int sum = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {

            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(visited[node] == true)
                continue;
            
            visited[node] = true;
            sum += wt;

            for (auto &a : adj[node]) {

                int neigh_node = a.first;
                int neigh_wt = a.second;

                if(visited[neigh_node] == false) {
                    pq.push({neigh_wt, neigh_node});
                }
            }
        }
        return sum;
    } 

    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<vector<pair<int, int>>> adj(V);

        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {

                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x2 - x1) + abs(y2 - y1);

                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        return prims(adj, V);
    }
};