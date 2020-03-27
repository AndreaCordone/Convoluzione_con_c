#!/bin/bash 
g++ -I$mkBoostInc -c main.cpp
g++ -L$mkBoostLib -lboost_iostreams -lboost_system -lboost_filesystem main.o
./a.out                
