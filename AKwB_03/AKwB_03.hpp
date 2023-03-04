#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include<algorithm>

using namespace std;

void get_data(vector<string> *s, vector<vector<int>> *q);

void delete_nucleotides(vector<string> *s, vector<vector<int>> *q, vector<vector<int>> *p, int tresh);

class Graph
{
    int g_size;
    int **matrix;
    //vector<vector<string>> vertices_helper; //POMAGA W DODAWANIU KRAWEDZI
    vector<string> vertices;  //WEKTORY PLASKIE OZNACZAJACE WIERZCHOLKI, NUMER SEKWENCJI, I POZYCJE
    vector<int> seqs;
    vector<int> pos;

    vector<int> degree;
    vector<vector<int>> storage;
    vector<int> clique;

    public:
    void create_graph(vector<string> &s, vector<vector<int>> &p, int sub);
    void search_for_clique(int clique_size);
};
