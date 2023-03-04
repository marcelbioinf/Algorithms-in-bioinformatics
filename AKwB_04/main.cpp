#include "AKwB_04.hpp"

int main()
{
    vector<int> multi_set;
    vector<int> cpy;
    vector<int> maps;
    vector<int> used;
    int is;

    get_multi_set(multi_set); //pobranie danych z pliku
    copy(multi_set.begin(), multi_set.end(), back_inserter(cpy)); //kopia multizbioru aby wydobyc 1 element mapy
    sort(cpy.begin(), cpy.end()); //sortowanie
    cout<<"Multizbior: ";
    for(unsigned int i=0;i<multi_set.size();i++)//**** wyswietlanie
    {
        cout<<multi_set[i]<<"  ";
    }
    cout<<endl;
    unsigned int multi_set_size=multi_set.size(); //rozmiar multizbioru
    unsigned int map_size=restrictive_sites(multi_set_size)+1; //rozmiar mapy, czyli ilosc miejsc ciecia + 1
    if(map_size-1==0) //koniec programu jesli blad w instancji
    {
        return 0;
    }
    cout<<"Rozmiar mapy: "<<map_size<<endl;//******wyswietlanie

    int first=cpy[cpy.size()-1]-cpy[cpy.size()-2];
    for(unsigned int i=0;i<cpy.size();i++)
    {
        if(cpy[i]==first) break;
        else if(i==cpy.size()-1)
        {
            cout<<"Blad w instancji"<<endl;
            return 0;
        }
    }
    int max_elem=cpy[cpy.size()-1];
    //cout<<"Maksymalny element mapy: "<<max_elem<<endl;
    cout<<"Pierwszy element mapy: "<<first<<endl; ////****wyswietlanie
    used.push_back(first);
    used.push_back(max_elem);
    used.push_back(max_elem-first);

    is=0;
    clock_t start = clock();
    search_map(first, maps, multi_set, used, &map_size, &max_elem, 1, &is);
    if (is==0)
    {
        cout<<"Brak rozwiazania w danej instancji :( "<<endl;
    }
    cout<<"Czas wykonywania: "<<(double)(clock() - start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
