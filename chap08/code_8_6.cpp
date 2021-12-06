#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 연결 리스트의 각 노드를 가리키는 구조체
struct Node {
    Node *prev, *next;
    string name; // 노드에 저장하는 값

    Node(string name_ = "") :
    prev(NULL), next(NULL), name(name_) { }
};

// 감시 노드를 전역 변수로 설정
Node* nil;

// 초기화
void init() {
    nil = new Node();
    nil->prev = nil;
    nil->next = nil;
}

// 연결 리스트를 출력
void printList() {
    Node* cur = nil->next; // 선두부터 출발
    for (; cur != nil; cur = cur->next) {
        cout << cur->name << " -> ";
    }
    cout << endl;
}

// 노드 p 직후에 노드 v 삽입
void insert(Node* v, Node* p = nil) {
    v->next = p->next;
    p->next->prev = v;
    p->next = v;
    v->prev = p;
}

// 노드 v 삭제
void erase(Node *v) {
    if (v == nil) return; // v가 감시 노드이면 아무 것도 하지 않음
    v->prev->next = v->next;
    v->next->prev = v->prev;
    delete v; // 메모리 해방
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

    // 연결 리스트 작성: 각 노드를 생성해서 연결 리스트 선두에 삽입
    Node *myongjin;
    for (int i = 0; i < (int)names.size(); ++i) {
        // 노드 작성
        Node* node = new Node(names[i]);

        // 작성한 노드를 연결 리스트 선두에 삽입
        insert(node);

        // 명진 노드를 저장
        if (names[i] == "myongjin") myongjin = node;
    }

    // 명진 노드 삭제
    cout << "before: ";
    printList(); // 삭제 전에 출력
    erase(myongjin);
    cout << "after: ";
    printList(); // 삭제 후에 출력
}
