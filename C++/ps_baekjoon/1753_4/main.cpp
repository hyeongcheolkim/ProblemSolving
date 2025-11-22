#include <iostream>
#include <vector>
#include <queue>
#include <limits>

// 무한대를 나타내는 상수 (int의 최댓값)
#define INF std::numeric_limits<int>::max()

// 입출력 속도 향상을 위한 설정
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

int main() {
    setup_io();

    int V, E, K;
    std::cin >> V >> E >> K;

    // 인접 리스트로 그래프 표현. pair: {가중치, 도착 정점}
    std::vector<std::pair<int, int>> adj[V + 1];
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    // 시작점으로부터의 최단 거리를 저장할 벡터
    std::vector<int> dist(V + 1, INF);

    // 우선순위 큐를 이용한 다익스트라 알고리즘
    // pair: {비용, 현재 정점}. 비용이 낮은 순으로 정렬되도록 min-heap 구성
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    // 시작점 설정
    dist[K] = 0;
    pq.push({0, K}); // {비용, 시작 정점}

    while (!pq.empty()) {
        // 현재 가장 비용이 적은 정점 정보 가져오기
        int current_cost = pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        // 이미 더 짧은 경로를 찾았다면 무시
        if (dist[current_vertex] < current_cost) {
            continue;
        }

        // 현재 정점과 연결된 다른 정점들을 확인
        for (const auto& edge : adj[current_vertex]) {
            int neighbor_weight = edge.first;
            int neighbor_vertex = edge.second;

            int new_cost = current_cost + neighbor_weight;

            // 현재 정점을 거쳐 가는 것이 더 짧은 경우 거리 갱신
            if (new_cost < dist[neighbor_vertex]) {
                dist[neighbor_vertex] = new_cost;
                pq.push({new_cost, neighbor_vertex});
            }
        }
    }

    // 결과 출력
    for (int i = 1; i <= V; ++i) {
        if (dist[i] == INF) {
            std::cout << "INF\n";
        } else {
            std::cout << dist[i] << "\n";
        }
    }

    return 0;
}