#include <iostream>
#include <vector>
#include <algorithm>

#include "Graph.h"
#include "Knoten.h"

void draw_grid(const Graph& graph){
	
	std::vector<std::vector<std::string>> vec2D(graph.length, std::vector<std::string>(graph.width, "#"));
	vec2D[graph.startPoint.getY()][graph.startPoint.getX()] = "S ";
	
	std::queue<Knoten*> notSearched;
	std::vector<Knoten*> searched;
	
	notSearched.push(graph.startPoint);
	while (!notSearched.empty()) {
		Knoten current = notSearched.pop();
		vec2D[current.getY()][current.getX()] = " #";
		for(int i=0; i!=graph.knoten.neighbors.size(); i++) {
			// Knoten *temp =  graph.knoten.neighbors[i];
			Knoten *temp =  graph.knoten.neighbors[i];
			if (std::find(searched.begin(), searched.end(), temp) == searched.end()) {		//Verificar!!!
				notSearched.push(temp);
			}
		}
	}
	
	for(int i=0; i<vec2D.size(); i++) {
		for(int j=0; j<vec2D[i].size(); j++) {
			std::cout << vec2D[i][j];
		}
		std::cout << "\n";
	}
}