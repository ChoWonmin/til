#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> g[101];

int visit[101];
int sum = 1;

void dfs(int v, bool up) {
    visit[v] = 1;

    for (pair<int,int> next: g[v]) {
        int x = up?next.first:next.second;

        if (visit[x]!=1) {
            sum++;
            dfs(x, up);
        }
    }
}

int main() {

    int n, ordersNum;

    cin >> n >> ordersNum;

    for (int i = 0; i < ordersNum; ++i) {
        pair<int, int> order;

        cin >> order.first >> order.second;

        g[order.first].push_back(order);
        g[order.second].push_back(order);
    }

    for (int i = 1; i <= n; ++i) {
        dfs(i, 1);
        dfs(i, 0);

        cout << n - sum << endl;

        fill_n(visit, 101, 0);
        sum = 1;
    }


    return 0;
}