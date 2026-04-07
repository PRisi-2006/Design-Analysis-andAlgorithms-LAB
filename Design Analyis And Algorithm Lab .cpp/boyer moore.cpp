#include <iostream>
#include <cstring>
using namespace std;

#define SIZE 256

// Function to generate bad character heuristic table
void badCharHeuristic(string pat, int bad[]) {
    for (int i = 0; i < SIZE; i++)
        bad[i] = -1;

    for (int i = 0; i < pat.length(); i++)
        bad[(int)pat[i]] = i;
}

// Boyer-Moore search function
void boyerMooreSearch(string txt, string pat) {
    int m = pat.length();
    int n = txt.length();

    int bad[SIZE];
    badCharHeuristic(pat, bad);

    int s = 0; // shift of pattern

    while (s <= (n - m)) {
        int j = m - 1;

        // Compare from right to left
        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        // If pattern is found
        if (j < 0) {
            cout << "Found at index " << s << endl;

            // Shift pattern
            if (s + m < n)
                s += m - bad[(int)txt[s + m]];
            else
                s += 1;
        }
        else {
            s += max(1, j - bad[(int)txt[s + j]]);
        }
    }
}

// Main function
int main() {
    string txt = "ABAAABCD";
    string pat = "ABC";

    boyerMooreSearch(txt, pat);

    return 0;
}