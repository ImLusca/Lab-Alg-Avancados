//Lucas Pereira Pacheco 12543930

#include <iostream>
#include <vector>
#include <algorithm>

std::pair<int,int> loop()
{
  int productsCount, money;
  std::vector<int> products;

  std::cin >> productsCount;

  for(int i = 0 ; i < productsCount; i++)
  {
    int productPrice;
    std::cin >> productPrice;
    products.push_back(productPrice);
  }

  std::cin >> money;

  std::sort(products.begin(), products.end());
  
  int pointerLeft = 0, pointerRight = productsCount - 1;
  int productsCost;
 
  std::pair<int,int> solution;

  while(pointerLeft < pointerRight)
  {
    productsCost = products[pointerLeft] + products[pointerRight]; 
    
    if(productsCost < money) pointerLeft++;
    if(productsCost > money) pointerRight--;

    if(productsCost == money)
    {
      solution = {products[pointerLeft], products[pointerRight]};
      pointerRight--;
    }
  }

  return solution;
}

int main()
{
  while(std::cin.peek() != EOF)
  {
    auto products = loop();

    std::cout << "Joaquina deve comprar os jogos de preços " << products.first;
    std::cout << " e " << products.second << "." << std::endl << std::endl;

    std::cin >> std::ws;  // Esse \n antes do EOF me quebrou demais kkkk
  }

  return 0;
}
