#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> ipair;

int main() {

    queue<ipair> q;
    vector<int> pq;

    int N;

    cin >> N;

    for (int i = 0; i < N; ++i) {

        int num, x;

        cin >> num >> x;

        for (int j = 0; j < num; ++j) {
            ipair tmp;

            cin >> tmp.first;
            tmp.second = j;

            q.push(tmp);
            pq.push_back(tmp.first);
        }

        sort(pq.begin(), pq.end(), greater<int>());

        int k = 0;
        while (k<pq.size()) {
            int degree = pq[k];
            ipair val = q.front(); q.pop();

            if (val.first == degree) {
                k++;

                if (val.second == x) {
                    cout << k << endl;
                    break;
                }

            } else {
                q.push(val);
            }
        }

        pq = vector<int>();
        q = queue<ipair>();

    }

    return 0;
}
