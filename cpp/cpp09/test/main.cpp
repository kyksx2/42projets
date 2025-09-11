#include <iostream>
#include <vector>

std::vector<int> jacobsthalSuite(int size) {
    std::vector<int> j;
    long j0 = 0;
    long j1 = 1;
    long j2 = 0;

    while (1) {
        j2 = j1 + (2 * j0);
        if (j2 > size)
            break;
        j.push_back(j2);
        j0 = j1;
        j1 = j2;
    }
    for (size_t i = size; i >= 1; i--) {
        bool find = false;
        for (size_t k = 0; k < j.size(); k++) {
            if (j[k] == i) {
                find = true;
                break;
            }
        }
        if (!find)
            j.push_back(i);
    }
    return j;
}

int main() {
    std::vector<int> j;
    j.push_back(1);
    j.push_back(3);
    j.push_back(5);
    j.push_back(2);
    j.push_back(4);
    std::vector<int> jacob = jacobsthalSuite(j.size());
    for(size_t i = 0; i < jacob.size(); i++)
        std::cout << jacob[i] << " ";
    return (0);
}