#include <iostream>
#include <vector>
using namespace std;
const int INF = 20000000;   // 충분히 큰 값

int main() {
    // 입력
    int N, K;
    cin >> N >> K;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) cin >> b[i];

    // 선형 탐색
    int min_value = INF;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // 값이 K 미만이면 건너뛰기
            if (a[i] + b[j] < K) continue;

            // 최솟값 갱신
            if (a[i] + b[j] < min_value) {
                min_value = a[i] + b[j];
            }
        }
    }

    // 결과 출력
    cout << min_value << endl;
}
