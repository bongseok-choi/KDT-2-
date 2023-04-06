#include <iostream>
#include <cstdlib>  
#include <ctime>   

using std::cin;
using std::cout;
using std::endl;

const int MAX_NUMBER = 3;       
const int WINNING_NUMBER = 31; 

int main() {
    int currentCount = 0;
    bool win = true;         
    bool isUserTurn = true;  

    srand(time(NULL));  

    while (currentCount < WINNING_NUMBER) {
        int num = 0;

        if (isUserTurn) {
            cout << "1에서 " << MAX_NUMBER << "까지의 숫자를 입력하세요: ";
            cin >> num;
            while (num < 1 ||
                num > MAX_NUMBER) { 
                cout << "잘못된 입력입니다!!\n1에서 " << MAX_NUMBER
                    << "까지의 숫자를 입력하세요: ";
                cin >> num;
            }
            isUserTurn = false;
        }
        else {
            num = rand() % MAX_NUMBER + 1;
            cout << "컴퓨터 입력: ";
            cout << num << endl;
            isUserTurn = true;
        }

        currentCount += num;
        cout << currentCount << endl;
    }
    cout << endl;
    isUserTurn ? cout << "사용자의 승리!"
        : cout << "컴퓨터의 승리!";

    return 0;
}