// Lucas Pereira Pacheco - 12543930

#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>
#include<climits>

int findMinimal(std::vector<int> loots, int targetValue)
{
  const int max = targetValue + 1;
  std::vector<int> dp(targetValue + 1, max);
  dp[0] = 0;

  for(int i =1;  i <= targetValue; i++)
  {
    for(auto loot: loots)
    {
      if(i >= loot)
        dp[i] = std::min(dp[i], dp[i-loot] + 1);
    }
  }

  return dp[targetValue] == max ? -1 : dp[targetValue];
}

int main()
{
  int targetValue, nLoots;
  for(;;)
  {
    std::cin >> targetValue >> nLoots;
    if(!targetValue && !nLoots)
      break;
    
    std::vector<int> lootsList;

    for(int i =0 ; i < nLoots; i++)
    {
      int lootValue;
      std::cin >> lootValue;
      lootsList.push_back(lootValue);
    }
    std::cout << findMinimal(lootsList, targetValue) << std::endl;

  }


  return 0;
}
