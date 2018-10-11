/*
fond the longest common substring between to string,
i.e. LCS problem
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string longestCommonSubstring(const string& s1, const string& s2) {
    string common;
    if (s1.empty() || s2.empty()) return common;
    int m = s1.size(), n = s2.size();
    // calculate length of longest common substring
    vector<vector<int> > count(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i < m + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            if (s1[i-1] == s2[j-1]) count[i][j] = count[i-1][j-1] + 1;
            else count[i][j] = max(count[i-1][j], count[i][j-1]);
        }
    }
    for (int i = 0; i < count.size(); ++i) {
        for (int j = 0; j < count[i].size(); ++j)
            cout << count[i][j] << "\t";
        cout << endl;
    }
    // construct longest common substring
    int i = m, j = n;
    while (i >= 1 && j >= 1) {
        if (count[i-1][j] == count[i][j]) i--;
        else if (count[i][j-1] == count[i][j]) j--;
        else {
            // cout << s1[i-1] << "\t" << s2[j-1] << endl;
            common.push_back(s1[i-1]);
            i--, j--;
        }    
    }
    reverse(common.begin(), common.end());
    return common;
}


int main() {
    string s1 = "ABCBAD", s2 = "BDCABA";
    cout << longestCommonSubstring(s1, s2) << endl;
    system("pause");
    return 0;
}