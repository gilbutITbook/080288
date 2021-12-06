#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}

const long long INF = 1LL << 60; // 충분히 큰 값(여기서는 2^60)

// 입력 데이터와 메모용 DP 테이블
int N;
vector<long long> h;
vector<long long> dp;

long long rec(int i) {
    // DP 값이 갱신되어 있으면 그대로 반환
    if (dp[i] < INF) return dp[i];

    // 베이스 케이스: 발판 0의 비용은 0
    if (i == 0) return 0;

    // 답을 나타내는 변수를 INF로 초기화
    long long res = INF;

    // 발판 i-1에서 온 경우
    chmin(res, rec(i - 1) + abs(h[i] - h[i - 1]));

    // 발판 i-2에서 온 경우
    if (i > 1) {
        chmin(res, rec(i - 2) + abs(h[i] - h[i - 2]));
    }

    // 결과를 메모하고 반환
    return dp[i] = res;
}

int main() {
    // 입력
    cin >> N;
    h.resize(N);
    for (int i = 0; i < N; ++i) cin >> h[i];

    // 초기화(최소화 문제이므로 INF로 초기화)
    dp.assign(N, INF);

    // 답
    cout << rec(N - 1) << endl;
}
