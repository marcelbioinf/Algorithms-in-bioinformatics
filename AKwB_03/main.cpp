#include "AKwB_03.hpp"

using namespace std;


int main()
{
    vector<string> sequences;
    vector<vector<int>> qualities;
    vector<vector<int>> positions;
    int treshold;
    int substring;

    Graph g1;
    int program;
    int control;
    cout<<"DOSTEPNE PROGRAMY:"<<endl;
    cout<<"1-Wczytaj dane z pliku"<<endl;
    cout<<"2-Usun nukleotydy ponizej danego progu"<<endl;
    cout<<"3-Utworz graf z wierzcholkow bedacych podicagami o danej dlugosci"<<endl;
    cout<<"4-Wyszukaj kliki"<<endl;

    while(1){
        cout<<endl<<"Wybierz program: ";
        cin>>program;
        if(program<1 || program>4){
           cout<<"Blad nie ma takiego programu!"<<endl;
           continue;
        }

        switch(program){

        case 1:
            {
              get_data(&sequences, &qualities);
              cout<<"Pomyslnie pobrano dane z plikow"<<endl;

               for(int i=0;i<qualities.size();i++){          //  WYSWIETLANIE WEKTORA WEKTOROW
                   cout<<"Numer sekwencji: "<<i<<endl;
                   for (auto it = qualities[i].begin();
                   it != qualities[i].end(); it++) {

                        cout << ' ' << *it << ' ';
                   }
                   cout<<endl;
                   cout<<"Rozmiar sekwencji: "<<qualities[i].size()<<endl;
                }
               cout<<endl<<endl;
               //cout<<sequences.size()<<endl;
               for(int i=0;i<sequences.size();i++){
                    cout<<"Numer sekwencji: "<< i <<endl<<sequences[i]<<endl;
                    cout<<"Rozmiar sekwencji: "<<sequences[i].length()<<endl;
               }
               break;
            }
        case 2:
            {
                cout<<"Podaj prog: ";
                cin>>treshold;
                delete_nucleotides(&sequences, &qualities, &positions, treshold);
                cout<<endl<<"Pomyslnie usunieto nukleotydy, sekwencje po usunieciu: "<<endl;
                for(int i=0;i<sequences.size();i++){
                    cout<<"Numer sekwencji: "<< i <<endl<<sequences[i]<<endl;
                    cout<<"Rozmiar sekwencji: "<<sequences[i].length()<<endl;
                }
                break;
            }
        case 3:
            {
                cout<<"Podaj dlugosc podciagu: ";
                cin>>substring;
                g1.create_graph(sequences, positions, substring);
                cout<<"Pomyslnie stworzono graf"<<endl;
                break;
            }
        case 4:
            {
                cout<<"Wyszukano nastepujaca klike o roamiarze domyslnym 5:"<<endl;
                g1.search_for_clique(5);
                while(control!=999){
                cout<<endl<<"Jesli nie znaleziono wyniku, wprowadz mniejszy rozmiar kliki, wpisz 999 zaby zamknac program: "<<endl;
                cin>>control;
                if(control<5)  g1.search_for_clique(control);
                else if(control==999) return 0;
                }

            }
       }
    }
   /*get_data(&sequences, &qualities);

   cout<<qualities.size()<<endl;
   for(int i=0;i<qualities.size();i++){          //  WYSWIETLANIE WEKTORA WEKTOROW
        cout<<i<<endl;
        for (auto it = qualities[i].begin();
             it != qualities[i].end(); it++) {

            cout << ' ' << *it << ' ';
        }
        cout<<endl;
        cout<<qualities[i].size()<<endl;
    }

      cout<<sequences.size()<<endl;
      for(int i=0;i<sequences.size();i++){
        cout<<sequences[i]<<endl;
        cout<<sequences[i].length()<<endl;
      }

      treshold=1;
      delete_nucleotides(&sequences, &qualities, &positions, treshold);
      cout<<endl;
          cout<<endl<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
    for(int i=0;i<positions.size();i++){          //  WYSWIETLANIE WEKTORA WEKTOROW
        cout<<i<<endl;
        for (auto it = positions[i].begin();
             it != positions[i].end(); it++) {

            cout << ' ' << *it << ' ';
        }
        cout<<endl;
        cout<<positions[i].size()<<endl;
    }
    cout<<endl<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
// TO WYSWIETLA NOWE POZYCJE -SPR

            for(int i=0;i<sequences.size();i++){
        cout<<sequences[i]<<endl;
        cout<<sequences[i].length()<<endl;
      }

    substring=5;


    //Graph g1;
    g1.create_graph(sequences, positions, substring);
    g1.search_for_cliques(0,1,3);
*/
return 0;
}
