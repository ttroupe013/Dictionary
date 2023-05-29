#include <iostream>

using namespace std;

#include "NodeMapG.h"

#include "DNodeG.h"
#include "IteratorG.h"
#include "EnglishDictionary.h"
#include "Entry.h"
int main()
{
EnglishDictionary a1("Webster");
  Entry<string,string> b("Rogue", "A dishonest or unprincipled person");
  Entry<string,string> c("Silent", "Not making or accompanied by any sound");
  Entry<string,string> d("Tyler", "A grown man");
  Entry<string,string> e("Iron Man", "A super hero");
  a1.add(b);
  a1.add(c);
  a1.add(d);
  a1.add(e);
  a1.printDictionary(1);  
  cout << endl;
  a1.printDefinition("Iron Man");
  cout << endl;
  cout << endl;

  cout << a1.words() << "\t" << a1.uniqueWords();
  a1.deleteFirst("Silent");
  a1.printDictionary(1);
  a1.deleteAll("Iron Man");
  cout << endl;
  a1.printDictionary(1);

   a1.find("Tyler");
  

  
}