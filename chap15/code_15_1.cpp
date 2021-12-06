#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Union-Find
struct UnionFind {
    vector<int> par, siz;

    // 초기화
    UnionFind(int n) : par(n, -1) , siz(n, 1) { }

    // 루트 구하기
    int root(int x) {
        if (par[x] == -1) return x; // x가 루트라면 x를 반환
        else return par[x] = root(par[x]);
    }

    // x와 y가 같은 그룹에 속하는지 여부(루트가 일치하는지 여부)
    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    // x를 포함하는 그룹과 y를 포함하는 그룹 병합하기
    bool unite(int x, int y) {
        // x, y를 각각 루트까지 이동시킴
        x = root(x);
        y = root(y);

        // 이미 같은 그룹이라면 아무 것도 안함
        if (x == y) return false;

        // union by size(y쪽 크기가 작아지도록 만듬)
        if (siz[x] < siz[y]) swap(x, y);

        // y를 x의 자식으로 만듬
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // x를 포함하는 그룹 크기
    int size(int x) {
        return siz[root(x)];
    }
};

// 변 e = (u, v)를 {w(e), {u, v}}로 표현함
using Edge = pair<int, pair<int,int>>;

int main() {
    // 입력
    int N, M; // 꼭짓점 개수와 변 개수
    cin >> N >> M;
    vector<Edge> edges(M); // 변 집합
    for (int i = 0; i < M; ++i) {
        int u, v, w; // w는 가중치
        cin >> u >> v >> w;
        edges[i] = Edge(w, make_pair(u, v));
    }

    // 각 변을 변의 가중치가 작은 순서로 정렬
    // pair는 기본값으로(첫 번째 요소, 두 번째 요소) 사전순으로 비교
    sort(edges.begin(), edges.end());

    // 크러스컬 알고리즘
    long long res = 0;
    UnionFind uf(N);
    for (int i = 0; i < M; ++i) {
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        // 변 (u, v) 추가로 사이클이 형성되면 추가하지 않음
        if (uf.issame(u, v)) continue;

        // 변 (u, v)를 추가하기
        res += w;
        uf.unite(u, v);
    }
    cout << res << endl;
}
