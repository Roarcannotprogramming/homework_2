#pragma once
using namespace std;
#include <string>

class DicNode
{
public:
	DicNode();
	virtual ~DicNode();
public:
	int count;
	bool word;
	DicNode* next[26];
};

class Dic //: public AddWord
{
public:
	Dic();
	virtual ~Dic();

private:
	DicNode * head;

public:
	//bool    addFilter(Filter* filter);
	bool    addWord(string word);
	//bool    travel(WordSord* pool);

private:
	//void    travel_inside(DicNode* p, string data, WordSord* pool);
	//vector<Filter*> filter_array;

};
