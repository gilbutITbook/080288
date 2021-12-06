#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {4, 3, 12, 7, 11, 1, 9, 8, 14, 6};

    // 0번째 요소를 출력(4)
    cout << a[0] << endl;

    // 2번째 요소를 출력(12)
    cout << a[2] << endl;

    // 2번째 요소를 5로 교체
    a[2] = 5;

    // 2번째 요소를 출력(5)
    cout << a[2] << endl;
}
