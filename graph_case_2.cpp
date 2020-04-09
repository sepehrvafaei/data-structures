#include<iostream>
#include<vector>
#include<utility>
#include<string>
using namespace std;
/*simple weighted directed graph*/

class Node {
public:
	string name;
	vector<pair<string,int>> neighbours;
};
class Graph {
private:
	int order, size;
	vector<Node> adjList;
public:
	void add_edge(vector<pair<string,string>,int>){}
	void add_edge(string u,string v,int wt) {}
	void remove_edge(string u,string v){}
	void is_edge(string u,string v){}
	vector<pair<string, int>> get_neighbours(string u){}
};
int main() {
	Graph G;
	cin.get();
	return 0;
}
