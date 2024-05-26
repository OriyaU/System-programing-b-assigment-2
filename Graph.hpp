// oriya7914@gamil.com
// 213525512
#include <iostream>
#include <vector>
#pragma once
using namespace std;
namespace ariel
{
  class Graph
  {
  private:
    vector<vector<int>> adjMatrix;
    int numedges;
    size_t numvertices;
    bool directedGraph;
    bool weightedGraph;

    size_t countEdgesDirect() const;

  public:
    std::vector<size_t> getNeighbors(size_t node);
    void loadGraph(vector<vector<int>> &Matrix);
    string printGraph();
    //std::string printGraph() const ;
    //std::string printGraph() const;
    std::vector<std::vector<int>> getMatrix() const;
    size_t getNumOfVertices() const;
    bool checkEdge(size_t node, size_t node2);
    bool isDirected();

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Graph operator+(const Graph &other);
    Graph &operator+=(const Graph &other);
    Graph operator+() const;
    Graph operator-(const Graph &other);
    Graph &operator-=(const Graph &other);
    Graph operator-() const;

    bool operator<(const Graph &other) const;
    bool operator>(const Graph &other) const;
    bool operator>=(const Graph &other) const;
    bool operator<=(const Graph &other) const;
    bool operator==(const Graph &other) const;
    bool operator!=(const Graph &other) const;

    Graph &operator++();   // Pre-increment
    Graph operator++(int); // Post-increment
    Graph &operator--();   // Pre-decrement
    Graph operator--(int); // Post-decrement

    Graph operator*(int);
    Graph operator*=(int);
    Graph operator*(const Graph &other) const;
    Graph operator*=(const Graph &other);

    Graph operator/(int num);
    Graph operator/=(int num);

    friend Graph operator*(int num, const Graph &graph);
    
    friend std::ostream &operator<<(std::ostream &os, const Graph &graph);
  };

}
