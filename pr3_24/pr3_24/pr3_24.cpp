#include <iostream>
#include <vector>

using namespace std;

vector<int> computeLPS(string pattern) {
    int n = pattern.length();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

int findMinLength(string str) {
    int n = str.length();
    vector<int> lps = computeLPS(str);

    int longestSuffixLength = lps[n - 1];
    int minLength = n - longestSuffixLength;

    if (n % minLength == 0) {
        return minLength;
    }
    else {
        return n;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    string input;
    cout << "Введите подстроку: ";
    cin >> input;

    int minLength = findMinLength(input);
    cout << "Минимально возможная длина исходной строки S: " << minLength << endl;

    return 0;
}