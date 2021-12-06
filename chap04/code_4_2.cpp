#include <iostream>
using namespace std;

int func(int N) {
    // 재귀 함수를 호출한다고 출력
    cout << "func(" << N << ") 호출함" << endl;

    if (N == 0) return 0;

    // 재귀적으로 답을 구해서 출력
    int result = N + func(N - 1);
    cout << N << "까지의 합 = " << result << endl;

    return result;
}

int main() {
    func(5);
}
