#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

// 입력: 그래프 G와 탐색 시작점 s
// 출력: s에서 각 꼭짓점을 향한 최단 경로 거리를 나타내는 배열
vector<int> BFS(const Graph &G, int s) {
    int N = (int)G.size(); // 꼭짓점 개수
    vector<int> dist(N, -1); // 전체 꼭짓점을 미방문으로 초기화
    queue<int> que;

    // 초기 조건(꼭짓점 s를 초기 꼭짓점으로)
    dist[s] = 0;
    que.push(s); // s를 주황색 꼭짓점으로

    // BFS 시작(큐가 빌 때까지 탐색)
    while (!que.empty()) {
        int v = que.front(); // 큐에서 꼭짓점을 추출
        que.pop();

        // v에서 갈 수 있는 꼭짓점을 모두 조사
        for (int x : G[v]) {
            // 이미 발견한 꼭짓점은 탐색하지 않음
            if (dist[x] != -1) continue;

            // 새로운 흰색 꼭짓점 x에 대해 거리 정보를 갱신해서 큐에 삽입
            dist[x] = dist[v] + 1;
            que.push(x);
        }
    }
    return dist;
}

int main() {
    // 꼭짓점 개수와 변 개수
    int N, M;
    cin >> N >> M;

    // 그래프 입력(무향 그래프라고 가정)
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 꼭짓점 0을 시작점으로 하는 BFS
    vector<int> dist = BFS(G, 0);

    // 결과 출력(각 꼭짓점의 꼭짓점 0으로부터의 거리)
    for (int v = 0; v < N; ++v) cout << v << ": " << dist[v] << endl;
}
