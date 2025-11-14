#include <iostream>
#include <string>
#include <vector>

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

int main() {

    std::string str;
    std::cin >> str;

    std::vector<int> func = pref_func(str);
    for (int i = 0; i < func.size(); i++) {
        std::cout << func[i] << " ";
    }
}