int root(int x) {
    if (par[x] == -1) return x; // x가 루트라면 x를 반환
    else return par[x] = root(par[x]); // x의 부모 par[x]를 루트에 설정
}
