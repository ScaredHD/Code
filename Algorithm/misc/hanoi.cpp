#include <iostream>

int hanoi(int idx, int from, int to, int through) {
	if (idx == 0) {
		return 0;
	}
	return hanoi(idx - 1, 1, 2, 3)     // Disks [1..n-1] from peg 1 to peg 2 through peg 3
		   + 1                         // Biggest disk (idx = n) from peg 1 to peg 3
		   + hanoi(idx - 1, 2, 3, 1);  // Disks [1..n-1] from peg 2 to peg 3 through peg 1
}

int main() {
	std::cout << hanoi(8, 1, 3, 2);
}