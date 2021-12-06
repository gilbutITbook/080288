struct Node {
    Node* next; // 다음이 어떤 노드를 가리키는가
    string name; // 노드에 저장된 값

    Node(string name_ = "") : next(NULL), name(name_) { }
};
