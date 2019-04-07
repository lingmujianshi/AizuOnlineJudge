#!/bin/sh
if [ ! $1 ]; then
    echo "引数１；レッスン番号"
    exit;
fi

if [ ! -e ALDS1/$1 ]; then
    mkdir ALDS1/$1
fi
cp -v main.cpp ALDS1/$1/