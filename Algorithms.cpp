//oriya7914@gamil.com
//213525512
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <climits>
#include <unordered_set>
#include <queue>

using namespace std;

namespace ariel
{
    
    bool Algorithms::isContainsCycle( Graph &graph)
    {
        // Check if the graph has no vertices, in which case it cannot have a cycle.
        if (graph.getNumOfVertices() == 0)
        {
            return false;
        }

        // Initialize colors for vertices, parents, and CirclePath to track the cycle.
        std::vector<Color> colors(graph.getNumOfVertices(), WHITE);
        std::vector<int> parents(graph.getNumOfVertices(), -1);
        std::vector<int> CirclePath;

        // Iterate through each vertex to check for cycles using DFS.
        for (size_t i = 0; i < graph.getNumOfVertices(); i++)
        {
            if (colors[i] == WHITE)
            {
                // If a WHITE vertex is found, start DFS from that vertex.
                if (isContainsCycleUtil(graph, i, &colors, &parents, &CirclePath))
                {
                    // If a cycle is detected during DFS, return true.
                    return true;
                }
            }
        }
        // If no cycle is found after checking all vertices, return false.
        return false;
    }

    bool Algorithms::isContainsCycleUtil(Graph &graph, size_t currentVertec, std::vector<Color> *colors, std::vector<int> *parents, std::vector<int> *CirclePath)
    {
        // Mark the current vertex as being visited.
        (*colors)[currentVertec] = GRAY;
        // Add the current vertex to the CirclePath.
        CirclePath->push_back(currentVertec);

        // Explore adjacent vertices of the current vertex.
        for (size_t i = 0; i < graph.getNumOfVertices(); i++)
        {
            if (graph.getMatrix()[currentVertec][i] != 0)
            {
                // If there is an edge from currentVertec to vertex i.
                if ((*colors)[i] == WHITE)
                {
                    // If vertex i is WHITE (not visited), mark its parent and recursively check for cycles.
                    (*parents)[i] = static_cast<int>(currentVertec);
                    if (isContainsCycleUtil(graph, i, colors, parents, CirclePath))
                    {
                        return true; // If a cycle is found in recursion, return true.
                    }
                }
                else if ((*colors)[i] == GRAY)
                {
                    if (!graph.isDirected() && (*parents)[currentVertec] == static_cast<int>(i))
                    {
                        continue; // Skip back edges in undirected graphs to avoid false cycle detection.
                    }

                    // Detect a cycle and print the cycle path.
                    bool cycleFound = false;
                    size_t v = 0;
                    for (v = 0; v < (*CirclePath).size(); ++v)
                    {
                        if ((*CirclePath)[v] == static_cast<int>(i))
                        {
                            cycleFound = true;
                            break;
                        }
                    }
                    if (cycleFound)
                    {
                        std::cout << "The cycle is: ";
                        for (size_t j = v; j < (*CirclePath).size(); ++j)
                        {
                            std::cout << (*CirclePath)[j];
                            if (j != (*CirclePath).size() - 1)
                            {
                                std::cout << "->";
                            }
                        }
                        std::cout << "->" << i << std::endl;
                    }
                    return true; // Return true as a cycle is detected.
                }
            }
        }

        // Mark the current vertex as explored.
        (*colors)[currentVertec] = BLACK;
        // Remove the current vertex from the CirclePath as DFS backtracks.
        CirclePath->pop_back();

        return false; // No cycle is detected in this branch.
    }

    std::string Algorithms::isBipartite(Graph &graph)
    {
        size_t numVertices = graph.getNumOfVertices();
        std::vector<int> color(numVertices, -1); // Initialize colors to -1 (unassigned)
        std::vector<size_t> groupA, groupB;      // Separate vectors for nodes in groups A and B

        // if (!graph.isDirected()) {
        //  For undirected graphs, use the existing algorithm
        //  Start BFS traversal from each uncolored vertex
        for (size_t start = 0; start < numVertices; ++start)
        {
            if (color[start] == -1)
            {
                std::queue<size_t> q;
                q.push(start);
                color[start] = 0; // Color the starting vertex with 0 (group A)

                while (!q.empty())
                {
                    size_t current = q.front();
                    q.pop();

                    if (color[current] == 0)
                    {
                        groupA.push_back(current); // Add current node to group A
                    }
                    else
                    {
                        groupB.push_back(current); // Add current node to group B
                    }

                    auto neighbors = graph.getNeighbors(current);
                    for (size_t i = 0; i < neighbors.size(); ++i)
                    {
                        size_t neighbor = neighbors[i];
                        if (color[neighbor] == -1)
                        {                                         // Neighbor is uncolored
                            color[neighbor] = 1 - color[current]; // Assign opposite color of current vertex
                            q.push(neighbor);
                        }
                        else if (color[neighbor] == color[current])
                        { // Neighbor has same color as current vertex
                            return "0";//The graph is not bipartite
                        }
                    }
                }
            }
        }

        // Construct the result string for graphs
        std::string result = "The graph is bipartite: A={";
        for (size_t i = 0; i < groupA.size(); ++i)
        {
            result += std::to_string(groupA[i]);
            if (i < groupA.size() - 1)
            {
                result += ", ";
            }
        }
        result += "}, B={";
        for (size_t i = 0; i < groupB.size(); ++i)
        {
            result += std::to_string(groupB[i]);
            if (i < groupB.size() - 1)
            {
                result += ", ";
            }
        }
        result += "}";

        return result;
    }
    

    std::string Algorithms::negativeCycle(Graph &graph)
    {
 
        vector<vector<int>> matrix = graph.getMatrix();
        int numVertices = graph.getNumOfVertices();
        vector<int> distance(size_t(numVertices), INT_MAX);
        vector<int> parent(size_t(numVertices), -1);
        int start = 0;
        distance[size_t(start)] = 0;

        // Relax edges repeatedly to find shortest paths
        for (int i = 0; i < numVertices - 1; ++i)
        {
            
            for (int u = 0; u < numVertices; ++u)
            {
                for (int v = 0; v < numVertices; ++v)
                {
                    if (matrix[size_t(u)][size_t(v)] != 0 && distance[size_t(u)] != INT_MAX && distance[size_t(u)] + matrix[size_t(u)][size_t(v)] < distance[size_t(v)])
                    {
                        distance[size_t(v)] = distance[size_t(u)] + matrix[size_t(u)][size_t(v)];
                        parent[size_t(v)] = u; // Update parent node for backtracking
                    }
                }
            }
        }

        // Check for negative weight cycle
        vector<int> negativeCycleNodes;
        int cycleNode = -1;
        for (int u = 0; u < numVertices; ++u)
        {
            for (int v = 0; v < numVertices; ++v)
            {
                if (matrix[size_t(u)][size_t(v)] != 0 && distance[size_t(u)] != INT_MAX && distance[size_t(u)] + matrix[size_t(u)][size_t(v)] < distance[size_t(v)])
                {
                    
                    // Found negative weight cycle
                    cycleNode = v;
                    break;
                }
            }
            if (cycleNode != -1)
                break;
        }

        if (cycleNode != -1)
        {
            // Include cycleNode in the negative cycle nodes
            negativeCycleNodes.push_back(cycleNode);

            int currentNode = parent[size_t(cycleNode)];
            while (currentNode != cycleNode)
            {
                negativeCycleNodes.push_back(currentNode);
                currentNode = parent[size_t(currentNode)];
            }

            

            std::string negativeCycleStr = "Negative cycle found: ";

            for (int i = negativeCycleNodes.size() - 1; i >= 0; --i)
            {
                negativeCycleStr += std::to_string(negativeCycleNodes[size_t(i)]) + "->";
            }
            negativeCycleStr += std::to_string(negativeCycleNodes[size_t(negativeCycleNodes.size() - 1)]);

            return negativeCycleStr;
        }

        return "No negative cycle";
        
    }

    void Algorithms::DFS(Graph &graph, size_t node, std::vector<bool> &visited)
    {
        visited[node] = true;
        std::vector<std::vector<int>> retrievedMatrix = graph.getMatrix();
        for (size_t neighbor = 0; neighbor < graph.getNumOfVertices(); ++neighbor)
        {
            if (!visited[neighbor] && graph.checkEdge(node, neighbor))
            {
                DFS(graph, neighbor, visited);
            }
        }
    }

    int Algorithms::isConnected(Graph &graph)
    {

        if (graph.isDirected() == false)
        {
            std::vector<bool> visited(size_t(graph.getNumOfVertices()), false); // Mark all vertices as not visited initially

            // Perform Depth-First Search (DFS) from the first vertex
            DFS(graph, 0, visited);

            // // Check if all vertices were visited during DFS traversal
            for (bool isVisited : visited)
            {
                if (!isVisited)
                {
                    // If any vertex is not visited, the graph is not connected
                    return 0; // Return false
                }
            }

            // If all vertices were visited, the graph is connected
            return 1; // Return true
        }
        else
        {
            for (size_t i = 0; i < size_t(graph.getNumOfVertices()); ++i)
            {
                std::vector<bool> visitedCopy(size_t(graph.getNumOfVertices()), false); // Reset visited for each vertex
                DFS(graph, i, visitedCopy);
                for (bool isVisited : visitedCopy)
                {
                    if (!isVisited)
                    {
                        // If any vertex is not visited, the graph is not strongly connected
                        return 0; // Return false
                    }
                }
            }
            return 1;
        }
    }

    std::string Algorithms::shortestPath(Graph &graph, int start, int end)
    {
        // Check if the graph is valid and has the given start and end vertices
        if (start < 0 || start >= graph.getNumOfVertices() || end < 0 || end >= graph.getNumOfVertices())
        {
            return "Invalid start or end vertex";
        }

        // Initialize distance array to store shortest distances from start vertex
        std::vector<int> distance(size_t(graph.getNumOfVertices()), INT_MAX);
        std::vector<size_t> parent(size_t(graph.getNumOfVertices()), SIZE_MAX); // Parent array for backtracking
        distance[size_t(start)] = 0;                                            // Distance from start to itself is 0

        // Relax edges repeatedly to find shortest paths
        for (int i = 0; i < graph.getNumOfVertices() - 1; ++i)
        {
            for (int u = 0; u < graph.getNumOfVertices(); ++u)
            {
                for (int v = 0; v < graph.getNumOfVertices(); ++v)
                {
                    if (graph.checkEdge(size_t(u), size_t(v)) && distance[size_t(u)] != INT_MAX && distance[size_t(u)] + graph.getMatrix()[size_t(u)][size_t(v)] < distance[size_t(v)])
                    {
                        distance[size_t(v)] = distance[size_t(u)] + graph.getMatrix()[size_t(u)][size_t(v)];
                        parent[size_t(v)] = size_t(u); // Update parent for backtracking
                    }
                }
            }
        }

        // Check for negative weight cycles
        for (int u = 0; u < graph.getNumOfVertices(); ++u)
        {
            for (int v = 0; v < graph.getNumOfVertices(); ++v)
            {
                if (graph.checkEdge(size_t(u), size_t(v)) && distance[size_t(u)] != INT_MAX && distance[size_t(u)] + graph.getMatrix()[size_t(u)][size_t(v)] < distance[size_t(v)])
                {
                    return "-1";//Graph contains negative weight cycle
                }
            }
        }

        if (distance[size_t(end)] == INT_MAX)
        {
            return "-1";
        }
        
        // Construct the shortest path string
        std::string shortestPathStr = std::to_string(end); // Start building the path from the end vertex
        int currentVertex = end;
        size_t parentVertex = parent[size_t(currentVertex)];
        while (parentVertex != SIZE_MAX)
        {
            shortestPathStr = std::to_string(parentVertex) + "->" + shortestPathStr;
            currentVertex = parentVertex;
            parentVertex = parent[size_t(currentVertex)];
        }

        return shortestPathStr;
    }

}
