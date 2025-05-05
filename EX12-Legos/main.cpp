// Lucas Pereira Pacheco - 12543930

#include <cstring>
#include <vector>
#include <iostream>
#include <climits>

int minimoCortes(int tamanho, std::vector<int> pontosCortes)
{
  int nCortes = pontosCortes.size();
  int dp[nCortes][nCortes];
  memset(dp, 0, sizeof(dp));
  
  for(int i = 2; i< nCortes; i++)
  {
    for(int j = 0; j + i < nCortes; j++)
    {
      int k = i + j;
      dp[j][k] = INT_MAX;

      for(int l = j+1; l < k; l++)
      { 
        int custo = dp[j][l] + dp[l][k] + (pontosCortes[k] - pontosCortes[j]);
        dp[j][k] = std::min(dp[j][k], custo);
      }
    }
  }

  return dp[0][nCortes - 1];
}

int main()
{
  int l, npecas;

  for(;;)
  {
    std::cin >> l;

    if(l == 0) break;
    
    std::cin >> npecas;
    std::vector<int> pontosCorte;
    

    pontosCorte.push_back(0);
    for(int i =0; i < npecas; i++)
    {
      int pontoCorte;
      std::cin >> pontoCorte;
      pontosCorte.push_back(pontoCorte);
    }
    pontosCorte.push_back(l);
    
    std::cout << "O custo mínimo de separação é " << minimoCortes(l, pontosCorte) << "." << std::endl;
  }


  return 0;
}
