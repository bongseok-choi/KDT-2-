#include <ctime>
#include <iostream>

using namespace std;

int main() {
    string first = "Bongseok";
    int count = 0;

    cout << "�����ձ� ����: " << first << "\n";

    while (true) {

        clock_t start_time = clock();
        cout << "�ܾ �Է��ϼ���: ";
        string new_word;
        cin >> new_word;

        if (new_word.length() <= 1) {
            cout << "�� ���� �̻��� �ܾ �Է��ϼ���.\n";
            continue;
        }

        for (int i = 0; i < new_word.length(); i++) {
            new_word[i] = tolower(new_word[i]);
        }

        if (new_word.front() != first.back()) {
            cout << "Ʋ�� �Է��Դϴ�.\n";
            continue;
        }


        clock_t end_time = clock();
        if ((end_time - start_time) / CLOCKS_PER_SEC >= 30) {
            cout << "�ð� �ʰ�!! ���� ����." << endl;
            cout << "�Է��� �ܾ� ���� : " << count<< endl;
            break;
        }


        first += (" --> " + new_word);
        count++;
        cout << first << endl;
    }

    return 0;
}