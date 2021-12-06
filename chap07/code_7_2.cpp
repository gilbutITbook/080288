#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// 구간은 pair<int,int>로 표현
typedef pair<int,int> Interval;

// 구간을 종료 시각으로 대소를 비교하는 함수
bool cmp(const Interval &a, const Interval &b) {
    return a.second < b.second;
}

int main() {
    // 입력
    int N;
    cin >> N;
    vector<Interval> inter(N);
    for (int i = 0; i < N; ++i)
        cin >> inter[i].first >> inter[i].second;

    // 종료 시각이 빠른 순서로 정렬
    sort(inter.begin(), inter.end(), cmp);

    // 탐욕법으로 고름
    int res = 0;
    int current_end_time = 0;
    for (int i = 0; i < N; ++i) {
        // 이전에 고른 구간과 겹치면 제외
        if (inter[i].first < current_end_time) continue;

        ++res;
        current_end_time = inter[i].second;
    }
    cout << res << endl;
}
