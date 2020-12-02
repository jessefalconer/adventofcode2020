#include <algorithm>
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
using namespace std;

bool checkSledPassword(int min, int max, char character, string password)
{
  int count = std::count(password.begin(), password.end(), character);
  return (count >= min && count <= max);
}

bool checkTobogganPassword(int min, int max, char character, string password)
{
  return ((password[min-1] == character) != (password[max-1] == character));
}

int main()
{
  std::ifstream infile("2.txt");
  std::string line;
  const std::regex pwd_regex("(\\d+)-(\\d+) ([a-z]): ([a-z]+)");
  std::smatch pwd_match;
  int sledCounter = 0;
  int tobogganCounter = 0;

  while (std::getline(infile, line))
  {
    std::regex_search(line, pwd_match, pwd_regex);
    int min = std::stoi(pwd_match[1]);
    int max = std::stoi(pwd_match[2]);
    char character = std::string(pwd_match[3]).at(0);
    string password = pwd_match[4];

    if (checkSledPassword(min, max, character, password))
    {
      sledCounter += 1;
    }
    if (checkTobogganPassword(min, max, character, password))
    {
      tobogganCounter += 1;
    }
  }

  cout << sledCounter << endl;
  cout << tobogganCounter;
}
