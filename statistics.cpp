#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
char letter = 'a';

struct Word {
    string str;
    int freqs[26] = {0};
};

bool compare(Word word1, Word word2) {
    int length1 = word1.str.length();
    int length2 = word2.str.length();
    int letter_idx = static_cast<int>(letter) - 97;
    if (2 * word1.freqs[letter_idx] - length1 >
    2 * word2.freqs[letter_idx] - length2) {
        return true;
    }
    return false;
}

int main() {
    int n, i, j;
    ifstream fin("statistics.in");
    ofstream fout("statistics.out");
    fin >> n;
    vector< Word > words;
    vector<int> freqs;
    int maxim = 0;
    for (i = 0; i < n; i++) {
        Word word;
        fin >> word.str;
        for (j = 0; j < word.str.length(); j++) {
            int index = static_cast<int>(word.str[j]) - 97;
            word.freqs[index]++;
        }
        words.push_back(word);
    }
    int nr_max = 0;
    for (i = 0; i < 26; i++) {
        sort(words.begin(), words.end(), compare);
        int nr_words = 0, freq_letter = 0, total_length = 0;
        for (j = 0; j < words.size(); j++) {
            int letter_idx = static_cast<int>(letter) - 97;
            if (freq_letter + words[j].freqs[letter_idx] >
            (total_length + words[j].str.length()) / 2) {
                nr_words++;
                freq_letter += words[j].freqs[letter_idx];
                total_length += words[j].str.length();
            } else {
                break;
            }
        }
        if (nr_words > nr_max) {
            nr_max = nr_words;
        }
        letter = static_cast<char>(letter + 1);
    }
    if (nr_max == 0) {
        fout << -1 << endl;
    } else {
        fout << nr_max << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
