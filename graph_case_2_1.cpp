#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<tuple>
using namespace std;
/*simple weighted directed graph*/

struct Edge {
	int tail, head, weight;
};
class Graph {
private:
	vector<vector<pair<int,int>>> adjList;
	int order = 0; int size=0;
public:
	Graph(vector<Edge> const &edges, int N){
		adjList.resize(N);
		order = N;
		for (auto &edge : edges){
			int tail = edge.tail;
			int head = edge.head;
			int weight = edge.weight;
			adjList[tail].push_back(make_pair(head, weight));
			size += 1;
		}
	}
	void add_edge(int a, int b, int c) { adjList[a].push_back(make_pair(b, c)); size += 1; }
	void delete_edge(int a, int b){ 
		for (auto &x : adjList[a]) {
			if (x.first == b) {
				pair<int, int>* it = &x;
				*it = move(adjList[a].back());
				adjList[a].pop_back();
			}
		}
		size -=1; }
	void add_node() { 
		adjList.push_back({});
		order += 1; }
	void delete_node(int a) {
		size = size - adjList[a].size();
		adjList[a] = move(adjList.back());
		adjList.pop_back();
		order -= 1;
	}
	bool is_edge(int a,int b){
		for (auto &x : adjList[a]) {
			if (x.first == b) {
				return true;
			}
		}
		return false;
	}
	int get_weight(int a,int b) {
		for (auto &x : adjList[a]) {
			if (x.first == b) {
				return x.second;
			}
		}
	}
	void printGraph(Graph const &graph, int N){
		for (int i = 0; i < N; i++){
			for (pair<int, int> v : graph.adjList[i]) {
				cout << "(" << i << ", " << v.first <<
					", " << v.second << ") ";
			}
			if (!adjList[i].empty()) { cout << endl; }
		}
	}
};
int main() {
	Graph G({ {0,1,10},{0,3,15},{1,2,22},{3,2,25} }, 4);
	G.printGraph(G,4);
	cout << G.is_edge(0, 1) << endl;
	cout << G.get_weight(0, 1) << endl;
	G.add_edge(2,0,42);
	G.printGraph(G, 4);
	G.delete_edge(2, 0);
	G.printGraph(G, 4);
	cin.get();
	return 0;
}