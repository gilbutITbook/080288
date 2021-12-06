#include <iostream>
#include <vector>
using namespace std;

// 그래프를 나타내는 구조체
struct Graph {
    // 변을 나타내는 구조체
    // rev: 역변 (to, from)이 G[to]에서 몇 번째 요소인가
    // cap: 변 (from, to) 용량
    struct Edge {
        int rev, from, to, cap;
        Edge(int r, int f, int t, int c) :
            rev(r), from(f), to(t), cap(c) {}
    };

    // 인접 리스트
    vector<vector<Edge>> list;

    // N: 꼭짓점 개수
    Graph(int N = 0) : list(N) { }

    // 그래프 꼭짓점 개수 취득
    size_t size() {
        return list.size();
    }

    // Graph 인스턴스를 G라고 하면
    // G.list[v]를 G[v]라고 표현 가능하게 만듬
    vector<Edge> &operator [] (int i) {
        return list[i];
    }

    // 변 e = (u, v)의 역변 (v, u)를 취득
    Edge& redge(const Edge &e) {
        return list[e.to][e.rev];
    }

    // 변 e = (u, v)에 유량 f의 흐름을 흘리면
    // e = (u, v) 유량이 f만큼 감소함
    // 이때 역변 (v, u)의 유량을 증가시킴
    void run_flow(Edge &e, int f) {
        e.cap -= f;
        redge(e).cap += f;
    }

    // 꼭짓점 from에서 꼭짓점 to를 향해 용량 cap인 변을 잇고
    // 이때 to에서 from으로도 용량 0인 변을 연결함
    void addedge(int from, int to, int cap) {
        int fromrev = (int)list[from].size();
        int torev = (int)list[to].size();
        list[from].push_back(Edge(torev, from, to, cap));
        list[to].push_back(Edge(fromrev, to, from, 0));
    }
};

struct FordFulkerson {
    static const int INF = 1 << 30; // 적절하게 고른 무한대를 뜻하는 값
    vector<int> seen;

    FordFulkerson() { }

    // 잔여 그래프 위에 s-t 패스를 찾기(깊이 우선 탐색)
    // 반환값은 s-t 패스에서 용량의 최솟값(찾지 못한 경우는 0)
    // f: s에서 v로 도착하는 과정의 각 변 용량의 최솟값
    int fodfs(Graph &G, int v, int t, int f) {
        // 끝점 t에 도달하면 반환
        if (v == t) return f;

        // 깊이 우선 탐색
        seen[v] = true;
        for (auto &e : G[v]) {
            if (seen[e.to]) continue;

            // 용량 0인 변은 실제로는 존재하지 않음
            if (e.cap == 0) continue;

            // s-t 패스 찾기
            // 찾으면 flow는 패스 위의 최소 용량
            // 찾지 못하면 f = 0
            int flow = fodfs(G, e.to, t, min(f, e.cap));

            // s-t 패스를 찾지 못하면 다음 변을 탐색
            if (flow == 0) continue;

            // 변 e에 용량 flow인 흐름을 흘려 보내기
            G.run_flow(e, flow);

            // s-t 패스를 찾으면 패스의 최소 용량을 반환
            return flow;
        }

        // s-t 패스를 찾지 못했을 때
        return 0;
    }

    // 그래프 G의 s-t 사이의 최대 유량을 구하기
    // 단, 반환시 G는 잔여 그래프가 됨
    int solve(Graph &G, int s, int t) {
        int res = 0;

        // 잔여 그래프에 s-t 패스가 없어질 때까지 반복
        while (true) {
            seen.assign((int)G.size(), 0);
            int flow = fodfs(G, s, t, INF);

            // s-t 패스를 찾지 못하면 종료
            if (flow == 0) return res;

            // 답을 더하기
            res += flow;
        }

        // no reach
        return 0;
    }
};

int main() {
    // 그래프 입력
    // N: 꼭짓점 개수, M: 변 개수
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int u, v, c;
        cin >> u >> v >> c;

        // 용량 c인 변 (u, v)를 잇기
        G.addedge(u, v, c);
    }

    // 포드-풀커슨 알고리즘
    FordFulkerson ff;
    int s = 0, t = N - 1;
    cout << ff.solve(G, s, t) << endl;
}
