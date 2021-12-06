#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}

const int INF = 1 << 29; // 충분히 큰 값(여기서는 2^29)

int main() {
    // 입력
    string S, T;
    cin >> S >> T;

    // DP 테이블 정의
    vector<vector<int>> dp(S.size() + 1, vector<int>(T.size() + 1, INF));

    // DP 초기 조건
    dp[0][0] = 0;

    // DP 반복
    for (int i = 0; i <= S.size(); ++i) {
        for (int j = 0; j <= T.size(); ++j) {
            // 대체
            if (i > 0 && j > 0) {
                if (S[i - 1] == T[j - 1]) {
                    chmin(dp[i][j], dp[i - 1][j - 1]);
                }
                else {
                    chmin(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }

            // 삭제
            if (i > 0) chmin(dp[i][j], dp[i - 1][j] + 1);

            // 삽입
            if (j > 0) chmin(dp[i][j], dp[i][j - 1] + 1);
        }
    }

    // 답 출력
    cout << dp[S.size()][T.size()] << endl;
}
