#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int countTrees(int rise, int run){
  std::ifstream infile("3.txt");
  std::string line;
  int treesHit = 0;
  int position_x = 0;
  int position_dy = rise;

  while (std::getline(infile, line))
  {
    int size = line.size();

    if (rise - position_dy != 0)
    {
      position_dy += 1;
      continue;
    }

    if (line[position_x] == '#')
    {
      treesHit += 1;
    }

    if ((position_x + run) > (size - 1))
    {
      position_x = position_x - size;
    }

    if (position_dy - 1 == 0) {
      position_dy = rise;
    } else {
      position_dy -= 1;
    }

    position_x += run;
  }

  return treesHit;
}

int main()
{
  int result = 1;
  std::vector<std::pair<int, int>> slopes {{1, 1}, {1, 3}, {1, 5}, {1, 7}, {2, 1}};
  for (auto slope : slopes){
    result = result * countTrees(slope.first, slope.second);
  }

  cout << result;
}
