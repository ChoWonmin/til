#include <iostream>

using namespace std;

int height, width;
int map[50][50];
int sum = 0;

// 서 남 동 북
int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};

int main() {

    int r, c, dir;
    cin >> height >> width;

    cin >> r >> c >> dir;

    dir = 3-dir;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cin >> map[i][j];
        }
    }

    int y = r;
    int x = c;

    while(true) {

        int move = 0;
        map[y][x] = 2;
        sum++;

        for (int i = 0; i < 4; ++i) {

            dir = (dir+1)%4;

            int nextY = y + dy[dir];
            int nextX = x + dx[dir];

            if (nextX >= 0 && nextX < width && nextY >= 0 && nextY < height) {

                if (map[nextY][nextX] == 0) {
                    x = nextX;
                    y = nextY;
                    move = 1;
                    break;
                }

            }
        }

        if (!move) {
            int backDir = (dir+2)%4;

            int backY = y + dy[backDir];
            int backX = x + dx[backDir];

            if (!(backX >= 0 && backX < width && backY >= 0 && backY < height)) {
                break;
            } else if (map[backY][backX]==1) {
                break;
            } else {
                y = backY;
                x = backX;
                sum--;
            }
        }

    }

    cout << sum << endl;


    return 0;
}