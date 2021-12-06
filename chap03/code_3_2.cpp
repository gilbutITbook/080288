#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 입력
    int N, v;
    cin >> N >> v;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // 선형 탐색
    int found_id = -1; // 존재할 수 없는 값인 -1로 초기화
    for (int i = 0; i < N; ++i) {
        if (a[i] == v) {
            found_id = i; // 발견하면 인덱스를 저장
            break; // 반복문 종료
        }
    }

    // 결과 출력(-1이라면 값이 존재하지 않음을 뜻함)
    cout << found_id << endl;
}
