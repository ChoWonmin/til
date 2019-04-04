/*
 * 2644번 촌수계산
 * wonmin
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> graph[101];
queue<int> q;
int visit[101];

void bfs(int start) {
    q.push(start);
    visit[start] = 1;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (int i = 0; i < graph[front].size(); ++i) {

            int next = graph[front][i];

            if (visit[next]==0) {
                visit[next] = visit[front]+1;
                q.push(next);
            }
        }

    }

}

int main() {
    
    int N, num, x, y;
    
    cin >> N;
    cin >> x >> y;
    cin >> num;

    for (int i = 0; i < num; ++i) {
        int v1, v2;

        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    bfs(x);

    cout << visit[y] - 1 << endl;
    
    
    return 0;
}