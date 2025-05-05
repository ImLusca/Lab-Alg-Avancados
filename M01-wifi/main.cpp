// Lucas Pereira Pacheco - 12543930

#include <cstring>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>


float calcCoverage(int r, int w)
{
  return std::sqrt(4*r*r - w*w ) / 2.0;
}

int findMinimal(std::vector<std::pair<float,float>> routersPos, int streetLen)
{
  std::sort(routersPos.begin(), routersPos.end());

  float position = 0;
  int lastIndex = 0;
  int routersCounter = 0;
  while(position < streetLen)
  {
    float mostDistant = -1;
    for(; routersPos[lastIndex].first <= position && lastIndex < routersPos.size(); lastIndex++)
      if(routersPos[lastIndex].second > mostDistant) mostDistant = routersPos[lastIndex].second;
    
    if(mostDistant == -1) return -1;
    position = mostDistant;
    routersCounter++;
  }

  return routersCounter;
}

int main()
{
 int nRouters, streetLength, streetWidth;
  for(;;)
  {

    std::cin >> nRouters >> streetLength >> streetWidth;
    if(!nRouters && !streetLength && !streetWidth)
      break;
    
    std::vector<std::pair<float,float>> routersPositions;

    for(int i =0 ; i < nRouters; i++)
    {
      int routerPos, radius;
      std::cin >> routerPos >> radius;
      float coverage = calcCoverage(radius, streetWidth);
      routersPositions.push_back({routerPos - coverage, routerPos + coverage});
    }
    std::cout << findMinimal(routersPositions, streetLength) << std::endl;

  }


  return 0;
}
