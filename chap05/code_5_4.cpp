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
    int N; cin >> N;
    vector<long long> h(N);
    for (int i = 0; i < N; ++i) cin >> h[i];

    // 초기화(최소화 문제이므로 무한대로 초기화)
    vector<long long> dp(N, INF);

    // 초기 조건
    dp[0] = 0;

    // 반복
    for (int i = 0; i < N; ++i) {
        if (i + 1 < N) {
            chmin(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
        }
        if (i + 2 < N) {
            chmin(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
        }
    }

    // 답
    cout << dp[N - 1] << endl;
}
