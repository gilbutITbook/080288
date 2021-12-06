#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using Graph = vector<vector<int>>;

// 입력
int N; // 꼭짓점 개수
vector<long long> w; // 각 꼭짓점의 가중치
Graph G; // 그래프

// 트리의 동적 계획법 테이블
vector<int> dp1, dp2;

void dfs(int v, int p = -1) {
    // 최초로 각 자식 꼭짓점을 탐색함
    for (auto ch : G[v]) {
        if (ch == p) continue;
        dfs(ch, v);
    }

    // 후위 순회시에 동적 계획법
    dp1[v] = 0, dp2[v] = w[v]; // 초기 조건
    for (auto ch : G[v]) {
        if (ch == p) continue;
        dp1[v] += max(dp1[ch], dp2[ch]);
        dp2[v] += dp1[ch];
    }
}

int main() {
    // 꼭짓점 개수(트리이므로 변 개수는 N -1)
    cin >> N;

    // 가중치와 그래프를 입력 받음
    w.resize(N);
    for (int i = 0; i < N; ++i) cin >> w[i];
    G.clear(); G.resize(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 탐색
    int root = 0; // 임시로 꼭짓점 0을 루트로
    dp1.assign(N, 0), dp2.assign(N, 0);
    dfs(root);

    // 결과
    cout << max(dp1[root], dp2[root]) << endl;
}
