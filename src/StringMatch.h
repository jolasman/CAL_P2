#include <string>
#include <vector>
#include <iostream>
using namespace std;


void pre_kmp(string const &pattern, vector<int> &prefix);
int kmp(string const &text, string const &pattern, int &q);