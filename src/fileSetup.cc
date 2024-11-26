#include "fileSetup.h"

FileSetup::FileSetup(string fileName) : fileName{fileName} {}

void FileSetup::setupResources() {
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
        for(int i = 0; i < 5; ++i) {
            getline(file, str);
        }

        int input;

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
    } catch (FileFormatException& e) {
        std::cerr << e.what() << endl;
    }
}

