#!/bin/bash

project_root="/home/cyphix/programmation/c++/universe-idle"

build_dir="$project_root"/build
test_dir="$project_root"/test
test_build_dir="$test_dir"/build

if [ "$1" == "clean" ]
then
    rm -rf "$build_dir"/*
    rm -rf "$project_root"/bin/*
    rm -rf "$test_build_dir"/*
    exit 0
fi


build_project(){
    cd "$build_dir"
    cmake ..
    make
}

build_test(){
    cd "$test_build_dir"
    cmake ..
    make
}

build_project

if [ "$1" == run ]
then
    cd "$project_root"
    ./bin/*
fi

if [ "$1" == "test" ]
then
    build_test
    ./bin/*
fi
