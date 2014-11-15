#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

#define NUM_CHAR 26

struct TrieNode
{
	int value;
	TrieNode* children[NUM_CHAR];
};


TrieNode* create()
{
	TrieNode *n = new TrieNode;
	if(n == NULL) return NULL;
	n->value = 0;
	for(int i=0; i<NUM_CHAR; i++)
		n->children[i] = NULL;
	return n;
}

void insert1(TrieNode* root, string &word)
{
	const int n = word.size();
	TrieNode *cur = root;

	for(int i=0; i<n; i++)
	{
		if(cur->children[word[i]-'a'] == NULL)
			cur->children[word[i]-'a'] = create();
		cur = cur->children[word[i]-'a'];
	}
	cur->value = n;
}

bool query(TrieNode* root, string &word)
{
	const int n = word.size();
	TrieNode *cur = root;
	for(int i=0; i<n; i++)
	{
		if(cur->children[word[i]-'a'] == NULL)
			return false;
		cur = cur->children[word[i]-'a'];
	}
	return cur->value != 0;
}

void remove(TrieNode* root)
{
	for(int i=0; i<NUM_CHAR; i++)
	{
		if(root->children[i])
			remove(root->children[i]); 
	}
	delete root;
}

class wordGroup
{
public:
	wordGroup(){}

	void insert(string &word)
	{
		if(hash.find(word) != hash.end())
			return;
		words.push_back(word);
		hash.insert(word);
	}

	int length()
	{
		return words.size();
	}

	void createTrie()
	{
		trie = create();

		for(int i=0; i<words.size(); i++)
		{
			insert1(trie, words[i]);
		}
	}

	bool queryPartial(string &str)
	{
		const int n = str.size();
		TrieNode *cur = trie;
		for(int i=0; i<n; i++)
		{
			if(cur->children[str[i]-'a'] == NULL)
				return false;
			cur = cur->children[str[i]-'a'];
		}
		return true;
	}

	bool query(string &str)
	{
		return hash.find(str) != hash.end();
	}

	static vector<wordGroup*> createWordGroup(unordered_set<string> &wordList)
	{
		int maxlen = -1;
		for(auto str: wordList)
			maxlen = max(maxlen, (int)(str.size()));

		vector<wordGroup*> groups(maxlen+1);

		for(auto str: wordList)
		{
			const int len = str.size();
			if(groups[len] == NULL)
				groups[len] = new wordGroup();

			groups[len]->insert(str);
		}

		//return groups;

		for(int i=1; i<=maxlen; i++)
			if(groups[i])
				groups[i]->createTrie();

		return groups;
	}

	vector<string>& getWords()
	{
		return this->words;
	}

private:
	vector<string> words;
	unordered_set<string> hash;
	TrieNode *trie;
};

class wordSquare
{
public:

	wordSquare(int size, wordGroup *group)
	{
		this->size = size;
		this->group = group;
	}

	void appendLine(string &word)
	{
		if(word.size() != size)
			cout << "error !!! " << size << " " << word.size() << endl;
		square.push_back(word);
	}

	bool valid()
	{
		if(square.size() == 0)
			return true;

		for(int i=0; i<square[0].size(); i++)
		{
			string col = getColumn(i);
			if(group->queryPartial(col) == false)
				return false;
		}
		return true;
	}

	bool finalValid()
	{
		if(square.size() == 0)
			return false;

		for(int i=0; i<square[0].size(); i++)
		{
			string col = getColumn(i);
			if(group->query(col) == false)
				return false;
		}
		return true;
	}

	void removeLine()
	{
		square.pop_back();
	}

	string getColumn(int col)
	{
		string column;
		for(int i=0; i<square.size(); i++)
		{
			column += square[i][col];
		}
		return column;
	}

	int getSize()
	{
		return this->size;
	}

	int getLine()
	{
		return this->square.size();
	}

	wordGroup *getGroup()
	{
		return this->group;
	}

	void output()
	{
		cout << endl;
		for(int i=0; i<square.size(); i++)
			cout << square[i] << endl;
		cout << endl;
	}

private:
	vector<string> square;
	wordGroup *group;
	int size;
};


bool process(string &word)
{
	for(int j=0; j<word.size(); j++)
	{
		if(word[j] == '\'')
		{
			word.resize(j);
			break;
		}
		word[j] = ::tolower(word[j]);
		if(word[j] < 'a' || word[j] > 'z')
			return false;
	}
	return true;
}

void dfs(wordSquare* square, vector<string>& words)
{
	wordGroup *group = square->getGroup();

	if(square->getLine() >= square->getSize())
	{
		if(square->finalValid())
			square->output();
		return;
	}

	if(square->valid())
	{
		for(int i=0; i<words.size(); i++)
		{
			square->appendLine(words[i]);
			dfs(square, words);
			square->removeLine();
		}
	}
}

int main()
{
	fstream fin("dict", fstream::in);
	char line[256];
	unordered_set<string> wordList;
	while(!fin.eof())
	{
		fin.getline(line, 256);
		string str(line);
		if(process(str))
			wordList.insert(str);
	}

	vector<wordGroup*> groups = wordGroup::createWordGroup(wordList);
	int max_len = groups.size()-1;
	cout << "max_len is " << max_len << " " << wordList.size() << endl;

	for(int len = 2; len <= max_len; len++)
	{
		if(groups[len] == NULL || groups[len]->getWords().size() < max_len)
			continue;

		wordSquare *square = new wordSquare(len, groups[len]);
		dfs(square, groups[len]->getWords());
	}
	return 0;
}
