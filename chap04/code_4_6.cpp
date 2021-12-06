#include <iostream>
using namespace std;

int fibo(int N) {
    cout << "fibo(" << N << ") 호출" << endl;

    // 베이스 케이스
    if (N == 0) return 0;
    else if (N == 1) return 1;

    // 재귀적으로 답을 구해서 출력
    int result = fibo(N - 1) + fibo(N - 2);
    cout << N << " 번째 = " << result << endl;

    return result;
}

int main() {
    fibo(6);
}
