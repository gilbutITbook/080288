#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000; // 큐 배열 최대 크기

int qu[MAX]; // 큐를 가리키는 배열
int tail = 0, head = 0; // 큐의 요소 구간을 나타내는 변수

// 큐 초기화
void init() {
    head = tail = 0;
}

// 큐가 비어 있는지 판정
bool isEmpty() {
    return (head == tail);
}

// 큐가 가득찼는지 판정
bool isFull() {
    return (head == (tail + 1) % MAX);
}

// enqueue
void enqueue(int x) {
    if (isFull()) {
        cout << "error: queue is full." << endl;
        return;
    }
    qu[tail] = x;
    ++tail;
    if (tail == MAX) tail = 0; // 링버퍼 끝에 도달했으면 0
}

// dequeue
int dequeue() {
    if (isEmpty()) {
        cout << "error: queue is empty." << endl;
        return -1;
    }
    int res = qu[head];
    ++head;
    if (head == MAX) head = 0; // 링버퍼 끝에 도달했으면 0
    return res;
}

int main() {
    init(); // 큐 초기화

    enqueue(3); // 큐에 3 삽입 {} -> {3}
    enqueue(5); // 큐에 5 삽입 {3} -> {3, 5}
    enqueue(7); // 큐에 7 삽입 {3, 5} -> {3, 5, 7}

    cout << dequeue() << endl; // {3, 5, 7} -> {5, 7}이 되고 3 출력
    cout << dequeue() << endl; // {5, 7} -> {7}이 되고 5 출력

    enqueue(9); // 새로 9 삽입 {7} -> {7, 9}
}
