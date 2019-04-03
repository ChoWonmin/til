#include <iostream>
#include <vector>

using namespace std;

vector<int> g[101];
int check[101];
int sum = 0;

void dfs(int v) {

    check[v] = 1;

    for (int i: g[v]) {
        if (check[i]!=1) {
            sum++;
            dfs(i);
        }
    }
}

int main() {

    int n, pn;

    cin >> n >> pn;

    for (int i = 0; i < pn; ++i) {

        int v1, v2;

        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);

    }

    dfs(1);

    cout << sum << endl;


    return 0;
}