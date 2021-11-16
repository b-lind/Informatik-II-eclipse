#!/bin/bash

make

gcc -shared bin/ComplexNumbers.o -o libcomplex.so

cp libcomplex.so /usr/lib/libcomplex.so
cp include/ComplexNumbers.h /usr/include/ComplexNumbers.h