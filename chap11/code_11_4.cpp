#include <iostream>
#include <vector>
using namespace std;

// Union-Find
struct UnionFind {
    vector<int> par, siz;

    UnionFind(int n) : par(n, -1) , siz(n, 1) { }

    // 루트 구하기
    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    // x와 y가 같은 그룹에 속하는가(루트가 일치하는가)
    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    // x를 포함한 그룹과 y를 포함한 그룹을 병합
    bool unite(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // x를 포함하는 그룹 크기
    int size(int x) {
        return siz[root(x)];
    }
};

int main() {
    // 꼭짓점 개수와 변 개수
    int N, M;
    cin >> N >> M;

    // Union-Find를 요소 개수 N으로 초기화
    UnionFind uf(N);

    // 각 변에 대한 처리
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        uf.unite(a, b); // a를 포함하는 그룹과 b를 포함하는 그룹을 병합
    }

    // 집계
    int res = 0;
    for (int x = 0; x < N; ++x) {
        if (uf.root(x) == x) ++res;
    }
    cout << res << endl;
}
