#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 무한대를 나타내는 값(여기서는 2^60)
const long long INF = 1LL << 60;

// 변을 나타내는 자료형. 가중치 자료형은 long long
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
    vector<long long> dist(N, INF);
    dist[s] = 0;

    // (d[v], v) 쌍을 요소로 하는 힙을 작성
    priority_queue<pair<long long, int>,
                   vector<pair<long long, int>>,
                   greater<pair<long long, int>>> que;
    que.push(make_pair(dist[s], s));

    // 다익스트라 알고리즘 반복을 시작
    while (!que.empty()) {
        // v: 미사용 꼭짓점 중 d[v]가 최소인 꼭짓점
        // d: v에 대한 키값
        int v = que.top().second;
        long long d = que.top().first;
        que.pop();

        // d > dist[v]는 (d, v)가 쓰레기라는 걸 의미함
        if (d > dist[v]) continue;

        // 꼭짓점 v를 시작점으로 하는 각 변을 완화
        for (auto e : G[v]) {
            if (chmin(dist[e.to], dist[v] + e.w)) {
                // 갱신이 있으면 힙에 새롭게 삽입
                que.push(make_pair(dist[e.to], e.to));
            }
        }
    }

    // 결과 출력
    for (int v = 0; v < N; ++v) {
        if (dist[v] < INF) cout << dist[v] << endl;
        else cout << "INF" << endl;
    }
}
