#include <iostream>
#include <vector>
using namespace std;

// Union-Find
struct UnionFind {
    vector<int> par, siz;

    // 초기화
    UnionFind(int n) : par(n, -1) , siz(n, 1) { }

    // 루트를 구함
    int root(int x) {
        if (par[x] == -1) return x; // x가 루트이면 x를 반환
        else return par[x] = root(par[x]);
    }

    // x와 y가 같은 그룹에 속해 있는가(루트가 일치하는가)
    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    // x를 포함한 그룹과 y를 포함한 그룹을 병합함
    bool unite(int x, int y) {
        // x, y를 각각 루트까지 이동시킴
        x = root(x);
        y = root(y);

        // 이미 같은 그룹이라면 아무 것도 안함
        if (x == y) return false;

        // union by size (y쪽이 크기가 작도록 만들기)
        if (siz[x] < siz[y]) swap(x, y);

        // y를 x의 자식으로 만들기
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // x를 포함한 그룹 크기
    int size(int x) {
        return siz[root(x)];
    }
};

int main() {
    UnionFind uf(7); // {0}, {1}, {2}, {3}, {4}, {5}, {6}

    uf.unite(1, 2); // {0}, {1, 2}, {3}, {4}, {5}, {6}
    uf.unite(2, 3); // {0}, {1, 2, 3}, {4}, {5}, {6}
    uf.unite(5, 6); // {0}, {1, 2, 3}, {4}, {5, 6}
    cout << uf.issame(1, 3) << endl; // True
    cout << uf.issame(2, 5) << endl; // False

    uf.unite(1, 6); // {0}, {1, 2, 3, 5, 6}, {4}
    cout << uf.issame(2, 5) << endl; // True
}
