#include "fileSetup.h"

FileSetup::FileSetup(string fileName) : fileName{fileName} {}

void FileSetup::setup() {
    ifstream file;
    try{
        file.open(fileName);
        if(file.fail()) {
            throw new FileNotFoundException(fileName);
        }
    } catch (FileNotFoundException& e) {
        std::cerr << e.what() << endl;
        return;
    }

    try{
        string str;

        //skiping the sutden tinfo
        for(int i = 0; i < 5; ++i) {
            getline(file, str);
        }

        int input;

        //reading in the board line
        for(int i = 0; i < NUM_TILES; ++i){
            file >> input;
            if(input < 0 || input > 5) {
                throw new FileFormatException(fileName);
            }
            resourceTypes[i] = input;
            file >> input;
            if(input < 0 || input > 12) {
                throw new FileFormatException(fileName);
            }
            resourceValues[i] = input;
        }

        //read in geese
    } catch (FileFormatException& e) {
        std::cerr << e.what() << endl;
    }
}

