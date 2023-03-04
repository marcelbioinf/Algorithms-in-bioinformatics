#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <ctime>
#include <sstream>
#include <iterator>

using namespace std;


void get_multi_set(vector<int> &v);
unsigned long long silnia(int x);
int restrictive_sites(unsigned int s);
void search_map(int map_element, vector<int> maps, vector<int> multi_set, vector<int> &used, unsigned int *map_size, int *max_elem, unsigned int ind, int *is);

