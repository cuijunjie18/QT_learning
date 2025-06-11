#!/bin/zsh

qmake 
bear -- make
mv *.h include/
mv *.o build/
mv *.cpp src/
mv main bin/main