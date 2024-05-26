//oriya7914@gamil.com
//213525512

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <sstream>

using namespace std;

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
   
   CHECK(g3.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]");

   vector<vector<int>> graph3 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    ariel::Graph g7;
    g7.loadGraph(graph3);
    ariel::Graph g8 = g3 + g7;
    CHECK(g8.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]");

    vector<vector<int>> graph10 = {
        {1, 1, 1},
        {0, 0, 0},
        {0, 0, 0}};
    ariel::Graph g9;
    g9.loadGraph(graph10);
    g9+=g3;
    
    CHECK(g9.printGraph() == "[1, 3, 2]\n[2, 0, 3]\n[1, 3, 0]");
    
    vector<vector<int>> graph11 = {
        {1, 1, 1},
        {0, 0, 0},
        {0, 0, 0}};
    ariel::Graph g12;
    g12.loadGraph(graph11);
    ariel::Graph g13 = +g12;
    CHECK(g13.printGraph() == "[1, 1, 1]\n[0, 0, 0]\n[0, 0, 0]");

     vector<vector<int>> graph14 = {
         {-1, -1, -1},
        {-1, 0, -2},
        {-1, -2, 0}};
    ariel::Graph g15;
    g15.loadGraph(graph14);
   
   
    ariel::Graph g16 = g13-g15;
     CHECK(g16.printGraph() == "[2, 2, 2]\n[1, 0, 2]\n[1, 2, 0]");

     g16-=g15;
    CHECK(g16.printGraph() == "[3, 3, 3]\n[2, 0, 4]\n[2, 4, 0]");

    
     ariel::Graph g20 = -g2;
     CHECK(g20.printGraph() == "[0, -1, -1]\n[-1, 0, -2]\n[-1, -2, 0]");
     

}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}};
    CHECK(g4.printGraph() == "[0, 0, 2]\n[1, 0, 1]\n[1, 0, 0]");

    // ariel::Graph g5;
    // std::vector<std::vector<int>> graph5 = {
    //     {0, 1, 0},
    //     {1, 0, 1},
    //     {0, 1, 0}
    // };
    // g5.loadGraph(graph5);

    // ariel::Graph g6;
    // std::vector<std::vector<int>> graph6 = {
    //     {0, 1, 1},
    //     {1, 0, 2},
    //     {1, 2, 0}
    // };
    // g6.loadGraph(graph6);

    // CHECK(g5 < g6);
    
    // ariel::Graph g7;
    // std::vector<std::vector<int>> graph7 = {
    //     {0, 1, 0},
    //     {1, 0, 0},
    //     {0, 0, 0}
    // };
    // g7.loadGraph(graph7);

    // CHECK(g7 < g5);
}
TEST_CASE("Test operator< for Graph") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(graph2);

    CHECK(g1 < g2);
    
    ariel::Graph g3;
    std::vector<std::vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}
    };
    g3.loadGraph(graph3);

    CHECK(g3 < g1);
}
TEST_CASE("Test operator> for Graph") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(graph2);

    CHECK(g2 > g1);
    
    ariel::Graph g3;
    //contain but has less edjes
    std::vector<std::vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}
    };
    g3.loadGraph(graph3);

    CHECK(g2 > g3);
    // same thing but hasmore vertex
    ariel::Graph g4;
    std::vector<std::vector<int>> graph4 = {
        {0, 1, 1,0},
        {1, 0, 2,0},
        {1, 2, 0,0},
        {0, 0, 0, 0}
    };
    g4.loadGraph(graph4);
     CHECK(g4 > g2);


}
TEST_CASE("Test operator>= for Graph") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(graph2);

    CHECK(g2 >= g1);
    CHECK(g1 >= g1);
}
TEST_CASE("Test operator<= for Graph") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(graph2);

    CHECK(g1 <= g2);
    CHECK(g1 <= g1);
}
TEST_CASE("Test operator== and != for Graph") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g2.loadGraph(graph2);

    CHECK(g1 == g2);
    
    ariel::Graph g3;
    std::vector<std::vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 2},
        {0, 2, 0}
    };
    g3.loadGraph(graph3);

    CHECK((g1 != g3));
}
TEST_CASE("Test pre-increment operator++ for Graph") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    ++g1;

    std::string expectedGraph = "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]";
    CHECK(g1.printGraph() == expectedGraph);
}

TEST_CASE("Test post-increment operator++(int) for Graph") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    ariel::Graph g2 = g1++;
    std::string expectedGraph1 = "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]";
    std::string expectedGraph2 = "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]";

    CHECK(g2.printGraph() == expectedGraph1);
    CHECK(g1.printGraph() == expectedGraph2);
}
TEST_CASE("Test pre-decrement operator-- for Graph") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}
    };
    g1.loadGraph(graph);

    --g1;

    std::string expectedGraph = "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]";
    CHECK(g1.printGraph() == expectedGraph);
}

TEST_CASE("Test post-decrement operator--(int) for Graph") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}
    };
    g1.loadGraph(graph);

    ariel::Graph g2 = g1--;
    std::string expectedGraph1 = "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]";
    std::string expectedGraph2 = "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]";

    CHECK(g2.printGraph() == expectedGraph1);
    CHECK(g1.printGraph() == expectedGraph2);
}
TEST_CASE("Test multiplication operator* with integer for Graph") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    ariel::Graph g2 = g1 * 2;
    std::string expectedGraph = "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]";

    CHECK(g2.printGraph() == expectedGraph);
}

TEST_CASE("Test multiplication operator*= with integer for Graph") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    g1 *= 2;
    std::string expectedGraph = "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]";

    CHECK(g1.printGraph() == expectedGraph);
}
TEST_CASE("Test multiplication operator* with another Graph") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 * g2;
    std::string expectedGraph = "[0, 0, 2]\n[1, 0, 1]\n[1, 0, 0]";

    CHECK(g3.printGraph() == expectedGraph);
}

TEST_CASE("Test multiplication operator*= with another Graph") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(graph2);

    g1 *= g2;
    std::string expectedGraph = "[0, 0, 2]\n[1, 0, 1]\n[1, 0, 0]";

    CHECK(g1.printGraph() == expectedGraph);
}
TEST_CASE("Test division operator/ with integer for Graph") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 4, 0},
        {4, 0, 4},
        {0, 4, 0}
    };
    g1.loadGraph(graph);

    // Update the test case to expect an exception
    CHECK_THROWS_AS(g1 / 0, std::invalid_argument);
}


TEST_CASE("Test division operator/= with integer for Graph") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 4, 0},
        {4, 0, 4},
        {0, 4, 0}
    };
    g1.loadGraph(graph);

    g1 /= 2;
    std::string expectedGraph = "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]";

    CHECK(g1.printGraph() == expectedGraph);
}
TEST_CASE("Test multiplication operator* with integer and Graph") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    ariel::Graph g2 = 2 * g1;
    std::string expectedGraph = "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]";

    CHECK(g2.printGraph() == expectedGraph);
}
TEST_CASE("Test stream insertion operator<< for Graph") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    std::ostringstream oss;
    oss << g1;
    std::string expectedOutput = "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]\n";

    CHECK(oss.str() == expectedOutput);
}













TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    // g2.loadGraph(weightedGraph);
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    // CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}