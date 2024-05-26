/*
 * Demo program for Exercise 3.
 * Author: Benjamin Saldman.
 */
//oriya7914@gamil.com
//213525512
#include "Graph.hpp"
#include "Algorithms.hpp"
using ariel::Algorithms;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{
    ariel::Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph); // Load the graph to the object.

    cout << g1; // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]
    //cout<<"jjjj";
    
    // 3x3 matrix that represents a weighted connected graph.
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    ariel::Graph g2;
    g2.loadGraph(weightedGraph); // Load the graph to the object.

    ariel::Graph g3 = g1 + g2; // Add the two graphs together.
    cout << g3;                // Should print the matrix of the graph: [0, 2, 1], [2, 0, 3], [1, 3, 0]
   cout<<g3.printGraph();
cout<<"****11******";
   vector<vector<int>> graph3 = {
         {0, -1, -1},
        {-1, 0, -2},
        {-1, -2, 0}};
    ariel::Graph g7;
    g7.loadGraph(graph3);
   
   
    ariel::Graph g8 = g2+g7;
    cout<<g8.printGraph();
    
cout<<"****22******";





    


    

    // ariel::Graph g50=-g1;

    // g1+=g2;
    //  cout<<g1;
    // vector<vector<int>> weightedGraph2 = {
    //     {0, 1},
    //     {1, 0}};
    // ariel::Graph g10;
    // g10.loadGraph(weightedGraph2); // Load the graph to the object.
    // bool flag=g1!=g10;
    // cout<<flag<<"MMMMMM";

    cout << "\n";

    g1 *= -2;   // Multiply the graph by -2.
    cout << g1; // Should print the matrix of the graph: [0, -2, 0], [-2, 0, -2], [0, -2, 0]
    cout << "\n";
    g1 /= -5;
    ariel::Graph g4 = g1 * g2; // Multiply the two graphs together.
    cout << g4;                // Should print the multiplication of the matrices of g1 and g2: [0, 0, 2], [1, 0, 1], [1, 0, 0]

    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    ariel::Graph g5;
    g5.loadGraph(graph2); // Load the graph to the object.
    try
    {
        ariel::Graph g6 = g5 * g1; // Multiply the two graphs together.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print "The number of columns in the first matrix must be equal to the number of rows in the second matrix."
    }
}