//Lucas Pereira Pacheco 12543930

#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
  int nDays, cash, countStocks = 0;
  std::vector<std::pair<int,int>> valoresPdia;
  
  std::cin >> nDays;

  for(int i = 0; i < nDays ; i++)
  {
    int valorDia;
    std::cin >> valorDia;
    
    valoresPdia.push_back({valorDia, i+1});
  }

  std::cin >> cash;
  std::sort(valoresPdia.begin(),valoresPdia.end());

  for(auto value:valoresPdia)
  {
    if(value.first * value.second <= cash)
    {
      cash -= value.first * value.second;
      countStocks += value.second;
      continue;
    }
    
    int numStocks = cash / value.first;
    countStocks += numStocks;
    break;      
  }

  std::cout << countStocks;

  return 0;
}
