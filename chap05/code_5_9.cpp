#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}

const long long INF = 1LL << 60; // 충분히 큰 값(여기서는 2^60)

int main() {
    // 입력
    int N;
    cin >> N;
    vector<vector<long long>> c(N + 1, vector<long long>(N + 1));
    for (int i = 0; i < N + 1; ++i) {
        for (int j = 0; j < N + 1; ++j) {
            cin >> c[i][j];
        }
    }
    
    // DP 테이블 정의
    vector<long long> dp(N + 1, INF);
    
    // DP 초기 조건
    dp[0] = 0;

    // DP 반복
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j < i; ++j) {
            chmin(dp[i], dp[j] + c[j][i]);
        }
    }
    
    // 답 출력
    cout << dp[N] << endl;
}
