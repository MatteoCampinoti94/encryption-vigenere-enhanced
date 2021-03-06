#include "cypher.h"


int key_val(const std::string& key, const int& pos)
{
  return key[pos%key.length()];
}

void code (std::fstream& file, const double& size, const std::string& key, const int& coding)
{
  char c;
  setbuf(stdout, NULL);

  for (int i=0; file.get(c); i++)
  {
    printf("\rCompletion: %.2f%%", (i/size)*100 );

    c+=coding*key_val(key, i);

    file.seekg(i, file.beg);

    file.put(c);
  }
  printf("\rCompletion: 100.00%%\n");
}
