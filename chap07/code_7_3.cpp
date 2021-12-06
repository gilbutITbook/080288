#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 입력
    int N;
    cin >> N;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i] >> B[i];

    // 답
    long long sum = 0;
    for (int i = N - 1; i >= 0; --i) {
        A[i] += sum; // 전회까지의 작업 횟수를 더함
        long long amari = A[i] % B[i];
        long long D = 0;
        if (amari != 0) D = B[i] - amari;
        sum += D;
    }
    cout << sum << endl;
}
