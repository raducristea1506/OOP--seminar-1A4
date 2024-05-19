#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include <cctype>
using namespace std;
ifstream file("input.txt");
class Comparare
{
public:
	bool operator()(pair<string, int>& c1, pair<string, int>& c2)
	{
		if (c1.second != c2.second)  return c1.second < c2.second;
		else return c1.first > c2.first;

	}
};
string TransformareLiteraMica(const string& cuv)
{
	int i;
	string rez;
	for (i = 0; i < cuv.length(); i++)
		rez += tolower(cuv[i]);
	return rez;

}
vector<string> DespartireInCuv(const string& text, const string& delimitatori)
{
	vector<string> cuvinte;
	int i, j;
	size_t index1;
	index1 = text.find_first_not_of(delimitatori);
	while (index1 != string::npos)
	{
		size_t index2 = text.find_first_of(delimitatori, index1);
		cuvinte.push_back(text.substr(index1, index2 - index1));
		index1 = text.find_first_not_of(delimitatori, index2);
	}
	return cuvinte;
}
int main()
{
    string text="I bought an apple. Then I eat an apple. Apple is my favorite.";
	getline(file, text);
	string delimitatori = " ,?!.";
	vector<string> cuvinte = DespartireInCuv(text, delimitatori);
	map<string, int> wordcount;
	for (const auto& cuv : cuvinte)
	{
		string cuvliteremici = TransformareLiteraMica(cuv);
		wordcount[cuvliteremici]++;
	}
	priority_queue<pair<string, int>, vector<pair<string, int>>, Comparare> wordqueue;
	for (auto& pair : wordcount) wordqueue.push(pair);
	while (!wordqueue.empty())
	{
		cout<<wordqueue.top().first<<" => "<<wordqueue.top().second<< "\n";
		wordqueue.pop();
	}
	file.close();
	return 0;
};