#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{

    // game loop
    while (1) {
        int action_count; // the number of spells and recipes in play
        cin >> action_count; cin.ignore();

        int action_id[action_count]; // the unique ID of this spell or recipe
        string action_type[action_count]; // in the first league: BREW; later: CAST, OPPONENT_CAST, LEARN, BREW
        int delta[action_count][4];
        int price[action_count]; // the price in rupees if this is a potion
        int tome_index; // in the first two leagues: always 0; later: the index in the tome if this is a tome spell, equal to the read-ahead tax; For brews, this is the value of the current urgency bonus
        int tax_count; // in the first two leagues: always 0; later: the amount of taxed tier-0 ingredients you gain from learning this spell; For brews, this is how many times you can still gain an urgency bonus
        bool castable; // in the first league: always 0; later: 1 if this is a castable player spell
        bool repeatable; // for the first two leagues: always 0; later: 1 if this is a repeatable player spell

        for (int i = 0; i < action_count; i++) {
            
            cin >> action_id[i] >> action_type[i] >> delta[i][0] >> delta[i][1] >> delta[i][2] >> delta[i][3] >> price[i] >> tome_index >> tax_count >> castable >> repeatable; cin.ignore();
            cerr << action_id[i] << " " << action_type[i] << " " << delta[i][0] << " " << delta[i][1] << " " << delta[i][2] << " " << delta[i][3] << " " << price[i] << endl;
        }

        int inv[4];
        int score; // amount of rupees
        
        for (int i = 0; i < 2; i++) {
            cin >> inv[0] >> inv[1] >> inv[2] >> inv[3] >> score; cin.ignore();
        }

        int mais_alto_preco = 0;
        int mais_alto_id = 0;

        for(int i = 0; i < action_count; i++){
            if(action_type[i] != "BREW") break;

            if( (delta[i][0]*-1)<=inv[0] && (delta[i][1]*-1)<=inv[1] && (delta[i][2]*-1)<=inv[2] && (delta[i][3]*-1)<=inv[3] && price[i] >= mais_alto_preco){
                mais_alto_preco = price[i];
                mais_alto_id = action_id[i];
            }
        }


        // in the first league: BREW <id> | WAIT; later: BREW <id> | CAST <id> [<times>] | LEARN <id> | REST | WAIT 
        if(mais_alto_preco > 0){
            cout << "BREW " << mais_alto_id << endl;
            mais_alto_preco = 0;
        }

        else{

            // fazer alguma coisa pra escolher a proxima poção (qtd de ingredientes diferentes, preco, tier dos ing, sla), e depois pegar os ingredientes em ordem,
            // já que o ing 3 precisa do 2, 2 precisa do 1, 1 do 0 e 0 é gratis

            // descobrir a quantidade de ações pra cada ingrediente; exemplo: 2 ing0 é só 1 ação, mas o ing3 precisa da ação 1, dps 2, dps 3 e dps 4
            // então, uma poção do ing 3 precisa valer umas 4x mais do q essa do ing 0 pra ela valer a pena
            // da pra fazer um float com o preco da pocao dividido pela quantidade de acoes, e procurar a pocao q mais da dinheiro por acao



            cout << "REST" << endl;

        }
    }
}
