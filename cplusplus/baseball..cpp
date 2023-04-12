#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool isDuplicate(int num[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (num[i] == value) {
            return true;
        }
    }
    return false;
}

int main() {
    srand(time(0)); // 난수 생성

    int answer[3]; // 컴퓨터가 생각한 답
    int guess[3]; // 플레이어의 추측
    int tries = 0; // 시도 횟수
    int strike = 0; // 스트라이크 수
    int ball = 0; // 볼 수

    // 컴퓨터가 3개의 서로 다른 숫자(0-9)를 랜덤으로 생성
    for (int i = 0; i < 3; i++) {
        answer[i] = rand() % 10;
        for (int j = 0; j < i; j++) {
            while (answer[i] == answer[j]) {
                answer[i] = rand() % 10;
                j = 0;
            }
        }
    }

    cout << "숫자 야구 게임을 시작합니다!" << endl;

    do {
        bool duplicate = true;
        // 플레이어의 추측 입력받기
        while (duplicate) {
            duplicate = false;
            cout << "숫자 3개를 입력하세요(0-9): ";
            cin >> guess[0] >> guess[1] >> guess[2];
            for (int i = 0; i < 2; i++) {
                if (isDuplicate(guess, i, guess[i])) {
                    cout << "중복된 숫자를 입력하셨습니다. 다시 입력하세요." << endl;
                    duplicate = true;
                    break;
                }
            }
        }

        // 스트라이크와 볼 수 계산
        strike = 0;
        ball = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (guess[i] == answer[j]) {
                    if (i == j) {
                        strike++;
                    }
                    else {
                        ball++;
                    }
                }
            }
        }

        // 스트라이크와 볼 수 출력
        if (strike == 0 && ball == 0) {
            cout << "3 아웃!" << endl;
        }
        else {
            cout << strike << " 스트라이크, " << ball << " 볼" << endl;
        }

        tries++;

    } while (strike < 3);

    cout << "축하합니다! 정답을 " << tries << "번만에 맞추셨습니다!" << endl;

    return 0;
}
