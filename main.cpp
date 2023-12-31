#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using std::cout;
using std::ifstream;
using std::string;
using std::stringstream;

int main(int argc, char *argv[])
{
  if (argc != 2)
    return -1;
  unsigned int map[10][9];
  unsigned int y = 0;
  unsigned int x = 0;
  ifstream ifs(argv[1]);
  while (!ifs.eof())
  {
    x = 0;
    string temp = "";
    getline(ifs, temp);
    stringstream ss(temp);
    while (ss && y < 9)
    {
      string s = "";
      ss >> s;
      map[y][x] = atoi(s.c_str());
      x++;
    }
    y++;
  }

  for (int y = 0; y < 9; y++)
  {
    for (int x = 0; x < 9; x++)
    {
      cout << map[y][x] << " ";
    }
    cout << '\n';
  }

  return 0;
}