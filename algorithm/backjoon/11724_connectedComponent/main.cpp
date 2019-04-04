#include <iostream>

using namespace std;

int map[9][9];

int heigth, width;




int main() {


    cin >> heigth >> width;

    for (int i = 0; i < heigth; ++i) {
        for (int j = 0; j < width; ++j) {
            cin >> map[i][j];
        }
    }


    return 0;
}