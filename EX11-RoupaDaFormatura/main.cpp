// Nome: Lucas Pereira Pacheco - 12345678

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int M, C;
int prices[25][25];
int dp[210][25];

int shop(int moneyLeft, int g) {
    if (moneyLeft < 0) return -1000000; // valor impossível
    if (g == C) return M - moneyLeft; // comprou de todas as categorias

    if (dp[moneyLeft][g] != -1) return dp[moneyLeft][g];

    int ans = -1000000;
    for (int i = 1; i <= prices[g][0]; i++) {
        ans = max(ans, shop(moneyLeft - prices[g][i], g + 1));
    }

    return dp[moneyLeft][g] = ans;
}

int main() {
    int N;
    cin >> N;

    while (N--) {
        cin >> M >> C;
        for (int i = 0; i < C; i++) {
            cin >> prices[i][0];
            for (int j = 1; j <= prices[i][0]; j++) {
                cin >> prices[i][j];
            }
        }

        memset(dp, -1, sizeof(dp));
        int result = shop(M, 0);
        if (result < 0)
            cout << "no solution" << endl;
        else
            cout << result << endl;
    }

    return 0;
}
