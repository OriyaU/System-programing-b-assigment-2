// oriya7914@gamil.com
// 213525512

#include "Graph.hpp"
#include <iostream>
#include <stdexcept>
#include <sstream>
using namespace std;

namespace ariel
{
    std::vector<size_t> Graph::getNeighbors(size_t node)
    {
        std::vector<size_t> neighbors;
        if (node >= this->numvertices)
        {
            throw std::invalid_argument("Invalid vertex index");
        }

        for (size_t i = 0; i < this->numvertices; ++i)
        {
            if (this->adjMatrix[node][i] != 0)
            {
                neighbors.push_back(i);
            }
        }

        return neighbors;
    }

    string Graph::printGraph()
    {

        string output = "";

        for (size_t i = 0; i < this->numvertices; i++)
        {
            output += "[";

            for (size_t j = 0; j < this->numvertices; j++)
            {
                output += to_string(adjMatrix[i][j]);

                if (j < this->numvertices - 1)
                {
                    output += ", ";
                }
            }
            output += "]";
            if (this->numvertices != i + 1)
            {
                output += "\n";
            }
        }

        return output;
    }

    bool Graph::isDirected()
    {
        return this->directedGraph;
    }

    vector<vector<int>> Graph::getMatrix() const
    {
        return this->adjMatrix;
    }

    size_t Graph::getNumOfVertices() const
    {
        return this->numvertices;
    }

    bool Graph::checkEdge(size_t node, size_t node2)
    {
        if (this->adjMatrix[node][node2] != 0)
        {
            return true;
        }
        return false;
    }

    void Graph::loadGraph(vector<vector<int>> &adjMatrix)
    {
        if (adjMatrix.size() != adjMatrix[0].size())
        {
            throw invalid_argument("Invalid graph: The graph is not a square matrix");
        }

        this->numvertices = adjMatrix.size();
        this->numedges = 0;
        this->adjMatrix = adjMatrix;
        this->directedGraph = false;
        this->weightedGraph = false;

        for (size_t i = 0; i < this->numvertices; ++i)
        {
            for (size_t j = 0; j < this->numvertices; ++j)
            {
                if (adjMatrix[i][j] != adjMatrix[j][i])
                {
                    this->directedGraph = true;
                    break; // Early exit if directedness is confirmed
                }
            }
            if (this->directedGraph)
            {
                break;
            }
        }

        for (size_t i = 0; i < this->numvertices; ++i)
        {
            for (size_t j = 0; j < this->numvertices; ++j)
            {
                if (adjMatrix[i][j] != 0)
                {
                    this->numedges = this->numedges + 1;
                }
            }
        }

        // cout << "Graph with " << this->numedges << " edges.\n";
        //  if the graph is directed, it has half the number of edges
        if (!this->directedGraph)
        {

            this->numedges = this->numedges / 2;
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Adds two graphs element-wise, assuming both graphs have the same number of vertices.
    Graph Graph::operator+(const Graph &other)
    {
        // Checking if the number of vertices in both graphs is the same
        if (this->numvertices != other.numvertices)
        {
            throw invalid_argument("The number of vertices in both graphs must be the same");
        }

        Graph result; // Create a new graph object to store the result

        result.numvertices = this->numvertices; // The number of vertices should be the same

        // Adding the two adjacency matrices
        for (size_t i = 0; i < this->numvertices; i++)
        {
            vector<int> row;
            for (size_t j = 0; j < this->numvertices; j++)
            {
                row.push_back(this->adjMatrix[i][j] + other.adjMatrix[i][j]);
            }
            result.adjMatrix.push_back(row);
        }
        cout << "\n";
        return result;
    }
    // Adds another graph to the current graph element-wise, modifying the current graph.
    Graph &Graph::operator+=(const Graph &other)
    {
        // Check if the number of vertices in both graphs is the same
        if (this->numvertices != other.numvertices)
        {
            throw std::invalid_argument("The number of vertices in both graphs must be the same");
        }

        // Add the adjacency matrices of the two graphs
        for (size_t i = 0; i < this->numvertices; ++i)
        {
            for (size_t j = 0; j < this->numvertices; ++j)
            {
                this->adjMatrix[i][j] += other.adjMatrix[i][j];
            }
        }

        return *this; // Return the modified graph
    }

    // Unary plus operator
    Graph Graph::operator+() const
    {
        return *this; // Return a copy of the current graph
    }
    // Subtracts one graph from another element-wise, assuming both graphs have the same number of vertices.
    Graph Graph::operator-(const Graph &other)
    {
        // Checking if the number of vertices in both graphs is the same
        if (this->numvertices != other.numvertices)
        {
            throw invalid_argument("The number of vertices in both graphs must be the same");
        }

        Graph result; // Create a new graph object to store the result

        result.numvertices = this->numvertices; // The number of vertices should be the same

        // decreasing the two adjacency matrices
        for (size_t i = 0; i < this->numvertices; i++)
        {
            vector<int> row;
            for (size_t j = 0; j < this->numvertices; j++)
            {
                row.push_back(this->adjMatrix[i][j] - other.adjMatrix[i][j]);
            }
            result.adjMatrix.push_back(row);
        }
        // cout << "\n";
        return result;
    }
    // Subtracts another graph from the current graph element-wise, modifying the current graph.
    Graph &Graph::operator-=(const Graph &other)
    {
        // Check if the number of vertices in both graphs is the same
        if (this->numvertices != other.numvertices)
        {
            throw std::invalid_argument("The number of vertices in both graphs must be the same");
        }
        // decrease the adjacency matrices of the two graphs
        for (size_t i = 0; i < this->numvertices; ++i)
        {
            for (size_t j = 0; j < this->numvertices; ++j)
            {
                this->adjMatrix[i][j] -= other.adjMatrix[i][j];
            }
        }

        return *this; // Return the modified graph
    }
    // Unary minus operator
    Graph Graph::operator-() const
    {
        Graph unary;
        unary.numvertices = this->numvertices;

        for (size_t i = 0; i < this->numvertices; ++i)
        {
            vector<int> row;
            for (size_t j = 0; j < this->numvertices; ++j)
            {
                int w = -1 * this->adjMatrix[i][j];

                row.push_back(w);
            }
            unary.adjMatrix.push_back(row);
        }

        return unary; // Return the modified graph
    }
    // count adge
    size_t Graph::countEdgesDirect() const
    {
        size_t count = 0;
        for (const auto &row : this->adjMatrix)
        {
            for (int val : row)
            {
                if (val != 0)
                {
                    count++;
                }
            }
        }
        return count; // Assuming all graphs are directed, each edge is counted twice. i do that because i want him to se un undirected graph with 4 edes wich has actually 8 edjes in undirectet graph. so it will be bigger than undirected graph whith 6 edge/
    }
    // graph 1 is bigger than graph 2 if  g2 is contained in g1. if not, it bigger if g2 has more edges than g1. if not its bigger if it has more vertexs
    bool Graph::operator<(const Graph &other) const
    {
        // Compare the number of edges in this graph and the other graph
        if (this->countEdgesDirect() > other.countEdgesDirect())
        {
            return false; // If this graph has more edges, it is not less than the other graph
        }

        // Compare the number of vertices in this graph and the other graph
        if (this->numvertices > other.numvertices)
        {
            return false; // If this graph has more vertices, it is not less than the other graph
        }

        // Compare adjacency matrices element-wise
        for (size_t i = 0; i < this->numvertices; ++i)
        {
            for (size_t j = 0; j < this->numvertices; ++j)
            {
                // If an edge exists in this graph but not in the other graph, this graph is not less
                if (this->adjMatrix[i][j] != 0 && other.adjMatrix[i][j] == 0)
                {
                    return false;
                }
            }
        }

        // If the number of vertices is less in this graph or the edge count is less, this graph is less
        if (this->numvertices < other.numvertices || this->countEdgesDirect() < other.countEdgesDirect())
        {
            return true;
        }

        // If none of the above conditions are met, this graph is not less than the other graph
        return false;
    }
    // the opposite function of <
    bool Graph::operator>(const Graph &other) const
    {
        return other < *this;
    }

    bool Graph::operator>=(const Graph &other) const
    {
        return !(*this < other);
    }
    bool Graph::operator<=(const Graph &other) const
    {
        return !(*this > other);
    }
    // Checks if two graphs are equal based on their adjacency matrices and vertex/edge counts.
    bool Graph::operator==(const Graph &other) const
    {
        // Check if the sizes of the two graphs are the same
        if (this->numvertices != other.numvertices)
        {
            return false;
        }

        if (this->countEdgesDirect() != other.countEdgesDirect())
        {
            return false;
        }

        // Compare the adjacency matrices
        for (size_t i = 0; i < this->numvertices; i++)
        {
            for (size_t j = 0; j < this->numvertices; j++)
            {
                if (this->adjMatrix[i][j] != other.adjMatrix[i][j])
                {
                    return false;
                }
            }
        }
        // i dont think this if is nassery because if we came to this place at the code it means that they look exactly the same. so of course, no matrrix bigger than the other.
        //  if((*this < other) ||(other < *this))
        //  {
        //      return false;
        //  }

        return true;
    }
    bool Graph::operator!=(const Graph &other) const
    {
        return !(*this == other);
    }
    // increments all non-zero values in the adjacency matrix by 1.
    Graph &Graph::operator++()
    {
        // Increment all the values in the adjacency matrix by 1
        for (size_t i = 0; i < this->numvertices; i++)
        {
            for (size_t j = 0; j < this->numvertices; j++)
            {
                if (this->adjMatrix[i][j] != 0)
                {
                    this->adjMatrix[i][j]++;
                }
            }
        }
        return *this;
    }

    // Post-increment operator Increments all non-zero values in the adjacency matrix by 1 and returns the original graph before the increment
    Graph Graph::operator++(int)
    {
        Graph temp = *this;
        ++(*this);
        return temp;
    }
    Graph &Graph::operator--()
    {
        // decrement all the values in the adjacency matrix by 1
        for (size_t i = 0; i < this->numvertices; i++)
        {
            for (size_t j = 0; j < this->numvertices; j++)
            {
                if (this->adjMatrix[i][j] != 0)
                {
                    this->adjMatrix[i][j]--;
                }
            }
        }
        return *this;
    }

    // Post-increment operator Decrements all non-zero values in the adjacency matrix by 1 and returns the original graph before the decrement.
    Graph Graph::operator--(int)
    {
        Graph temp = *this;
        --(*this);
        return temp;
    }
    Graph Graph::operator*=(int num)
    {
        for (size_t i = 0; i < this->numvertices; i++)
        {
            for (size_t j = 0; j < this->numvertices; j++)
            {
                this->adjMatrix[i][j] *= num;
            }
        }
        return *this;
    }
    // Performs matrix multiplication
    Graph Graph::operator*(const Graph &other) const
    {
        if (this->numvertices != other.numvertices)
        {
            throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
        }
        Graph result;
        result.numvertices = this->numvertices;

        // Initialize the result matrix with zeros
        for (size_t i = 0; i < this->numvertices; ++i)
        {
            std::vector<int> row(this->numvertices, 0);
            result.adjMatrix.push_back(row);
        }

        // Perform matrix multiplication
        for (size_t i = 0; i < this->numvertices; ++i)
        {
            for (size_t j = 0; j < this->numvertices; ++j)
            {
                for (size_t k = 0; k < this->numvertices; ++k)
                {
                    result.adjMatrix[i][j] += this->adjMatrix[i][k] * other.adjMatrix[k][j];
                }
            }
        }

        // Ensure diagonal is zero
        for (size_t i = 0; i < this->numvertices; ++i)
        {
            result.adjMatrix[i][i] = 0;
        }

        return result;
    }

    Graph Graph::operator*=(const Graph &other)
    {

        *this = *this * other;
        return *this;
    }
    // Multiplies all elements in the adjacency matrix of a graph by a scalar value (num). This is a friend function for convenience.
    Graph Graph::operator*(int num)
    {
        Graph result; // create the new graph
        result.numvertices = this->numvertices;

        for (size_t i = 0; i < this->numvertices; ++i)
        {
            vector<int> row;
            for (size_t j = 0; j < this->numvertices; ++j)
            {
                int w = num * this->adjMatrix[i][j];

                row.push_back(w);
            }
            result.adjMatrix.push_back(row);
        }

        return result; // Return the new graph
    }

    Graph operator*(int num, const Graph &graph)
    {

        Graph result; // create new graph
        result.numvertices = graph.numvertices;
        for (size_t i = 0; i < graph.numvertices; ++i)
        {
            vector<int> row;
            for (size_t j = 0; j < graph.numvertices; ++j)
            {
                int w = num * graph.adjMatrix[i][j];

                row.push_back(w);
            }
            result.adjMatrix.push_back(row);
        }

        return result; // Return the graph
    }
    // Divides all elements in the adjacency matrix of the graph by a scalar value (num).
    Graph Graph::operator/(int num)
    {
        if (num == 0) // not allowing dviding by ziro
        {
            throw std::invalid_argument("Division by zero is not allowed.");
        }

        Graph result;
        result.numvertices = this->numvertices;

        for (size_t i = 0; i < this->numvertices; ++i)
        {
            vector<int> row;
            for (size_t j = 0; j < this->numvertices; ++j)
            {

                int w = num / this->adjMatrix[i][j];
                row.push_back(w);
            }
            result.adjMatrix.push_back(row);
        }
        return result;
    }
    // Divides all elements in the adjacency matrix of the graph by a scalar value (num) in place.
    Graph Graph::operator/=(int num)
    {

        if (num == 0) //// not allowing dviding by ziro
        {
            throw std::invalid_argument("Division by zero is not allowed");
        }
        for (size_t i = 0; i < this->numvertices; i++)
        {
            for (size_t j = 0; j < this->numvertices; j++)
            {
                this->adjMatrix[i][j] /= num;
            }
        }
        return *this;
    }

    std::ostream &operator<<(std::ostream &os, const Graph &graph)
    {
        // Iterate through each row in the adjacency matrix of the graph
        for (const auto &row : graph.adjMatrix)
        {
            os << "["; // Start a new row with an opening bracket

            // Iterate through each element in the row
            for (size_t i = 0; i < row.size(); ++i)
            {
                os << row[i]; // Output the current element

                // Add a comma and space if there are more elements in the row
                if (i < row.size() - 1)
                {
                    os << ", ";
                }
            }

            os << "]\n"; // End the row with a closing bracket and newline character
        }

        return os; // Return the output stream
    }

}
