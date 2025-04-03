//Lucas Pereira Pacheco 12543930

#include <iostream>
#include <tuple>
#include <vector>

typedef struct {
  bool isValidInput = true;
  int nFans;
  int nRules;
  std::vector<std::tuple<int,int,int>> rules;
} dados;


bool validateRules(std::vector<int>& spaces, dados& data)
{
  
}

dados leDados()
{
  dados result;

  std::cin >> result.nFans >> result.nRules;

  if(result.nFans == 0 && result.nRules == 0)
  {
    result.isValidInput = false;
    return result;
  }

  for(int i = 0; i < result.nRules; i++)
  {
    int a,b,c;
    std::cin >> a >> b >> c;
    result.rules.push_back({a,b,c});
  }
  
  return result;
}

int main()
{
  for(;;)
  {
    auto input = leDados();
    if(!input.isValidInput)
      break;


  }
  
  return 0;
}
