#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
	TrieNode* arr[26];
	int count;
	int prefCnt;
	bool end;

	TrieNode(){
		count =0;
		prefCnt=0;
		for(int i=0;i<26;i++)
			arr[i] =NULL;
		end=false;
	}

};


class Trie{
public:
	TrieNode* root;

	Trie(){
		root = new TrieNode();
	}

	void insert(const string& word){

		TrieNode* tmp =root;

		for(int i=0;i<word.size();i++){

			int curIdx = word[i]-'a';

			if(tmp->arr[curIdx]==NULL)
				tmp->arr[curIdx] = new TrieNode();

			tmp->prefCnt+=1;

			tmp = tmp->arr[curIdx]; 

		}

		tmp->end = true;
		tmp->count+=1;
		tmp->prefCnt+=1;

	}

	bool isPresent(const string& word){

		TrieNode* tmp = root;

		for(int i=0;i<word.size();i++){

			int curIdx = word[i]-'a';

			if(tmp->arr	[curIdx]==NULL)
				return false;

			tmp = tmp->arr[curIdx];

		}

		return tmp->end==true;

	}


	bool startsWith(const string& prefix){

		TrieNode* tmp = root;

		for(auto&it: prefix){

			if(tmp->arr[it-'a']==NULL)
				return false;
			tmp = tmp->arr[it-'a'];

		}

		return true;

	}

	int wordCount(const string& word){

		TrieNode* tmp = root;

		for(auto&it: word){
			if(tmp->arr[it-'a']==NULL)
				return 0;
			tmp = tmp->arr[it-'a'];
		}

		return tmp->count;

	}

	int prefixCount(const string& prefix){

		TrieNode* tmp = root;

		for(auto&it: prefix){

			if(tmp->arr[it-'a']==NULL)
				return 0;

			tmp = tmp->arr[it-'a'];

		}

		return tmp->prefCnt;

	}



};