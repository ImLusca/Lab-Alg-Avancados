//Lucas Pereira Pacheco 12543930

#include <iostream>
#include <vector>
#include <algorithm>


int getHigherPrice(std::vector<int> prices, int nBrindes)
{
  int p1 = 0, p2 = prices.size(); 
  int spentMoney = 0;

  while(p1 <= p2)
  {
    spentMoney += prices[--p2];
    p1 += nBrindes;
  }

  return spentMoney;
}

int getLowerPrice(std::vector<int> prices, int nBrindes)
{
  int p1 = 0, p2 = prices.size(); 
  int spentMoney = 0;

  while(p1 <= p2)
  {
    spentMoney += prices[p1++];
    p2 -= nBrindes;
  }

  return spentMoney;
}

int main()
{
  int nDoces, nBrindes;
  std::vector<int> precosDoces;

  std::cin >> nDoces >> nBrindes;

  for(int i = 0; i < nDoces; i++)
  {
     int precoDoce;
     std::cin >> precoDoce;

     precosDoces.push_back(precoDoce);
  }
  
  std::sort(precosDoces.begin(), precosDoces.end());

  std::cout << getLowerPrice(precosDoces, nBrindes) << " ";
  std::cout << getHigherPrice(precosDoces, nBrindes);

  return 0;
}
