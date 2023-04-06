
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
	int input;
	std::vector <int> v(6);

	while (1) {
		cout << "숫자는 1~25까지의 숫자만 입력해주세요:";
		for (int i = 0; i < 6; i++) {
			int k = 1;
			int input;
			cout << i << "번째 번호를 입력해주세요:";
			cin >> input;
			int tmp;
			if (v[i] = v[i + k]) {
				cout << "이미 입력된 숫자입니다." << endl;
			}

		}
		
	}

}