#include <iostream>
#include <vector>
using namespace std;

// 무한대를 나타내는 값
const long long INF = 1LL << 60;

int main() {
    // 꼭짓점 개수, 변 개수
    int N, M;
    cin >> N >> M;

    // dp 배열(INF로 초기화)
    vector<vector<long long>> dp(N, vector<long long>(N, INF));

    // dp 초기 조건
    for (int e = 0; e < M; ++e) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        dp[a][b] = w;
    }
    for (int v = 0; v < N; ++v) dp[v][v] = 0;

    // dp 천이(플로이드 워셜 알고리즘)
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

    // 결과 출력
    // 만약 dp[v][v] < 0라면 음의 닫힌 경로가 존재함
    bool exist_negative_cycle = false;
    for (int v = 0; v < N; ++v) {
        if (dp[v][v] < 0) exist_negative_cycle = true;
    }
    if (exist_negative_cycle) {
        cout << "NEGATIVE CYCLE" << endl;
    }
    else {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (j) cout << " ";
                if (dp[i][j] < INF/2) cout << dp[i][j];
                else cout << "INF";
            }
            cout << endl;
        }
    }                              
}
