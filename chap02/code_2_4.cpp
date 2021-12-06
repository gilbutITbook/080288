#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 두 점 (x1, y1)과 (x2, y2) 사이 거리를 구하는 함수
double calc_dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    // 데이터를 입력 받음
    int N; cin >> N;
    vector<double> x(N), y(N);
    for (int i = 0; i < N; ++i) cin >> x[i] >> y[i];

    // 결과 값이 들어갈 변수를 초기화(결과 값 후보보다 훨씬 큰 값)
    double minimum_dist = 100000000.0;

    // 탐색 시작
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            // (x[i], y[i])와 (x[j], y[j]) 사이 거리
            double dist_i_j = calc_dist(x[i], y[i], x[j], y[j]);

            // 잠정 최솟값 minimum_dist를 dist_i_j와 비교
            if (dist_i_j < minimum_dist) {
                minimum_dist = dist_i_j;
            }
        }
    }

    // 결과 출력
    cout << minimum_dist << endl;
}
