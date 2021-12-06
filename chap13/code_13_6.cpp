#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int>>;

// 위상 정렬하기
vector<bool> seen;
vector<int> order; // 위상 정렬 순서를 나타냄
void rec(const Graph &G, int v) {
    seen[v] = true;
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // 이미 방문했다면 탐색하지 않음
        rec(G, next_v);
    }

    // v-out 기록
    order.push_back(v);
}

int main() {
    int N, M;
    cin >> N >> M; // 꼭짓점 개수와 가지 개수
    Graph G(N); // 꼭짓점 N개의 그래프
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // 탐색
    seen.assign(N, false); // 초기 상태는 모든 꼭짓점이 미방문
    order.clear(); // 위상 정렬 순서
    for (int v = 0; v < N; ++v) {
        if (seen[v]) continue; // 이미 방문했으면 탐색하지 않음
        rec(G, v);
    }
    reverse(order.begin(), order.end()); // 역순으로

    // 출력
    for (auto v : order) cout << v << " -> ";
    cout << endl;
}
