/**
 * main.cpp
 * 
*/

#include <iostream>

#include "headers/config.h"

int main(int argc, char *argv[]) {
    
    stmj::Config *cfg = new stmj::Config(argv[1]);
    
    return 0;
}