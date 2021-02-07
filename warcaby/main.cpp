#include <iostream>
#include <_ctype.h>
#include <cmath>
using namespace std;
int litery_na_liczby(char);
void wypisz(string [8][8]);
bool warunki(string [8][8],int ,int ,int ,int ,int);
int main() {
    // stoworzę szblon
    string tab[8][8];
    for(int i = 0;i < 8;i++)
    {
        for(int j = 0;j < 8;j++)
        {
            if((j+i) % 2 == 0){
                if(i < 2)
                    tab[i][j] = "●";
                else if(i > 5)
                    tab[i][j] = "◯";
                else
                    tab[i][j] = " ";
            }
            else
                tab[i][j] = "╳";
        }
    }
    wypisz(tab);
    
    int pionki_1 = 8, pionki_2  = 8,teraz = 0;
    int x1,yy1,x2,yy2;
    char y1,y2;
    cout << "\nPadaj nr pola na którym znajduje się twój pionek a nastepnie nr pola na ktorym chcesz aby sie znalazł.";
    while(pionki_1 != 0 && pionki_2 != 0)
    {
        cout << endl;
        cout << "●: " << pionki_1 << " ◯: " << pionki_2 << endl;
        cout << "Gra teraz " << ((teraz == 0)?"●":"◯") << endl;
        cin >> y1 >> x1 >> y2 >> x2;
        x1--;
        x2--;
        yy1 = litery_na_liczby(y1);
        yy2 = litery_na_liczby(y2);
        if(yy1 == 10 || yy2 == 10)
            cout << "Błąd.";
        else{
            if(warunki(tab, teraz, x1, yy1, x2, yy2) == 0)
            {
                
                if(yy2 == 7 || yy2 == 0)
                    continue;
                else if(tab[x2][yy2] == " " && abs(x1 -x2) == 1){
                tab[x2][yy2] = tab[x1][yy1];
                tab[x1][yy1] = " ";
                teraz = (teraz == 1?0:1);
                }
                else if(abs(x1-x2) == 2 && abs(yy1 - yy2) == 2)
                {
                    if(x1 - x2 > 0 && yy1 -yy2 < 0)
                    {
                        if(tab[x2][yy2] == " ")
                        {
                            if(tab[x1][yy1] == "●" && tab[x1 - 1][yy1 + 1] == "◯")
                            {
                                tab[x1][yy1] = " ";
                                tab[x1 - 1][yy1 + 1] = " ";
                                tab[x2][yy2] = "●";
                                pionki_2--;
                                cout << "aaa\n";
                            }
                            else if(tab[x1][yy1] != "●" && tab[x1 - 1][yy1 + 1] != "◯")
                            {
                                tab[x1][yy1] = " ";
                                tab[x1 - 1][yy1 + 1] = " ";
                                tab[x2][yy2] = "◯";
                                pionki_1--;
                                cout << "bbb\n";
                            }
                            else
                                continue;
                            cout << "ccc\n";
                        }
                    }
                }
                system("clear");
                wypisz(tab);
            }
        }
    }
    
    cout << endl;
    return 0;
}
int litery_na_liczby(char pom){
    pom = toupper(pom);
    switch(pom)
    {
        case 'A':
            return 0;
        case 'B':
            return 1;
        case 'C':
            return 2;
        case 'D':
            return 3;
        case 'E':
            return 4;
        case 'F':
            return 5;
        case 'G':
            return  6;
        case 'H':
            return  7;
    }
    return 10;
}

void wypisz(string tab[8][8])
{
    cout << "\tA\tB\tC\tD\tE\tF\tG\tH";
    for(int i = 0;i < 8;i++)
    {
        cout << "\n" << i + 1 << "\t";
        for(int j = 0;j < 8;j++)
        {
            cout << tab[i][j] << "\t";
        }
    }
}
bool warunki(string tab[8][8],int teraz,int x1,int yy1,int x2,int yy2)
{
    if(tab[x1][yy1] == "╳" || tab[x2][yy2] == "╳")
        return 1;
    if(tab[x1][yy1] == tab[x2][yy2])
        return 1;
    if(tab[x1][yy1] == "●" && teraz == 1)
        return 1;
    if(tab[x1][yy1] != "●" && teraz != 1)
        return 1;
    /*if(abs(yy1 - yy2) != 1 || abs(x1 - x2) != 1){
        
            return 1;
    }*/
//    pomyslec jeszcze nad tym
    return 0;
}

