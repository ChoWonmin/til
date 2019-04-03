#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[101][101];
int width, height, rectNum;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int seg = 1;
int sum = 0;

void dfs(int x, int y) {

    map[y][x] = seg;
    sum++;

    for (int i = 0; i < 4; ++i) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (nextX >= 0 && nextX < width && nextY>=0 && nextY<height) {

            if (map[nextY][nextX]==0) {
                dfs(nextX, nextY);
            }
        }


    }

}

int main() {

    vector<int> list;

    cin >> height >> width >> rectNum;

    for (int i = 0; i < rectNum; ++i) {

        int x0, y0, x1, y1;

        cin >> x0 >> y0 >> x1 >> y1;

        for (int j = y0; j < y1; ++j) {
            for (int k = x0; k < x1; ++k) {
                map[j][k] = -1;
            }
        }
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {

            if (map[i][j]==0) {
                dfs(j, i);
                list.push_back(sum);
                sum = 0;
            }

        }
    }

    sort(list.begin(), list.end());

    cout << list.size() << endl;
    for (int x:list) {
        cout << x << " ";
    }

    return 0;
}