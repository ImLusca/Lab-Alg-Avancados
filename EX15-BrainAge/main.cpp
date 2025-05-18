// Lucas Pereira Pacheco - 12543930
#include<iostream>
#include<vector>
#include<unordered_set>

std::unordered_set<int> numerosPrimos = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
    31, 37, 41, 43, 47, 53, 59, 61, 67,
    71, 73, 79, 83, 89, 97
};

std::vector<int> primos_vec = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
    31, 37, 41, 43, 47, 53, 59, 61, 67,
    71, 73, 79, 83, 89, 97
};

std::vector<int> processaFatorial(int fatorial)
{
    std::vector<int> resultado(primos_vec.size(), 0);
    for (int i = 2; i <= fatorial; ++i)
    {
        int num = i;
        for (size_t j = 0; j < primos_vec.size(); ++j)
        {
            int primo = primos_vec[j];
            while (num % primo == 0)
            {
                resultado[j]++;
                num /= primo;
            }
            if (num == 1) break;
        }
    }
    return resultado;
}

int main()
{
    int userInput;

    while (std::cin >> userInput && userInput != 0)
    {
        auto result = processaFatorial(userInput);
        std::cout << userInput << "! = ";
        
        if(userInput == 1){
          std::cout << 0 << std::endl;
          continue;
        } 

        bool first = true;
        for (size_t i = 0; i < result.size(); ++i)
        {
            if (result[i] > 0)
            {
                if (!first) std::cout << " ";
                std::cout << result[i];
                first = false;
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
