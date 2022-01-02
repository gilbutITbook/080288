#include <iostream>
#include <vector>
using namespace std;

// 배열 a의 구간 [left, right)를 정렬하기
// [left, right)는 left, left+1, ..., right-1를 뜻함
void MergeSort(vector<int> &a, int left, int right) {
    if (right - left == 1) return;
    int mid = left + (right - left) / 2;

    // 왼쪽 반쪽 [left, mid) 정렬
    MergeSort(a, left, mid);

    // 오른쪽 반쪽 [mid, right) 정렬
    MergeSort(a, mid, right);

    // 일단 왼쪽과 오른쪽 정렬 결과를 복사해 둠(오른쪽은 좌우반전)
    vector<int> buf;
    for (int i = left; i < mid; ++i) buf.push_back(a[i]);
    for (int i = right - 1; i >= mid; --i) buf.push_back(a[i]);

    // 병합하기
    int index_left = 0;                    // 왼쪽 인덱스
    int index_right = (int)buf.size() - 1; // 오른쪽 인덱스
    for (int i = left; i < right; ++i) {
        // 왼쪽 채용
        if (buf[index_left] <= buf[index_right]) {
            a[i] = buf[index_left++];
        }
        // 오른쪽 채용
        else {
            a[i] = buf[index_right--];
        }
    }
}

int main() {
    // 입력
    int N; // 요소 개수
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // 병합 정렬
    MergeSort(a, 0, N);
}
