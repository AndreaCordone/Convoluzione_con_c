module load boost
g++ -I$mkBoostInc -c main_bossi.cpp
g++ -L$mkBoostLib -lboost_iostreams -lboost_system -lboost_filesystem main_bossi.o -o main_bossi
./main_bossi
