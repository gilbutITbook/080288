#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 이분 그래프 판정
vector<int> color;
bool dfs(const Graph &G, int v, int cur = 0) {
    color[v] = cur;
    for (auto next_v : G[v]) {
        // 인접 꼭짓점이 이미 색상이 정해진 경우
        if (color[next_v] != -1) {
            // 같은 색이 인접하면 이분 그래프가 아님
            if (color[next_v] == cur) return false;

            // 색상이 정해져 있으면 탐색하지 않음
            continue;
        }

        // 인접 꼭짓점 색을 바꾸고 재귀적으로 탐색
        // false가 반환되면 false를 돌려주기
        if (!dfs(G, next_v , 1 - cur)) return false;
    }
    return true;
}

int main() {
    // 꼭짓점 개수와 변 개수
    int N, M;
    cin >> N >> M;

    // 그래프 입력
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 탐색
    color.assign(N, -1);
    bool is_bipartite = true;
    for (int v = 0; v < N; ++v) {
        if (color[v] != -1) continue; // v를 이미 탐색했으면 탐색하지 않음
        if (!dfs(G, v)) is_bipartite = false;
    }

    if (is_bipartite) cout << "Yes" << endl;
    else cout << "No" << endl;
}
