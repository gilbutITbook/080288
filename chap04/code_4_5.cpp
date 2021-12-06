int fibo(int N) {
    // 베이스 케이스
    if (N == 0) return 0;
    else if (N == 1) return 1;

    // 재귀 호출
    return fibo(N - 1) + fibo(N - 2);
}
