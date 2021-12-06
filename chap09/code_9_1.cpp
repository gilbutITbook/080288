#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000; // 스택 배열 최대 크기

int st[MAX]; // 스택을 나타내는 배열
int top = 0; // 스택 선두를 나타내는 인덱스

// 스택 초기화
void init() {
    top = 0; // 스택 인덱스를 초기 위치로
}

// 비어 있는 스택인지 판정
bool isEmpty() {
    return (top == 0); // 스택 크기가 0인가
}

// 스택이 가득 찼는지 판정
bool isFull() {
    return (top == MAX); // 스택 크기가 MAX인가
}

// push
void push(int x) {
    if (isFull()) {
        cout << "error: stack is full." << endl;
        return;
    }
    st[top] = x; // x 저장
    ++top; // top 증가
}

// pop
int pop() {
    if (isEmpty()) {
        cout << "error: stack is empty." << endl;
        return -1;
    }
    --top; // top 감소
    return st[top]; // top 위치에 있는 값을 돌려줌
}

int main() {
    init(); // 스택 초기화

    push(3); // 스택에 3 삽입 {} -> {3}
    push(5); // 스택에 5 삽입 {3} -> {3, 5}
    push(7); // 스택에 7 삽입 {3, 5} -> {3, 5, 7}

    cout << pop() << endl; // {3, 5, 7} -> {3, 5}가 되고 7을 출력
    cout << pop() << endl; // {3, 5} -> {3}이 되고 5를 출력

    push(9); // 새롭게 9 삽입 {3} -> {3, 9}
}
