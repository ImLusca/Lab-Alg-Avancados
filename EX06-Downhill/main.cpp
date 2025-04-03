// Lucas Pereira Pacheco - 12543930

#include <iostream>
#include <vector>

typedef struct{
  char acao;
  int quantidade;
  int posicao;
} evento;

int tryScript(std::vector<evento> eventos, float combustivel)
{
  return 0;
}

char leAcao()
{
  std::string acao;
  std::cin >> acao;

  char resultado;
  char ignorar = 0;
  
  if(acao == "Consumo")
  {
    resultado = 0;
    ignorar = 2;
  }

  if (acao == "Vazamento")
    resultado = 1;

  if(acao == "Posto")
  {
    resultado = 2;
    ignorar = 2;
  }

  if(acao == "Mecânico")
    resultado = 3;
  
  if(acao == "Destino")
    resultado = 4;

  for(int i =0 ; i< ignorar; i++)
    std::cin.ignore(1000, ' ');

  std::cin >> std::ws;
  return resultado;
}

std::vector<evento> leEventos()
{
  std::vector<evento> resultado;

  for(;;)
  {
    evento evt;
    std::cin >> evt.posicao;
    evt.acao = leAcao();  
    if(evt.acao == 0)
      std::cin >> evt.quantidade;
    
    if(!evt.posicao && !evt.quantidade)
      return resultado;

    resultado.push_back(evt);

    if(evt.acao == 4) break;
  }

  return resultado;
}

int main()
{

  for(;;)
  {
    auto eventos = leEventos();
    if(eventos.size() == 0) break;
    for(auto evt : eventos)
      std::cout << evt.acao << " | ";
  }

  return 0;
}
