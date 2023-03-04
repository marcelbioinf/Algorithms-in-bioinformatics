#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;


class Graph
{

    int g_size; //number of vertices in graph
    int g_size_transformed;
    vector<int> *vectors_array; //vectors_array is a pointer to an array of vectors
    vector<int> builder;//helps in building a graph
    vector<int> *precursors;
    vector<int> *transformation_array;
    vector<int> v1, v2, v3, v4;
    vector<int> *transformed_graph;

public:
    Graph(int v);//constructor
    ~Graph();
    void add_arc(int x,int y);//adds an arc to the graph
    void create_graph();//creats graph from the input file
    void print_graph();//prints graph in the same form as input file
    void sort_list(); //sorts vector in increasing order
    bool is_1_graph();//checks if graph is a 1-graph
    bool is_adjoint();//checks if graph is adjoint
   // int duplicates();
    void check_precursors();//checks precursors of each vertic
    bool is_linear();//checks if graph is linear
    void transform_and_save();//transform graph to its original representation
};

int read_graph_size();


