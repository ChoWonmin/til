#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> graph[20001];
int visit[20001];
bool no = 0;

void dfs(int root, int flag) {

    visit[root] = flag;

    for (int next: graph[root]) {

        if (visit[next]==0) {
            dfs(next, -flag);
        } else if (visit[next]==flag){
            no = 1;
            break;
        }

    }
}

int main() {
    int K;

    cin >> K;

    for (int i = 0; i < K; ++i) {

        int N, M;

        cin >> N >> M;

        for (int j = 0; j < M; ++j) {
            int v1, v2;

            cin >> v1 >> v2;

            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }

        for (int i = 1; i <= N; ++i) {
            if (visit[i]==0) {
                dfs(i,1);

                if (no) break;
            }

        }

        string res = no?"NO":"YES";
        cout << res << endl;

        no = 0;
        for (int i = 0; i < 20001; ++i) {
            graph[i].clear();
            visit[i] = 0;
        }

    }

    return 0;
}