
#include <iostream>
#include <string>

using namespace std;


int main (int argc, char* argv[]) {
    bool seed = false;

    try {
        string xxx;
        int seed;
        bool loadGame;
        bool loadBoard;
        for(int i = 1; i < argc; ++i){
            string curr = argv.at(i);
            if(input == "-seed") {
                seed = true;
                ++i;
                try {
                    int seed = stoi(argv.at(i));
                } catch (const invalid_argument& e) {
                    throw new InvalidCommandLineException("not an integer");
                }
            game.newGame(seed);

            } else if (input == "-load") {
                loadGame = true;
            } else if (input == "-board") {
                loadBoard = true;
            } else {
                xxx = input;
            }
        }

        if(seed) {
        } else if(loadGame) {
            game.loadGame(xxx);
        } else if(loadBoard) {
            game.loadBoard(xxx);
        }

    } catch (InvalidCommandLineException& e) {
        cerr << e.what() << endl;
    }
}
