#include "cypher.h"


int key_val(const std::string& key, const int& pos)
{
  return key[pos%key.length()];
}

void code (std::fstream& file, const double& size, const std::string& key, const int& coding)
{
  char c;
  double cmpl=size/10;

  for (int i=0; file.get(c); i++)
  {
    if ((i+1)>=cmpl) { printf("*"); cmpl+=size/10; }

    c+=coding*key_val(key, i);

    file.seekg(i, file.beg);

    file.put(c);
  }
  printf("\n");
}
