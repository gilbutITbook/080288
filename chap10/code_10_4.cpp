#include <iostream>
#include <vector>
using namespace std;

// 가중치를 나타내는 자료형은 long long형
struct Edge {
    int to; // 인접 꼭짓점 번호
    long long w; // 가중치
    Edge(int to, long long w) : to(to), w(w) {}
};

// 각 꼭짓점의 인접 리스트를 변 집합으로 나타냄
using Graph = vector<vector<Edge>>;

int main() {
    // 꼭짓점 개수와 변 개수
    int N, M;
    cin >> N >> M;

    // 그래프
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }
}
