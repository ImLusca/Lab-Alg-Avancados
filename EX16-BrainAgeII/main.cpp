// Lucas Pereira Pacheco - 12543930
#include <iostream>
#include <unordered_map>
#include <cmath>

std::unordered_map<int, int> fatorar(int m) {
    std::unordered_map<int, int> fatores;
    for (int i = 2; i * i <= m; ++i) {
        while (m % i == 0) {
            fatores[i]++;
            m /= i;
        }
    }
    if (m > 1) {
        fatores[m] = 1;
    }
    return fatores;
}

int contaExpEmFatorial(int n, int p) {
    int exp = 0;
    while (n) {
        n /= p;
        exp += n;
    }
    return exp;
}

bool mDivideFatorialDeN(int m, int n) {
    auto fatoresN = fatorar(n);
    for (const auto& [primo, expN] : fatoresN) {
        int expM = contaExpEmFatorial(m, primo);
        if (expM < expN) return false;
    }
    return true;
}

int main() {
    int m, n;
    while (std::cin >> m >> n) {
        bool divide = mDivideFatorialDeN(m, n); 
        std::cout << n << (!divide ? " does not divide " : " divides ") << m << "!" << std::endl;
    }
    return 0;
}
