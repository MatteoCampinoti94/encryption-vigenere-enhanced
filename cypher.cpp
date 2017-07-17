#include "cypher.h"


int key_val(const std::string& key, const int& pos)
{
  return key[pos%key.length()];
}

void code (std::fstream& file, const std::string& key, const int& coding)
{
  char c;

  for (int i=0; file.get(c); i++)
  {
    c+=coding*key_val(key, i);

    file.seekg(i, file.beg);

    file.put(c);
  }
}
