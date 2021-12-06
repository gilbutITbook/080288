#include <iostream>
#include <vector>
using namespace std;

// fibo(N) 답을 메모하는 배열
vector<long long> memo;

long long fibo(int N) {
    // 베이스 케이스
    if (N == 0) return 0;
    else if (N == 1) return 1;

    // 메모 확인(이미 계산한 값이면 반환)
    if (memo[N] != -1) return memo[N];

    // 답을 메모하면서 재귀 호출
    return memo[N] = fibo(N - 1) + fibo(N - 2);
}

int main() {
    // 메모이제이션할 배열을 -1로 초기화
    memo.assign(50, -1);

    // fibo(49) 호출
    fibo(49);

    // memo[0], ..., memo[49]에 답이 저장됨
    for (int N = 2; N < 50; ++N) {
        cout << N << " 항째: " << memo[N] << endl;
    }
}
