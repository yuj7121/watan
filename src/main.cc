
#include <iostream>
#include <string>
#include "gameplay.h"
#include "textDisplay.h"

using namespace std;


int main (int argc, char* argv[]) {
    shared_ptr<Gameplay> game;

    //get the command line and run appropriate functions from gameplay
    //  to set up the game
    try {
        if (argc < 2) {
            throw InvalidCommandLineException("Usage: ./waton <-seed xxx> | <-load file> | <-board file>");
        }
        for(int i = 1; i < argc; ++i){
            string curr{argv[i]};
            if(curr == "-seed") {
                ++i;
                try {
                    int seed = atoi(argv[i]);
                    game = make_shared<Gameplay>(seed); 
                } catch (const invalid_argument& e) {
                    throw InvalidCommandLineException("not an integer");
                }
            } else if (curr == "-load") {
                ++i;
                game = make_shared<Gameplay>(Gameplay::SetupType::LoadFromFile, argv[i]); 
            } else if (curr == "-board") {
                ++i;
                game = make_shared<Gameplay>(Gameplay::SetupType::LoadFromBoard, argv[i]);
            } else {
                throw InvalidCommandLineException("invalid commandline input");
            }
        }
    } catch (InvalidCommandLineException& e) {
        cerr << e.what() << endl;
        exit(-1);
    }

    // Establish the observer pattern here 
    shared_ptr<TextDisplay> td = make_shared<TextDisplay>(game); 
    game->attach(td); // attach the observer to the subject
    
    // running game instances
    while (true) { 
        game->play(); // keep playing the game until it terminates -> then ask for playing again -> 1 game instance
        cout << "Would you like to play again?" << endl;
        cout << ">"; 
        string response; 
        cin >> response; 
        if (response == "yes") {
            return false; 
        } else if (response == "no") {
            return true; 
        } else { 
            cout << "Invalid command." << endl; 
        }
    }

}
