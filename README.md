//oriya7914@gamil.com


Graphs & Operator overloading:

This assignment is a continuation of the first assignmet.The update Graph class  support various arithmetic and comparison operations on graphs represented using an adjacency matrix. 


Important files Included

    Graph.hpp: Header file containing the declaration of the Graph class and its member functions.
    Graph.cpp: Implementation file containing the definition of the Graph class member functions and operator overloads.
    Algorithms.cpp: Implementation file containing various algorithms and functions related to graph operations that we did in the first assigment.



operators-

The addition operators (+,+=) and substraction operator (-,-=)

1.Operator Overload + (Addition):

    Purpose: Adds two graphs element-wise, assuming both graphs have the same number of vertices.
    Example:Graph result = g1 + g2;
2.Operator Overload += (Compound Addition):

    Purpose: Adds another graph to the current graph element-wise, modifying the current graph.
    Example:g1 += g2;
3.Unary Plus Operator Overload +:

    Purpose: Returns a copy of the current graph.
    Example:Graph g2 = +g1;
4.Operator Overload - (Subtraction):

    Purpose: Subtracts one graph from another element-wise, assuming both graphs have the same number of vertices.
    Example:Graph result = g1 - g2;
5.Operator Overload -= (Compound Subtraction):

    Purpose: Subtracts another graph from the current graph element-wise, modifying the current graph.
    Example:g1 -= g2;
6.Unary Minus Operator Overload -:

    Purpose: Returns the negation of the current graph (element-wise negation of adjacency matrix).
    Example:Graph g2 = -g1;

comparison operators:
graph 1 is bigger than graph 2 if  g2 is contained in g1. if not, it bigger if g2 has more edges than g1. if not its bigger if it has more vertexs

1. < (Less Than) Operator Overload:

    Purpose: Determines if the current graph is less than the other graph based on edge count, vertex count, and adjacency matrices.
    Usage:
    if (g1 < g2) 
   
2. > (Greater Than) Operator Overload:

    Purpose: Determines if the current graph is greater than the other graph based on the < operator's logic.
    Usage:
    if (g1 > g2) 

3. >= (Greater Than or Equal To) Operator Overload:

    Purpose: Determines if the current graph is greater than or equal to the other graph based on the < and > operator's logic.
    Usage:
    if (g1 >= g2) 
  
4. <= (Less Than or Equal To) Operator Overload:

    Purpose: Determines if the current graph is less than or equal to the other graph based on the < and > operator's logic.
    Usage:
if (g1 <= g2) 


Equations operators (==,!=)
two graphs are equals if there matrix look exactly the same.
1. == (Equality) Operator Overload:

    Purpose: Checks if two graphs are equal based on their adjacency matrices and vertex/edge counts.
    Usage:
    if (g1 == g2) 
2. != (Inequality) Operator Overload:

    Purpose: Checks if two graphs are not equal based on the == operator's logic.
    Usage:

    if (g1 != g2) 

Multiplication operators (* , *=) and Division operator (/=):

1. Graph Graph::operator*(const Graph &other) const:

    Purpose: Performs matrix multiplication between two graphs. The resulting graph contains the product of the adjacency matrices of the two input graphs.
    Usage:
    Graph result = graph1 * graph2;

2. Graph Graph::operator*=(const Graph &other):

    Purpose: Performs matrix multiplication in place on the current graph by multiplying it with another graph and assigning the result back to the current graph.
    Usage:
    graph1 *= graph2;

3. Graph Graph::operator*(int num):

    Purpose: Multiplies all elements in the adjacency matrix of the graph by a scalar value (num).
    Usage:
    Graph scaledGraph = graph * 2; // Multiply all elements in graph by 2

4. Graph operator*(int num, const Graph &graph):

    Purpose: Multiplies all elements in the adjacency matrix of a graph by a scalar value (num). This is a friend function for convenience.
    Usage:
    Graph scaledGraph = 2 * graph; // Multiply all elements in graph by 2

5. Graph Graph::operator/(int num):

    Purpose: Divides all elements in the adjacency matrix of the graph by a scalar value (num).
    Usage:
    Graph scaledGraph = graph / 2; // Divide all elements in graph by 2

6. Graph Graph::operator/=(int num):

    Purpose: Divides all elements in the adjacency matrix of the graph by a scalar value (num) in place.
    Usage:
    graph /= 2; // Divide all elements in graph by 2 in place



Incerment and decrement - ++prefix & postfix++:

1. Prefix ++ (Increment) Operator Overload:

    Purpose: Increments all non-zero values in the adjacency matrix by 1.
    Usage:
    ++g;

2. Postfix ++ (Increment) Operator Overload:

    Purpose: Increments all non-zero values in the adjacency matrix by 1 and returns the original graph before the increment.
    Usage:
    Graph original = g++;

3. Prefix -- (Decrement) Operator Overload:

    Purpose: Decrements all non-zero values in the adjacency matrix by 1.
    Usage:
    --g;

4. Postfix -- (Decrement) Operator Overload:

    Purpose: Decrements all non-zero values in the adjacency matrix by 1 and returns the original graph before the decrement.
    Usage:
    Graph original = g--;



Printing by << operator
1. Purpose: Overloads the << operator to allow streaming the graph to an output stream (e.g., std::cout).
Usage:
std::cout << graph;


how to run :

     first, clone first the repository to your own computer.

      write: git clone https://github.com/chanan-hash/CPP-Ex1.git

    run  "make" command in your teminal to compile the project 

    make sure you have the right compiler clang-9 or clang++

  tests:
  to run test file:
  run the commend:"make test" and than "./test"







