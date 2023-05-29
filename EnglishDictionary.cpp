#include "EnglishDictionary.h"
#include <string>


EnglishDictionary::EnglishDictionary(string a):name(a)
{
    
}


EnglishDictionary::~EnglishDictionary()
{
    
}


int EnglishDictionary::words()const
{
    return dictionary.size();
}


int EnglishDictionary::uniqueWords()const
{
    return dictionary.sizeK();
}


bool EnglishDictionary::empty()const
{
    return dictionary.size() == 0;
}


void EnglishDictionary::add(Entry<string ,string> a)
{
    dictionary.put(a.getK(),a.getV());
}


void EnglishDictionary::deleteFirst(string w)
{
    dictionary.eraseFirst(w);
}


void EnglishDictionary::deleteAll(string w)
{
     dictionary.erase(w);
}


void EnglishDictionary::printDefinition(string x)
{
  Entry<string,string> a;
  a = find(x);
  cout << a;
  
    }

void EnglishDictionary::test(IteratorG<string, string>&p, bool x)
{
  if(x)
  {
  if(p == dictionary.end())
  {
    return;
  }
  else
  {
    cout << p.v->elm;
    ++p;
    test(p,x);
  }
  }
  else
  {
    if(p == dictionary.begin())
    {
      return;
    }
    else
    {
      --p;
      cout << p.v->elm;
      test(p,x);
    }
  }
}

void EnglishDictionary::printDictionary(bool x)
{
   if(x)
   {
     IteratorG<string,string> p = dictionary.begin();
     test(p,x);
   }
  else
   {
     IteratorG<string,string> p = dictionary.end();
     test(p,x);
   }
  
}
Entry<string,string> EnglishDictionary::find(string x)
{
  IteratorG<string, string> p;
  p = dictionary.find(x);
  return p.v->elm;
}




