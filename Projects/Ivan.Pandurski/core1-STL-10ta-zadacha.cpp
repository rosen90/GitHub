#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n = 3;
	int m = 19;
	stack<int> s;
	s.push(m);
	while (m != n) {
		while (s.top() % 2 == 0 && s.top() / 2 >= n) {
			m = s.top() / 2;
			s.push(m);

		}
		while (s.top() - 1 >= n) {
			m = s.top() - 1;
			s.push(m);
			while (s.top() % 2 == 0 && s.top() / 2 >= n) {
				m = s.top() / 2;
				s.push(m);

			}

		}

		while (s.top() - 2 >= n) {
			m = s.top() - 2;
			s.push(m);
			while (s.top() % 2 == 0 && s.top() / 2 >= n) {
				m = s.top() / 2;
				s.push(m);

			}

		}

	}

	while (!s.empty()) {
		cout << s.top() << "\t";
		s.pop();
	}
	return 0;
}
