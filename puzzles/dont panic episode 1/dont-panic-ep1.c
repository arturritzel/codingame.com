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
    int nb_floors; // number of floors
    int width; // width of the area
    int nb_rounds; // maximum number of rounds
    int exit_floor; // floor on which the exit is found
    int exit_pos; // position of the exit on its floor
    int nb_total_clones; // number of generated clones
    int nb_additional_elevators; // ignore (always zero)
    int nb_elevators; // number of elevators
    cin >> nb_floors >> width >> nb_rounds >> exit_floor >> exit_pos >> nb_total_clones >> nb_additional_elevators >> nb_elevators; cin.ignore();
    
    /// codigo do usuario
    int pos_elev[nb_elevators]; // posição do elevador em x andar
    /// fim do codigo do usuario
    
    for (int i = 0; i < nb_elevators; i++) {
        int elevator_floor; // floor on which this elevator is found
        int elevator_pos; // position of the elevator on its floor
        cin >> elevator_floor >> elevator_pos; cin.ignore();

        // codigo do usuario
        pos_elev[elevator_floor] = elevator_pos;
        // fim do codigo do usuario
    }

    // game loop
    while (1) {
        int clone_floor; // floor of the leading clone
        int clone_pos; // position of the leading clone on its floor
        string direction; // direction of the leading clone: LEFT or RIGHT
        cin >> clone_floor >> clone_pos >> direction; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        // codigo do usuario

        if(clone_floor < 0){
            cout << "WAIT" << endl;
        }

        else{
            if(clone_floor < exit_floor){
                if(clone_pos < pos_elev[clone_floor]){
                    if(direction.compare("LEFT") == 0) cout << "BLOCK" << endl;
                    else cout << "WAIT" << endl;
                }

                if(clone_pos > pos_elev[clone_floor]){
                    if(direction.compare("RIGHT") == 0) cout << "BLOCK" << endl;
                    else cout << "WAIT" << endl;
                }

                if(clone_pos == pos_elev[clone_floor]){
                    cout << "WAIT" << endl;
                }
            }

            else{
                if(clone_pos < exit_pos){
                    if(direction.compare("LEFT") == 0) cout << "BLOCK" << endl;
                    else cout << "WAIT" << endl;
                }

                if(clone_pos > exit_pos){
                    if(direction.compare("RIGHT") == 0) cout << "BLOCK" << endl;
                    else cout << "WAIT" << endl;
                }

                if(clone_pos == exit_pos){
                    cout << "WAIT" << endl;
                }

            }
        }
    }
}
