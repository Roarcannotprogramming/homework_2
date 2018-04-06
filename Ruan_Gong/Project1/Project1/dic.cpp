#include "dic.h"



DicNode::DicNode()
{
	this->count = 0;
	this->word = false;
	for (int i = 0; i < 26; ++i)
	{
		this->next[i] = NULL;
	}
}

DicNode::~DicNode()
{
	for (int i = 0; i < 26; ++i)
	{
		if (this->next[i])
		{
			delete next[i];
			this->next[i] = NULL;
		}
	}
}


Dic::Dic()
{
	this->head = new DicNode();
}

Dic::~Dic()
{
	if (this->head)
	{
		delete this->head;
		this->head = NULL;
	}
}

/*bool Dic::addFilter(Filter* filter)
{
	if (NULL == filter)
	{
		return false;
	}
	this->filter_array.push_back(filter);
	return true;
}*/

bool Dic::addWord(std::string word)
{
	DicNode* p = this->head;
	for (int i = 0; i < (int)word.length(); ++i)
	{
		// ≈–∂œ «≤ª «“™±ª»•≥˝µÙ  
		for (int j = 0; j <this->filter_array.size(); ++j)
		{
			if (this->filter_array[j]->existWord(word))
			{
				return true;
			}
		}

		// ◊™≥…–°–¥  
		if (word[i] >= 'A' && word[i] <= 'Z')
		{
			word[i] = word[i] - 'A' + 'a';
		}

		int index = word[i] - 'a';

		if (NULL == p->next[index])
		{
			p->next[index] = new DicNode();
		}
		p = p->next[index];

		if (i == word.length() - 1)
		{
			p->word = true;
			p->count++;
		}
	}
	return true;
}

/*bool Dic::travel(WordSord* pool)
{
	if (NULL == pool)
	{
		return false;
	}

	string data;
	this->travel_inside(this->head, data, pool);
	return true;
}*/

/*void Dic::travel_inside(DicNode* p, string data, WordSord* pool)
{
	if (NULL == p)
	{
		return;
	}

	if (p->word)
	{
		//cout <<data <<" " << p->count<< endl ;  
		pool->addString(data, p->count);
	}

	for (int i = 0; i < 26; ++i)
	{
		if (p->next[i])
		{
			string temp = data + char('a' + i);
			travel_inside(p->next[i], temp, pool);
		}
	}
}*/
