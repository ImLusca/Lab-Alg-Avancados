//Lucas Pereira Pacheco | 12543930

#include <iostream>
#include <map>
#include <string>

using server2Ip = std::map<std::string, std::string>;

std::pair<std::string, std::string> readLine(){
  std::string tempServer, tempIp;
  std::cin >> tempServer >> tempIp;
  return std::make_pair(tempServer, tempIp);
}


int main() {
  int n,m;
  std::cin >> n >> m;

  server2Ip servidores;

  for(int i = 0 ; i < n; i++)
  {
    auto lineRead = readLine();
    servidores[lineRead.second] = lineRead.first;
  }

  for(int i =0; i < m; i++)
  {
    auto lineRead = readLine();
    lineRead.second.pop_back();
    std::cout << lineRead.first << " " << lineRead.second << "; #" << servidores[lineRead.second] << std::endl;
  }

  return 0;
}
