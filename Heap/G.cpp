#include <iostream>
#include <queue>

int main() {
    int n;
    std::cin >> n;

    std::priority_queue<std::pair<int, int>> fishs;

    std::vector<int> population;

    int a, f;
    for (int i = 0; i < n; i ++) {
        std::cin >> a;
        population.push_back(a);
        f = std::max(1000-a, 1);
        fishs.push({-f, -i});
    }

    int position = 0;
    int time = 0;

    std::pair<int, int> current = fishs.top();
    int t = -current.first;
    int aq = -current.second;

    while (abs(position-aq) <= abs(t - time)) {
        population[aq] +=1;
        fishs.pop();
        f = std::max(1000-population[aq], 1);
        fishs.push({-(f+t), -aq});
        position = aq;
        time = t;
        current = fishs.top();
        t = -current.first;
        aq = -current.second;
    }
    std::cout << t << std::endl;
}