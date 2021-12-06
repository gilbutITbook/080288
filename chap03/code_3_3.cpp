#include <iostream>
#include <vector>
using namespace std;
const int INF = 20000000;   // 충분히 큰 값을 설정

int main() {
    // 입력
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    
    // 선형 탐색
    int min_value = INF;
    for (int i = 0; i < N; ++i) {
        if (a[i] < min_value) min_value = a[i];
    }
    
    // 결과 출력
    cout << min_value << endl;
}
