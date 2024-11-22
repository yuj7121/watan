#ifndef FILESETUP_H
#define FILESETUP_H

#include "boardSetup.h"
#include "exceptions.h"
#include <iostream>
#include <fstream>

class FileSetup: public BoardSetup {
  protected:
    string fileName;
    void prepare();
    void setupResources() override;
    void populate();
  public:
    FileSetup(string fileName);
    void setup(shared_ptr<Board> b);
};

#endif