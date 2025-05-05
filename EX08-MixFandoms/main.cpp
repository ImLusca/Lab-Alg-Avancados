// Lucas Pereira Pacheco 12543930
#include <iostream>
#include <tuple>
#include <vector>
#include <unordered_map>

struct dados {
    char nFans;
    char nRules;
    std::vector<std::tuple<char, char, char>> rules; // A, B, Dist
};

bool isValidDist(int peopleDist, int dist) {
    return (dist < 0 && peopleDist >= -dist) || (dist > 0 && peopleDist <= dist);
}

bool validateRules(const std::unordered_map<char, char>& pos, const dados& d) {
    for (const auto& rule : d.rules) {
        char a = std::get<0>(rule);
        char b = std::get<1>(rule);
        char rDist = std::get<2>(rule);

        if (!pos.count(a) || !pos.count(b)) continue;

        int actualDist = abs(pos.at(a) - pos.at(b));

        if (!isValidDist(actualDist, rDist)) return false;        
    }
    return true;
}

int backtrack(std::unordered_map<char, char>& pos, std::vector<char> available, int posIndex, const dados& d) {
    if (!validateRules(pos, d)) return 0;
    if (available.empty()) return 1;

    int total = 0;
    for (size_t i = 0; i < available.size(); ++i) {
        char person = available[i];
        pos[person] = posIndex;

        std::vector<char> newAvailable = available;
        newAvailable.erase(newAvailable.begin() + i);

        total += backtrack(pos, newAvailable, posIndex + 1, d);
        pos.erase(person);
    }
    return total;
}

dados leDados() {
    dados d;
    int nFans, nRules;
    std::cin >> nFans >> nRules;
    d.nFans = static_cast<char>(nFans);
    d.nRules = static_cast<char>(nRules);

    for (int i = 0; i < nRules; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c;
        d.rules.push_back({a, b, c});
    }
    return d;
}

int main() {
    while (true) {
        dados input = leDados();
        if (input.nFans == 0 && input.nRules == 0) break;

        std::vector<char> fans(input.nFans);

        for (char i = 0; i < input.nFans; ++i) fans[i] = i;
        
        std::unordered_map<char, char> pos;
        int total = backtrack(pos, fans, 1, input);
        std::cout << total << std::endl;
    }
    return 0;
}
