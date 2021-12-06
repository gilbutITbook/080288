#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 연결 리스트의 각 노드를 가리키는 구조체
struct Node {
    Node* next; // 다음 노드를 지정
    string name; // 노드에 저장하는 값

    Node(string name_ = "") : next(NULL), name(name_) { }
};

// 감시 노드를 전역 변수로 지정
Node* nil;

// 초기화
void init() {
    nil = new Node();
    nil->next = nil; // 초기 상태는 nil이 nil을 가리킴
}

// 연결 리스트 출력
void printList() {
    Node* cur = nil->next; // 선두부터 출발
    for (; cur != nil; cur = cur->next) {
        cout << cur->name << " -> ";
    }
    cout << endl;
}

// 노드 p 직후에 노드 v를 삽입
// 노드 p 기본 인수를 nil로 지정
// 따라서 insert(v)를 호출하면 리스트 선두에 삽입이 됨
void insert(Node* v, Node* p = nil) {
    v->next = p->next;
    p->next = v;
}

int main() {
    // 초기화
    init();

    // 만들고 싶은 노드명 목록
    // 마지막 노드(백호)부터 순서대로 삽입하므로 주의
    vector<string> names = {"bakho",
                            "myongjin",
                            "rangi",
                            "daeho",
                            "nara",
                            "gildong"};

    // 각 노드를 생성하고 연결 리스트 선두에 삽입함
    for (int i = 0; i < (int)names.size(); ++i) {
        // 노드 작성
        Node* node = new Node(names[i]);

        // 작성한 노드를 연결 리스트 선두에 삽입
        insert(node);

        // 각 단계의 연결 리스트 상황을 출력
        cout << "step " << i << ": ";
        printList();
    }
}
