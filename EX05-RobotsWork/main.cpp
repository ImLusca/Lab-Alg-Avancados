//Lucas Pereira Pacheco 12543930

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>

int botsCounter(std::vector<std::pair<int,int>> prazos)
{
  int nBots = 0, taskCounter = 0, task = 0;
  
  while(task < prazos.size())
  {
    int dia = prazos[task].first;

    while(task < prazos.size() && prazos[task].first == dia){
      taskCounter++;
      task++;
    }

    nBots = std::max(nBots, (int)std::ceil((float)taskCounter / dia));
  }

  return nBots;
}


int main()
{
  int nDias, nTasks;
  std::vector<int> prazos;
  std::vector<std::pair<int, int>> prazosOrdenados;

  std::cin >> nDias >> nTasks;

  for(int i =0 ; i< nTasks; i++)
  {
    int prazo;
    std::cin >> prazo;
    prazos.push_back(prazo);
  }
 
  for(int i = 0; i < nTasks; i++)
    prazosOrdenados.push_back({prazos[i],i});
  
  std::sort(prazosOrdenados.begin(), prazosOrdenados.end());

  int nBots = botsCounter(prazosOrdenados);
  std::cout << nBots << std::endl;

  // index, bot, dia 
  std::vector<std::tuple<int, int, int>> resultado;
  
  int dia =1;
  for(int i =0; i < nTasks; i+=nBots)
  {
    for(int j=0;j < nBots; j++)
      if(i+j < nTasks) resultado.push_back({prazosOrdenados[i+j].second,j+1, dia});

    dia++;
  }

  std::sort(resultado.begin(),resultado.end());
  for(auto resultados : resultado)
      std::cout << std::get<2>(resultados) << " " << std::get<1>(resultados) << std::endl;
  

  return 0;
}
