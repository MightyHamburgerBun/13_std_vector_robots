#include <iostream>
#include <vector>

int main() {
    int n;
    std::cout << "Number of robots: ";
    std::cin >> n;
    std::vector<int> robots(n);

    for (int i = 0; i < n; ++i) {
        std::cout << "ID: ";
        std::cin >> robots[i];
    }
    std::cout << "Showcase: { ";
    for (int i = 0; i < robots.size(); ++i) {
        std::cout << robots[i];
        std::cout << " ";
    }
    std::cout << "}\n";
    int m;
    std::cout << "Number of operations: ";
    std::cin >> m;
    std::cout << "For placement, use a query like '1 ID'.\n To buy, use a query like '2 index'\n";
    std::string query;
    std::cin.ignore();
    for (int i = 0; i < m; i++) {
        std::getline(std::cin, query);
        //std::cout << "query = " << query << std::endl;
        if (query.length() < 3) {
            std::cout << "Error\n";
            i--;
        } else if (query[1] != ' ') {
            std::cout << "Error\n";
            i--;
        } else {
            char y = query[0];
            int x = 0;
            int q = 1;
            for (int i = query.length()-1; i > 1; --i) {
                x += (int)(query[i] - '0') * q;
                q *= 10;
            }
            //std::cout << "x = " << x << std::endl;
            //std::cout << "y = " << y << std::endl;
            if (y == '1') {
                robots.resize(robots.size() + 1);
                robots[robots.size() - 1] = x;
            } else if (y == '2') {
                for (int i = x; i < robots.size() - 1; ++i) {
                    robots[i] = robots[i + 1];
                }
                robots.resize(robots.size() - 1);
            } else {
                std::cout << "Error\n";
                i--;
            }
        }
        std::cout << "Showcase: { ";
        for (int j = 0; j < robots.size(); ++j) {
            std::cout << robots[j];
            std::cout << " ";
        }
        std::cout << "}\n";
    }
}