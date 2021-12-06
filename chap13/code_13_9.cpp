#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 트리 탐색
vector<int> depth;
vector<int> subtree_size;
void dfs(const Graph &G, int v, int p = -1, int d = 0) {
    depth[v] = d;
    for (auto c : G[v]) {
        if (c == p) continue; // 탐색이 부모 방향으로 역류하는 걸 방지
        dfs(G, c, v, d + 1);
    }

    // 후위 순회시 부분 트리 크기를 구하기
    subtree_size[v] = 1; // 자기 자신
    for (auto c : G[v]) {
        if (c == p) continue;

        // 자식 꼭짓점을 루트로 하는 부분 트리 크기를 더하기
        subtree_size[v] += subtree_size[c];
    }
}

int main() {
    // 꼭짓점 개수(트리이므로 변 개수는 N -1)
    int N;
    cin >> N;

    // 그래프 입력
    Graph G(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 탐색
    int root = 0; // 일단 꼭짓점 0을 루트로 삼음
    depth.assign(N, 0);
    subtree_size.assign(N, 0);
    dfs(G, root);

    // 결과
    for (int v = 0; v < N; ++v) {
        cout << v << ": depth = " << depth[v]
        << ", subtree_size = " << subtree_size[v] << endl;
    }
}
