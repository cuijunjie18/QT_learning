#!/bin/zsh
qmake
bear -- make
mv *.h include/
mv UI_use2 bin/UI_use2
mv *.o build/