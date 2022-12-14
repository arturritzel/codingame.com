#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int n; // numero de dias de torneios
    cin >> n; cin.ignore();
    int r; // numero de consecutivos ate terem q descansar
    cin >> r; cin.ignore();

    int prize[n]; // premios de cada dia
    for (int i = 0; i < n; i++) {
        cin >> prize[i]; cin.ignore();
    }


    /////// user code:

    int max_money = 0;
    int cur_money = 0;

    int cur_day = 0;

    // trabalhando com obrigatoriamente fluxos de 4 dias seguidos (nao é o ideal, provavelmente nao vai funcionar)
    for(int i = 0; i <= r; i++){ // para cada possibilidade de pausa (pausar no dia 1, dia 2, dia 3, etc e seguir padrao)
        for(int j = 0; j < n; j++){ // para cada dia
            if((j-i) % (r+1) == 0) cerr << prize[j] << " não contou" << endl;
            else{cur_money+= prize[j]; cerr << prize[j] << " contou" << endl;}
        }

        cerr << "total dessa volta: " << cur_money << endl << endl;
        if(cur_money > max_money) max_money = cur_money;
        cur_money = 0;
    }

    cerr << "max: ";
    cout << max_money;

}
