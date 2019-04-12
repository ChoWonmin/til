#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> graph[1001];
int visit[1001];

void dfs(int v) {

    visit[v] = 1;
    cout << v << " ";

    sort(graph[v].begin(), graph[v].end());
    for (int i = 0; i < graph[v].size(); ++i) {

        int nextV = graph[v][i];

        if (visit[nextV]==0) {
            dfs(nextV);
        }


    }

}
void bfs(int root) {
    queue<int> q;

    q.push(root);
    visit[root] = 1;

    while (!q.empty()) {
        int v = q.front(); q.pop();
        cout << v << " ";



        sort(graph[v].begin(), graph[v].end());
        for (int next: graph[v]) {
            if (visit[next]==0) {
                visit[next] = 1;
                q.push(next);
            }


        }



    }




}


    int main() {

    int N, M, V;

    cin >> N >> M >> V;

    for (int i = 0; i < M; ++i) {
        int v1, v2;

        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    dfs(V);
    cout << endl;
    for (int i = 0; i < 1001; ++i) {
        visit[i] = 0;
    }

    bfs(V);



    return 0;
}