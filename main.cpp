#include <iostream>
#include <fstream>
#include "cypher.h"

std::string get_key ();
bool check_file (std::string name);
double file_size (std::string name);
void size_calc(double size);


int main (int argc, char* argv[])
{
  if (argc<2) { std::cout << "No file selected\n" ; exit(1); }
  if (!check_file(argv[1])) { std::cout << "File '" << argv[1] << "' does not exist\n"; exit(2); }
  if (argc<3) { std::cout << "No option selected\n"; exit(3); }

  std::string op=argv[2];

  if (op=="encrypt")
  {
    std::fstream file(argv[1], std::ios::in | std::ios::out);
    std::string key=get_key();

    double size=file_size(argv[1]);
    size_calc(size);

    code(file, size, key, 1);
  }
  else if (op=="decrypt")
  {
    std::fstream file(argv[1], std::ios::in | std::ios::out);
    std::string key=get_key();

    double size=file_size(argv[1]);
    size_calc(size);

    code(file, size, key, -1);
  }

  else { std::cout << "Invalid option. Use decrypt or encrypt\n"; exit(3); }

  return 0;
}


std::string get_key ()
{
  std::string key;

  do
  {
    printf("Type key: ");
    getline(std::cin, key);
  } while (key.length()==0);

  return key;
}

bool check_file (std::string name)
{
  std::ifstream file(name.c_str());

  if (file.fail()) { return false; }
  else { file.close(); return true; }
}

double file_size (std::string name)
{
  std::ifstream fsize(name.c_str(), std::ios::ate);

  double tmp=fsize.tellg();
  fsize.close();

  return tmp;
}

void size_calc(double size)
{
  char pw='B';

  if (size>=1024) { size/=1024; pw='K'; }
  if (size>=1024) { size/=1024; pw='M'; }
  if (size>=1024) { size/=1024; pw='G'; }

  printf("Size: %.2f%c\n", size, pw);
}
