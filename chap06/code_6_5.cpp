#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // 입력
    int N;
    cin >> N;
    vector<long long> H(N), S(N);
    for (int i = 0; i < N; i++) cin >> H[i] >> S[i];

    // 이진 탐색 상한값을 구함
    long long M = 0;
    for (int i = 0; i < N; ++i) M = max(M, H[i] + S[i] * N);

    // 이진탐색
    long long left = 0, right = M;
    while (right - left > 1) {
        long long mid = (left + right) / 2;

        // 판정
        bool ok = true;
        vector<long long> t(N, 0);  // 각 풍선이 터질 때까지 제한 시간
        for (int i = 0; i < N; ++i) {
            // mid가 초기 높이보다 낮으면 false
            if (mid < H[i]) ok = false;
            else t[i] = (mid - H[i]) / S[i];
        }
        // 시간 제한이 얼마 남지 않은 순서로 정렬
        sort(t.begin(), t.end());
        for (int i = 0; i < N; ++i) {
            // 제한 시간 초과가 발생하면 false
            if (t[i] < i) ok = false;
        }

        if (ok) right = mid;
        else left = mid;
    }

    cout << right << endl;
}
