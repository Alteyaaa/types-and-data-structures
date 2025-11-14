#include <iostream>
#include <vector>
#include <string>

std::vector<int> pref_func(std::string s) {
    int n = s.size();
    std::vector<int> pref(n, 0);
    for (int i = 1; i < n; i++) {
        int curr = pref[i-1];
        while (curr > 0 && s[i] != s[curr]) {
            curr = pref[curr-1];
        }
        if (s[i] == s[curr]) {
            pref[i] = curr + 1;
        }
    }
    return pref;
}

std::vector<int> kmp(std::string text, std::string pattern) {
    int n = text.size();
    int m = pattern.size();
    std::vector<int> pref = pref_func(pattern.append("#").append(text));
    std::vector<int> ans;
    for (int i = m; i < m+n+1; i++) {
        if (pref[i] == m) {
            ans.push_back(i-m*2);
        }
    }
    return ans;
}

int main() {
    std::string text, pattern;
    std::cin >> text >> pattern;
    std::vector<int> answer = kmp(text, pattern);
    for (int i = 0; i < answer.size(); i++) {
        std::cout << answer[i] << " ";
    }
}