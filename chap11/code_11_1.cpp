int root(int x) {
    if (par[x] == -1) return x; // x가루트라면 x를 직접 반환
    else return root(par[x]); // x가 루트가 아니면 재귀적으로 진행
}
