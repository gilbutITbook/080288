#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000; // 배열에 100000 미만 값만 존재한다고 가정

// 버킷 정렬
void BucketSort(vector<int> &a) {
    int N = (int)a.size();

    // 각 요소 개수를 카운트함
    // num[v]: v 개수
    vector<int> num(MAX, 0);
    for (int i = 0; i < N; ++i) {
        ++num[a[i]]; // a[i]를 카운트
    }

    // num 누적합
    // sum[v]: v 이하 값 개수
    // a[i]가 전체에서 몇 번째로 작은 값인지 구하기
    vector<int> sum(MAX, 0);
    sum[0] = num[0];
    for (int v = 1; v < MAX; ++v) {
        sum[v] = sum[v - 1] + num[v];
    }

    // sum를 바탕으로 정렬
    // a2: a를 정렬한 것
    vector<int> a2(N);
    for (int i = N - 1; i >= 0; --i) {
        a2[--sum[a[i]]] = a[i];
    }
    a = a2;
}

int main() {
    // 입력
    int N; // 요소 개수
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // 버킷 정렬
    BucketSort(a);
}
