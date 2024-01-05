#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void badCharHeuristic(const string& pattern, vector<int>& badChar) {
    int m = pattern.length();
    for (int i = 0; i < m - 1; i++) {
        badChar[pattern[i]] = max(1, m - i - 1);
    }
}

// Boyer-Moore search function
int boyerMooreSearch(const string& text, const string& pattern) {
    int m = pattern.length();
    int n = text.length();

    vector<int> badChar(256, m); 

    badCharHeuristic(pattern, badChar);

    int i = 0;
    while (i <= n - m) {
        int j = m - 1;

        // Check for a match
        while (j >= 0 && pattern[j] == text[i + j]) {
            j--;
        }

        // If the pattern is found
        if (j < 0) {
            return i;
        }

        i += max(1, j - badChar[text[i + j]]);
    }

    return -1; // Pattern not found
}

int main() {
    string text = "This is a sample text for searching.";
    string pattern;

    cout << "Enter the pattern to search: ";
    cin >> pattern;

    int result = boyerMooreSearch(text, pattern);

    if (result != -1) {
        cout << "Pattern found at index " << result << " in the text." << endl;
    } else {
        cout << "Pattern not found in the text." << endl;
    }

    return 0;
}
