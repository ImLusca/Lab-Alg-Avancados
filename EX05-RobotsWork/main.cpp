//Lucas Pereira Pacheco 12543930

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

// 5
// 7
// 2 3 1 4 2 3 5
// 1 2 2 3 3 4 5


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
  
  int nBots = 0,count = 1, lastOccurrence = prazosOrdenados[0].first;
  
  for(int i = 1; i < nTasks; i++){
    if(lastOccurrence != prazosOrdenados[i].first)
    {
      if(nBots < count) nBots = count;
      count = 1;
      lastOccurrence = prazosOrdenados[i].first;
      continue;
    }
    count++;
  }
  
  std::cout << nBots << std::endl;

  // index, bot, dia 
  std::vector<std::tuple<int, int, int>> resultado;
 
  int botNumber = 1, dia = 1;
  for(int i=0; i < nTasks; i++){
    if(prazosOrdenados[i].first != dia)
    {
      botNumber = 1;
      dia++;
      continue;
    }
    
    resultado.push_back({prazosOrdenados[i].second,botNumber,dia});
    botNumber++;

    if(botNumber > nBots)
    {
      std::cout << "Deu ruim na contagem" << std::endl;
      return 1;
    }
  }
  std::sort(resultado.begin(),resultado.end());
  for(auto resultados : resultado){
      std::cout << std::get<1>(resultados) << " " << std::get<2>(resultados) << std::endl;
  }

  return 0;
}
