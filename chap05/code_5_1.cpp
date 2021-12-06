#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL << 60; // 충분히 큰 값을 설정(여기서는 2^60)

int main() {
    // 입력
    int N; cin >> N;
    vector<long long> h(N);
    for (int i = 0; i < N; ++i) cin >> h[i];

    // 배열 dp를 정의(배열 전체를 무한대를 의미하는 값으로 초기화)
    vector<long long> dp(N, INF);

    // 초기 조건
    dp[0] = 0;

    // 반복
    for (int i = 1; i < N; ++i) {
        if (i == 1) dp[i] = abs(h[i] - h[i - 1]);
        else dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]),
                         dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    // 답
    cout << dp[N - 1] << endl;
}
