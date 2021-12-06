#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 깊이 우선 탐색
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true; // v를 방문했다고 표시

    // v에서 갈 수 있는 각 꼭짓점 next_v에 대해서
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v를 이미 탐색했으면 건너뜀
        dfs(G, next_v); // 재귀적으로 탐색
    }
}

int main() {
    // 꼭짓점 개수와 변 개수 s와 t
    int N, M, s, t;
    cin >> N >> M >> s >> t;

    // 그래프 입력 받기
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // 꼭짓점 s에서 탐색 시작
    seen.assign(N, false); // 모든 꼭짓점을 미방문으로 초기화
    dfs(G, s);

    // t에 도착 가능한가
    if (seen[t]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
