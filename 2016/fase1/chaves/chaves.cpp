#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool areBracketsBalanced(const string& code) {
    stack<char> brackets;
    for (char c : code) {
        if (c == '{') {
            brackets.push(c);
        } else if (c == '}') {
            if (brackets.empty() || brackets.top() != '{') {
                return false;
            }
            brackets.pop();
        }
    }
    return brackets.empty();
}

int main() {
    int N;
    cin >> N;
    cin.ignore(); // Clear newline character

    bool balanced = true;
    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);

        // Remove consecutive spaces
        string cleanLine;
        for (char c : line) {
            if (c != ' ') {
                cleanLine += c;
            }
        }

        if (!cleanLine.empty() && !areBracketsBalanced(cleanLine)) {
            balanced = false;
            break;
        }
    }

    cout << (balanced ? "S" : "N") << endl;

    return 0;
}