#include <iostream>
#include <queue>


struct freePart {
    int begin, end, request;

    freePart(int c_begin, int c_end, int c_request) {
        begin = c_begin;
        end = c_end;
        request = c_request;
    }

    bool operator<(const freePart &curr_m) const {
        return begin > curr_m.begin;
    }
};

int main() {
    int N, M;
    std::cin >> N >> M;

    std::priority_queue<freePart> memory;
    int num;

    int begin = 0;
    int end = N;
    int request = 1;

    int free = end - begin;
    freePart temp(begin, end, request);
    freePart curr_m(begin, end, request);
    memory.push(curr_m);
    for (int i =2 ; i < M+1;i++) {
        std::cin >> num;
        if (num > 0)
        {
            if (!memory.empty())
            {
                while (num > free) {
                    temp = memory.top();
                    memory.pop();
                    curr_m = memory.top();
                    begin = curr_m.begin;
                    end = curr_m.end;
                    request = curr_m.request;
                    free = end - begin;
                }

        }

    }
}