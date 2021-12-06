// 노드 p 직후에 노드 v를 삽입
void insert(Node* v, Node* p) {
    v->next = p->next;
    p->next = v;
}
