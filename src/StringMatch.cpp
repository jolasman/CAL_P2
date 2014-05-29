#include "StringMatch.h"

/**
Algoritmo de Knuth-Morris-Pratt

*/
void pre_kmp(string const &pattern, vector<int> & prefix)
{
	int m=pattern.length();
	prefix[0]=-1;
	int k=-1;
	for (int q=1; q<m; q++) {
		while (k>-1 && pattern[k+1]!=pattern[q])
			k = prefix[k];
		if (pattern[k+1]==pattern[q]) 
			k=k+1;
		prefix[q]=k;
	}
}

int kmp(string const &text, string const &pattern, int &shift)
{

	if(text.size() < pattern.size())
		return -1;

	int q;
	int num=0;
	int m=pattern.length();
	vector<int> prefix(m);
	pre_kmp(pattern, prefix);

	int n=text.length();

	q=-1;
	for (int i=0; i<n; i++) {
		while (q>-1 && pattern[q+1]!=text[i])
			q=prefix[q];
		if (pattern[q+1]==text[i])
			q++;
		if (q==m-1) {
			shift = i-m+1;
			//cout <<"pattern occurs with shift" << i-m+1 << endl;
			num++;
			q=prefix[q];
		}
	}
	return num;
}