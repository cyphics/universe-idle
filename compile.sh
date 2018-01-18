#!/bin/bash

project_root="/home/cyphix/programmation/c++/universe-idle"

build_dir="$project_root"/build
test_dir="$project_root"/test
test_build_dir="$test_dir"/build
bin_name="program"

if [ "$1" == "clean" ]
then
    rm -rf "$build_dir"/*
    rm -rf "$project_root"/bin/*
    rm -rf "$test_build_dir"/*
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


build_project(){
    cd "$build_dir"
    cmake ..
    make
}

build_test(){
    mkdir -p $test_build_dir
    cd "$test_build_dir"
    cmake ..
    make
}

build_project

if [ "$1" == run ]
then
    cd "$project_root"
    ./bin/"$bin_name" $2
fi

if [ "$1" == "test" ]
then
    echo ""
    build_test
    #./bin/*
fi
