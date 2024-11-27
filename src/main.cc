
#include <iostream>
#include <string>
#include "gameplay.h"

using namespace std;


int main (int argc, char* argv[]) {
    Gameplay game = Gameplay{};

    //get the command line and run appropriate functions from gameplay
    try {       
        for(int i = 1; i < argc; ++i){
            string curr{argv[i]};
            if(curr == "-seed") {
                ++i;
                try {
                    int seed = atoi(argv[i]);
                    game.newGame(seed);
                } catch (const invalid_argument& e) {
                    throw new InvalidCommandLineException("not an integer");
                }
            } else if (input == "-load") {
                ++i;
                game.loadGame(argv[i]);
            } else if (input == "-board") {
                ++i;
                game.loadBoard(argv[i]);
            } else {
                throw new InvalidCommandLineException("invalid commandline input");
            }
        }
    } catch (InvalidCommandLineException& e) {
        cerr << e.what() << endl;
    }


}
