#include <iostream>
#include <vector>
using namespace std;

// 동전 금액
const vector<int> value = {500, 100, 50, 10};

int main() {
    // 입력
    int X;
    vector<int> a(4);
    cin >> X;
    for (int i = 0; i < 4; ++i) cin >> a[i];

    // 탐욕법
    int result = 0;
    for (int i = 0; i < 4; ++i) {
        // 개수 제한이 없는 경우 최대 개수
        int add = X / value[i];

        // 개수 제한을 고려
        if (add > a[i]) add = a[i];

        // 남은 금액을 계산하고 답에 사용한 동전 개수를 더하기
        X -= value[i] * add;
        result += add;
    }
    cout << result << endl;
}
