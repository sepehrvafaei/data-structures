#include<iostream>
#include<vector>
using namespace std;
class Graph {
private:
	int num_edges;int num_nodes;
	vector<vector<int>> adjList;
	
public:
	Graph(int n) {
		adjList.resize(n);
		this->num_nodes = n; }
	Graph(int array[][2], int rows,int n) {
		adjList.resize(n);
		this->num_nodes = n;
		for (int i = 0; i < rows; i++) {
			this->add_edge(array[i][0],array[i][1]);
		}
	}
	int num_of_edges() { return num_edges; }
	int num_of_nodes() { return num_nodes; }
	void add_edge(int u, int v) {
		adjList[u].push_back(v); 
		adjList[v].push_back(u); 
		this->num_edges += 1; }
	void add_edge(int u, vector<int> nodes) {
		for (auto x : nodes) { add_edge(u,x); }
	}
	void delete_edge(int u, int v) {
		auto it = std::find(adjList[u].begin(), adjList[u].end(), v);
		if (it != adjList[u].end()) {
			swap(*it, adjList[u].back());
			adjList[u].pop_back();
		}
		auto it_ = find(adjList[v].begin(), adjList[v].end(), u);
		if (it_ != adjList[v].end()) {
			swap(*it_, adjList[v].back());
			adjList[v].pop_back();
		}
		num_edges -= 1;
	}
	bool is_edge(int u,int v){
		if (count(adjList[u].begin(), adjList[u].end(), v)) { return true; }
		else { return false; }
	}
	vector<int> neighbours(int u) { return adjList[u];}
	int degree(int u) { return adjList[u].size(); }
	void print() {
		for (int i = 0; i < num_nodes; i++) {
			cout << i << "->";
			for (auto x : adjList[i]) {
				cout << x << ',';
			}
			cout << endl;
		}
	}
};
int main() {
	Graph G(3);
	G.add_edge(0, 1);
	G.add_edge(0, 2);
	cout << "is there edge between nodes 1 & 2:"<<(G.is_edge(1, 2) ? "yes":"no") << endl;
	cout << "is there edge between nodes 0 & 1:" << (G.is_edge(0, 1) ? "yes" : "no") << endl;
	cout << G.num_of_edges() << endl;
	cout << G.num_of_nodes()<< endl;
	cout << G.degree(0) << endl;
	vector<int> neighbours = G.neighbours(0);
	cout << "node 0 neighbours: ";
	for (auto x : neighbours) { cout << x << ", "; }
	cout << endl;
	G.add_edge(2, 1);
	cout << "is there edge between nodes 1 & 2:" << (G.is_edge(1, 2) ? "yes" : "no") << endl;
	G.print();
	cin.get();
	return 0;
}
