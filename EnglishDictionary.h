#ifndef ENGLISHDICTIONARY_H
#define ENGLISHDICTIONARY_H
#include "NodeMapG.h"
#include "IteratorG.h"


class EnglishDictionary
{
private:
string name; //will hold the name of the English dictionary
NodeMapG<string, string> dictionary; //will hold the words and their definitions
void test(IteratorG<string,string> &, bool);


public:
 EnglishDictionary (string);
 
 virtual ~ EnglishDictionary ();
 int words() const; // number of words in dictionary
 int uniqueWords() const; // number of unique words in dictionary
 bool empty() const; // is the dictionary empty
 void add(Entry<string,string>); // adds a word with its definition in the dictionary
 void deleteFirst(string); // removes the first word equal to a given string
 void deleteAll(string); // removes from dictionary all the words equal to a given string
 void printDictionary(bool); /*prints all words and definitions. If bool is true print from the 
beginning, else print them from the end of the dictionary (this function should be designed as a 
recursive function).*/
 void printDefinition(string);
 Entry<string,string> find(string); // returns the first word and its definition equal to a given string


};

#endif