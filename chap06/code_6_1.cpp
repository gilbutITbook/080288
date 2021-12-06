#include <iostream>
#include <vector>
using namespace std;

const int N = 8;
const vector<int> a = {3, 5, 8, 10, 14, 17, 21, 39};

// 찾고 싶은 key 값의 인덱스 반환(존재하지 않으면 -1)
int binary_search(int key) {
    int left = 0, right = (int)a.size() - 1; // 배열 a 왼쪽과 오른쪽
    while (right >= left) {
        int mid = left + (right - left) / 2; // 중간
        if (a[mid] == key) return mid;
        else if (a[mid] > key) right = mid - 1;
        else if (a[mid] < key) left = mid + 1;
    }
    return -1;
}

int main() {
    cout << binary_search(10) << endl; // 3
    cout << binary_search(3) << endl; // 0
    cout << binary_search(39) << endl; // 7

    cout << binary_search(-100) << endl; // -1
    cout << binary_search(9) << endl; // -1
    cout << binary_search(100) << endl; // -1
}
