//oriya7914@gamil.com
//213525512
#include <iostream>
#include <vector>
#include "Graph.hpp"
#include <unordered_set>
using namespace std;
namespace ariel{
  enum Color { WHITE, GRAY, BLACK };
    class Algorithms{

       public:
        
      static int isConnected(Graph &graph);
      static std::string negativeCycle(Graph& graph);
      static std::string shortestPath(Graph& graph, int start, int end);
      static bool detectCycleDFS(Graph& graph, size_t node, std::vector<bool>& visited, std::vector<bool>& recStack);
       static std::string isBipartite(Graph& graph);
       static void DFS(Graph &graph, size_t node, std::vector<bool> &visited);
       static bool isContainsCycle(  Graph& g);
       static bool isContainsCycleUtil(Graph& g, size_t src, std::vector<Color>* colors, std::vector<int>* parents, std::vector<int>* path);
      
      

    };


}