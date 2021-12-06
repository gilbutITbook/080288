#include <iostream>
#include <vector>
using namespace std;

// 무한대를 뜻하는 값
const long long INF = 1LL << 60; // 충분히 큰 값을 사용(여기서는 2^60)

// 변을 나타내는 자료형. 여기서는 가중치를 나타내는 자료형으로 long long 사용
struct Edge {
    int to; // 인접 꼭짓점 번호
    long long w; // 가중치
    Edge(int to, long long w) : to(to), w(w) {}
};

// 가중 그래프를 나타내는 자료형
using Graph = vector<vector<Edge>>;

// 완화를 실시하는 함수
template<class T> bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    // 꼭짓점 개수, 변 개수, 시작점
    int N, M, s;
    cin >> N >> M >> s;

    // 그래프
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }

    // 다익스트라 알고리즘
    vector<bool> used(N, false);
    vector<long long> dist(N, INF);
    dist[s] = 0;
    for (int iter = 0; iter < N; ++iter) {
        // 미사용 꼭짓점 중 dist값이 최소인 꼭짓점 찾기
        long long min_dist = INF;
        int min_v = -1;
        for (int v = 0; v < N; ++v) {
            if (!used[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                min_v = v;
            }
        }

        // 만약 그런 꼭짓점이 없다면 종료
        if (min_v == -1) break;

        // min_v을 시작점으로 각 변을 완화
        for (auto e : G[min_v]) {
            chmin(dist[e.to], dist[min_v] + e.w);
        }
        used[min_v] = true; // min_v를 사용이 끝났다고 표시
    }

    // 결과 출력
    for (int v = 0; v < N; ++v) {
        if (dist[v] < INF) cout << dist[v] << endl;
        else cout << "INF" << endl;
    }
}
