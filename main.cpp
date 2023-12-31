#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using std::cerr;
using std::cout;
using std::ifstream;
using std::string;
using std::stringstream;

int input_check(int argc, string argv)
{
  if (argc != 2)
  {
    cerr << "텍스트 파일 하나가 입력값이어야 합니다.\n";
    return 1;
  }
  if (argv.compare("sudoku.txt"))
  {
    cerr << "텍스트 파일은 sudoku.txt 만 허용합니다.\n";
    return 1;
  }
  return 0;
}

void print_map(unsigned int map[10][9])
{
  for (unsigned int y = 0; y < 9; y++)
  {
    for (unsigned int x = 0; x < 9; x++)
    {
      cout << map[y][x] << " ";
    }
    cout << '\n';
  }
}

int main(int argc, char *argv[])
{
  if (input_check(argc, argv[argc - 1]))
  {
    return 1;
  }
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

  print_map(map);

  return 0;
}