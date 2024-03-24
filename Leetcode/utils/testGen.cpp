#include <random>
#include <string>
#include <iostream>

using namespace std;

random_device rd;
mt19937 gen(rd());

string generateRandomIntArrayString(int minElement, int maxElement, size_t len) {
    string res = "[";
    uniform_int_distribution<> dist(minElement, maxElement);
    for (int i = 0; i < len; ++i) {
        res += to_string(dist(gen));
        res += (i == len - 1 ? "]" : ", ");
    }
    return res;
}

int main() {
    for (int i = 0; i < 10; ++i) {
        uniform_int_distribution<> len(1, 20);
        cout << generateRandomIntArrayString(0, 20, len(gen)) << "\n";
    }

}