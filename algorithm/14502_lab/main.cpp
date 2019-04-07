#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ipair;

int height, width;
int origin[9][9];
int map[9][9];
int visit[9][9];

int dy[4] = {1, 0, 0, -1};
int dx[4] = {0, 1, -1, 0};

vector<ipair> virusList;

void dfs(int y, int x) {
    visit[y][x] = 1;

    for (int i = 0; i < 4; ++i) {

        int nextY = y + dy[i];
        int nextX = x + dx[i];

        if (nextX > 0 && nextX <= width && nextY > 0 && nextY <= height) {

            if (visit[nextY][nextX]==0 && map[nextY][nextX]==0) {
                map[nextY][nextX] = 2;
                dfs(nextY, nextX);
            }
        }

    }
}

void copy() {

    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= width; ++j) {
            map[i][j] = origin[i][j];
            visit[i][j] = 0;
        }
    }

}

int calcSafeArea() {
    int sum = 0;

    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= width; ++j) {

            if (map[i][j]==0)
                sum++;
        }
    }

    return sum;

}

int main() {

    vector<ipair> positions;
    int max = 0;

    cin >> height >> width;

    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= width; ++j) {
            cin >> origin[i][j];

            if (origin[i][j]==2)
                virusList.push_back(ipair(i,j));
            else if (origin[i][j]==0)
                positions.push_back(ipair(i,j));
        }
    }


    for (int i = 0; i < positions.size(); ++i) {
        for (int j = i+1; j < positions.size(); ++j) {
            for (int k = j+1; k < positions.size(); ++k) {
                ipair val1 = positions[i];
                ipair val2 = positions[j];
                ipair val3 = positions[k];
                copy();
                map[val1.first][val1.second] = 1;
                map[val2.first][val2.second] = 1;
                map[val3.first][val3.second] = 1;

                for (ipair virus: virusList) {
                    dfs(virus.first, virus.second);
                }

                int res = calcSafeArea();

                if (max<res)
                    max = res;

            }
        }
    }

    cout << max << endl;

    return 0;
}