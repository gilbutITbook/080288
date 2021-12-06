#include <iostream>
using namespace std;

// x가 조건을 만족하는지 여부
bool P(int x) {

}

// P(x) = true가 되는 최소 정수 x를 반환
int binary_search() {
    // P(left) = false, P(right) = true가 되도록 함
    int left, right;

    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (P(mid)) right = mid;
        else left = mid;
    }
    return right;
}
