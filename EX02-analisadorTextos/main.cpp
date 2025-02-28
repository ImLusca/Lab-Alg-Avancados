// Lucas Pereira Pacheco | 12543930

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
#include <algorithm>

using uShort = unsigned short;

std::string preprocessString(std::string bruteText){
  std::string result;
  
  for(char c : bruteText)
    if(std::isalpha(c))
      result += std::islower(c) ? c : tolower(c);
    else
      result += ' ';
  
  return result;
}

void printTextAndCount(std::vector<std::string> text)
{
  int occurrencesCount = 0;
  std::string lastWord = "";


  auto iterator = text.begin();
  
  std::cout << *iterator;
  
  for(iterator++; iterator != text.end(); ++iterator){
    if(*iterator == lastWord) continue;
    std::cout << ", " << *iterator;
    lastWord = *iterator;
  }
  
  std::cout << std::endl;
  lastWord = text[0];

  for(std::string str: text)
  {
    if(!str.compare(lastWord))
    {
      occurrencesCount++;
      continue;
    }
    
    std::cout << lastWord << " " << occurrencesCount << std::endl;

    lastWord = str;
    occurrencesCount = 1;
  }
  
  std::cout << lastWord << " " << occurrencesCount << std::endl;

}

int main()
{
  std::string input;
  std::getline (std::cin, input);
  std::vector<std::string> palavras;

  std::istringstream ss(preprocessString(input));
  std::string tmp; 

  while(ss >> tmp)
    palavras.push_back(tmp);

  std::cout << palavras.size() << std::endl;

  std::sort (palavras.begin(), palavras.end());
  

  printTextAndCount(palavras);

  return 0;
}
