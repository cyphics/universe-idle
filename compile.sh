#!/bin/bash

project_root="$(pwd)"

build_dir="$project_root"/build
test_dir="$project_root"/test
bin_dir="$project_root"/bin

bin_name="program"
test_name="test_app"

if [ "$1" == "clean" ]
then
    rm -rf "$project_root"/bin
    rm -rf "$project_root"/lib
    rm -rf "$project_root"/debug
    rm -rf "$project_root"/build
    rm -rf "$project_root"/test/bin
    rm -rf "$project_root"/test/build
    exit 0
fi



if [ "$1" == "debug" ]
then
    mkdir -p debug
    cd debug
    cmake -DCMAKE_BUILD_TYPE=Debug ..
    make
    exit 0
fi

# Configure
mkdir -p "$build_dir"
cd "$build_dir"
cmake ..

if [ "$1" == "test" ]
then
    make check
    "$project_root"/build/test/bin/*
    exit 0
fi

make
if [ "$1" == run ]
then
    "$bin_dir"/"$bin_name" $2
fi

if [ "$1" == gui ]
then
    "$bin_dir"/"$bin_name" gui
fi
