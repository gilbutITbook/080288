#include <iostream>
#include <vector>
using namespace std;

struct Heap {
    vector<int> heap;
    Heap() {}

    // 힙에 값 x 삽입
    void push(int x) {
        heap.push_back(x); // 마지막에 삽입
        int i = (int)heap.size() - 1; // 삽입한 꼭짓점 번호
        while (i > 0) {
            int p = (i - 1) / 2; // 부모 꼭짓점 번호
            if (heap[p] >= x) break; // 역전이 아니라면 종료
            heap[i] = heap[p]; // 부모에 자기 값 넣기
            i = p; // 위로 가기
        }
        heap[i] = x; // x는 최종적으로 이 위치가 됨
    }

    // 최댓값
    int top() {
        if (!heap.empty()) return heap[0];
        else return -1;
    }

    // 최댓값 삭제
    void pop() {
        if (heap.empty()) return;
        int x = heap.back(); // 꼭짓점에 가지고 올 값
        heap.pop_back();
        int i = 0; // 루트에서 시작
        while (i * 2 + 1 < (int)heap.size()) {
            // 자식 꼭짓점끼리 비교해서 큰 쪽이 child1
            int child1 = i * 2 + 1, child2 = i * 2 + 2;
            if (child2 < (int)heap.size()
                && heap[child2] > heap[child1]) {
                child1 = child2;
            }
            if (heap[child1] <= x) break; // 역전이 아니라면 종료
            heap[i] = heap[child1]; // 자식에 자기 값 넣기
            i = child1; // 아래로 가기
        }
        heap[i] = x; // x는 최종적으로 이 위치가 됨
    }
};

int main() {
    Heap h;
    h.push(5), h.push(3), h.push(7), h.push(1);

    cout << h.top() << endl; // 7
    h.pop();
    cout << h.top() << endl; // 5

    h.push(11);
    cout << h.top() << endl; // 11
}
