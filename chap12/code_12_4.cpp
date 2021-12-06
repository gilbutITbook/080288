#include <iostream>
#include <vector>
using namespace std;

// i번째 꼭짓점을 루트로하는 부분 트리에서 힙 조건을 만족하게 만듬
// a 중에서 0번째에서 N-1번째까지 부분 a[0:N]만 고려함
void Heapify(vector<int> &a, int i, int N) {
    int child1 = i * 2 + 1; // 왼쪽 자식
    if (child1 >= N) return; // 자식이 아니면 종료

    // 자식끼리 비교
    if (child1 + 1 < N && a[child1 + 1] > a[child1]) ++child1;

    if (a[child1] <= a[i]) return; // 역전이 없으면 종료

    // swap
    swap(a[i], a[child1]);

    // 재귀적으로
    Heapify(a, child1, N);
}

// 배열 a를 정렬함
void HeapSort(vector<int> &a) {
    int N = (int)a.size();

    // 단계 1: a 전체를 힙으로 만드는 과정
    for (int i = N / 2 - 1; i >= 0; --i) {
        Heapify(a, i, N);
    }

    // 단계 2: 힙에서 하나 하나 최댓값을 pop하는 과정
    for (int i = N - 1; i > 0; --i) {
        swap(a[0], a[i]); // 힙의 최댓값을 오른쪽에 채움
        Heapify(a, 0, i); // 힙 크기를 i로
    }
}

int main() {
    // 입력
    int N; // 요소 개수
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // 힙 정렬
    HeapSort(a);
}
