#include <iostream>
using namespace std;


int n;
int square[20][20];

void makesquare() {

    int r = 0, c = n / 2, num = 1;


    while (num <= n * n) {
        square[r][c] = num;

 
        int nr = (r - 1 + n) % n;
        int nc = (c + 1) % n;


        if (square[nr][nc] != 0) {

            r = (r + 1) % n;
        }
        else {
            r = nr;
            c = nc;
        }

        num++;
    }
}

void printsquare() {
    cout << "������ ��ĸ� �Դϴ�:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << square[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "������ ������ ũ�⸦ �Է��Ͻÿ� (Ȧ����): ";
    cin >> n;

    if (n % 2 == 0) {
        cout << "¦���Դϴ�. " << endl;
        return 1;
    }

    makesquare();
    printsquare();

    return 0;
}
