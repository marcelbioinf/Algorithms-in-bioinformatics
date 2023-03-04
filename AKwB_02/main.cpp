#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#include "AKwB_02.h"

using namespace std;

int main()
{

    int v;
    v=read_graph_size();
    cout<<v<<endl;
    Graph g(v);
    g.create_graph();
    g.sort_list();
    g.print_graph();
    g.is_1_graph();
    g.is_adjoint();
    g.is_linear();
    g.transform_and_save();
    cout<<endl;
    return 0;


}
