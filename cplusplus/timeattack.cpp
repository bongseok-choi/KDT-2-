#include <ctime>
#include <iostream>

using namespace std;

int main() {
    string first = "Bongseok";
    int count = 0;

    cout << "끝말잇기 시작: " << first << "\n";

    while (true) {

        clock_t start_time = clock();
        cout << "단어를 입력하세요: ";
        string new_word;
        cin >> new_word;

        if (new_word.length() <= 1) {
            cout << "두 글자 이상의 단어를 입력하세요.\n";
            continue;
        }

        for (int i = 0; i < new_word.length(); i++) {
            new_word[i] = tolower(new_word[i]);
        }

        if (new_word.front() != first.back()) {
            cout << "틀린 입력입니다.\n";
            continue;
        }


        clock_t end_time = clock();
        if ((end_time - start_time) / CLOCKS_PER_SEC >= 30) {
            cout << "시간 초과!! 게임 종료." << endl;
            cout << "입력한 단어 개수 : " << count<< endl;
            break;
        }


        first += (" --> " + new_word);
        count++;
        cout << first << endl;
    }

    return 0;
}