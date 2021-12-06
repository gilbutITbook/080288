struct Node {
    Node *prev, *next;
    string name; // 노드에 저장된 값

    Node(string name_ = "") :
    prev(NULL), next(NULL), name(name_) { }
};
