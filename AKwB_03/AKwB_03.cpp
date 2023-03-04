#include "AKwB_03.hpp"

using namespace std;


void get_data(vector<string> *s, vector<vector<int>> *q)
{
    int line_nr=1;
    char first;
    string line;
    int value;
    vector<int> temp;

    fstream filequal;
    filequal.open("qual2.txt" , ios::in);
    if( filequal.good()==false) {              //sprawdz prawidlowosc pliku
       cout<<"Taki plik nie istnieje!"<<endl;
       return;
    }

    while(getline(filequal, line))   //pobiera wartosci wiarygodnosci
    {
        stringstream ss(line);
        first=line[0];
        if(first=='>' && line_nr==1)
        {
             line_nr++;  //pomija pierwsz¹ linie
             continue;
        }
        else if(first=='>' && line_nr!=1)
        {
            q->push_back(temp); //wpychanie wektora tymczasowego na wktor qualities
            temp.clear();
        }

        else
        {
            while(ss>>value)
            {
                temp.push_back(value); //wpychanie na wektor tymczasowy pojedynczych wartosci ze strumienia napisowego
            }
        }

       /* if(filequal.eof())
        {
            q->push_back(temp); //wpychanie wektora tymczasowego na wktor qualities
            temp.clear();       // dziala dla ostatniej linijki
        }*/

    }
    filequal.close();

    fstream filefasta;
    filefasta.open("fasta2.txt" , ios::in);
    if( filefasta.good()==false) {
        cout<<"Taki plik nie istnieje!"<<endl;
        return;
    }

    while(getline(filefasta, line))   //pobiera sekwencje
    {
        first=line[0];
        if(first=='>')
        {
            continue;                   //dla ulatwienia sekwencja jest w jednej linii, i tak jest krótka.
        }
        else s->push_back(line);
    }

    filefasta.close();
    return;
}


void delete_nucleotides(vector<string> *s, vector<vector<int>> *q, vector<vector<int>> *p, int tresh)
{

    vector<int> position_helper;
    for(int i=0;i<s->size();i++)
    {
        string seq=(*s)[i];
        string final_seq="";

        for(int j=0;j<(*q)[i].size();j++)
        {
            if((*q)[i][j]<tresh) continue;
            else
            {
              position_helper.push_back(j+1);
              final_seq+=seq[j];
            }
        }
        p->push_back(position_helper);
        position_helper.clear();
        (*s)[i]=final_seq;
    }
}


void Graph::create_graph(vector<string> &s, vector<vector<int>> &p, int sub)
{
    string vertic;
    for(int i=0;i<s.size();i++)
    {
        for(int j=0;j<s[i].size();j++)
        {
            if(j>(s[i].length()-sub))
            {
                break;
            }
            vertic=s[i].substr(j,sub);
            vertices.push_back(vertic);
            seqs.push_back(i);
        }
    }

    for(int i=0;i<p.size();i++)
    {
        for(int j=0;j<p[i].size()-(sub-1);j++)
        {
          pos.push_back(p[i][j]);
        }
    }


    for(int i=0;i<vertices.size();i++){
        cout<<i<<"::"<<vertices[i]<<endl;//wektory plaskie pomoga w odczytaniu wyniku koncowego
        cout<<seqs[i]<<endl;
        cout<<pos[i]<<endl;
    }

    g_size=vertices.size();
    //cout<<vertices.size()<<endl;

    matrix=new int*[g_size];
    for(int i=0;i<g_size;i++)
    {
        matrix[i]=new int[g_size];
        for(int j=0;j<g_size;j++)
        {
            matrix[i][j]=0;
        }
    }

    for(int i=0;i<vertices.size();i++)
    {
       degree.push_back(0);
    }

    for(int i=0;i<vertices.size();i++)
    {
        for(int j=0+i;j<vertices.size();j++)////!!!!!!!!!
        {
            if(vertices[i]==vertices[j] && seqs[i]!=seqs[j])
            {
                matrix[i][j]=1;
                matrix[j][i]=1;
                degree[i]++;
                degree[j]++;
            }
        }
    }


    for(int i=0;i<vertices.size();i++){
        for(int j=0;j<vertices.size();j++){
            if(matrix[i][j]==1 && matrix[j][i]==1) cout<<i<<"\t"<<j<<endl;
        }
    }

}

   void Graph::search_for_clique(int clique_size)
{
         vector<int>helper;
         for (int i=0;i<g_size;i++)
         {
             if(clique_size==5){
                if (degree[i] >= clique_size-1) {
                   helper.push_back(i);
                   storage.push_back(helper);
                   helper.clear();
                }
             }
             else
             {
                 if (degree[i] >= clique_size-1) {
                   helper.push_back(i);
                   storage.push_back(helper);
                   helper.clear();
                }
             }
         }

                 for(int i=0;i<storage.size();i++){          //  WYSWIETLANIE WEKTORA WEKTOROW
            cout<<i<<":: ";
            for (auto it = storage[i].begin();
            it != storage[i].end(); it++) {

                cout << ' ' << *it << ' ';
            }
            cout<<endl;
         }

         int check=0;
         for(int x=0;x<storage.size();x++)
         {
             for(int j=0;j<vertices.size();j++){
                 if(matrix[storage[x][0]][j]==1 && matrix[j][storage[x][0]]==1)
                 {
                      if(seqs[j]!=seqs[storage[x][check]])
                      {
                        storage[x].push_back(j);
                        check++;
                      }
                 }
             }
         check=0;
         }
                 for(int i=0;i<storage.size();i++){          //  WYSWIETLANIE WEKTORA WEKTOROW
            cout<<i<<":: ";
            for (auto it = storage[i].begin();
            it != storage[i].end(); it++) {

                cout << ' ' << *it << ' ';
            }
            cout<<endl;
         }

         for(int i=0;i<storage.size();i++)
         {
             sort(storage[i].begin(), storage[i].end());
         }

        for(int i=0;i<storage.size();i++){          //  WYSWIETLANIE WEKTORA WEKTOROW
            cout<<i<<":: ";
            for (auto it = storage[i].begin();
            it != storage[i].end(); it++) {

                cout << ' ' << *it << ' ';
            }
            cout<<endl;
         }

         int counter=1;
         for(int i=0;i<storage.size();i++)
         {
             if(storage[i].size()<clique_size)
                continue;
             for(int j=0;j<storage.size();j++)
             {

                 if(i==j)
                    continue;
                 if(storage[i]==storage[j])
                 {
                     counter+=1;
                 }
                 if(counter==clique_size)
                 {
                     break;
                 }

             }
             if(counter==clique_size)
             {
                for (int x=0;x<storage[i].size(); x++)
                {
                   cout << storage[i][x] <<"::"<<vertices[storage[i][x]]<< ", numer sekwencji: "<<seqs[storage[i][x]]<<", pozycja w sekwencji wejsciowej: "<<pos[storage[i][x]]<<endl;
                }
                break;
             }
             counter=1;

         }

         for(int i=0;i<storage.size();i++)
         {
             storage[i].clear();
         }

         return;
}

