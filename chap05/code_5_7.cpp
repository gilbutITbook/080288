#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}

int main() {
    // 입력
    int N;
    long long W;
    cin >> N >> W;
    vector<long long> weight(N), value(N);
    for (int i = 0; i < N; ++i) cin >> weight[i] >> value[i];

    // DP 테이블 정의
    vector<vector<long long>> dp(N + 1, vector<long long>(W + 1, 0));

    // DP 반복
    for (int i = 0; i < N; ++i) {
        for (int w = 0; w <= W; ++w) {

            // i번째 물건을 선택한 경우
            if (w - weight[i] >= 0) {
                chmax(dp[i + 1][w], dp[i][w - weight[i]] + value[i]);
            }

            // i번째 물건을 선택하지 않은 경우
            chmax(dp[i + 1][w], dp[i][w]);
        }
    }

    // 최적값 출력
    cout << dp[N][W] << endl;
}
