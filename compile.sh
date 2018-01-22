#!/bin/bash

project_root="$(pwd)"

build_dir="$project_root"/build
test_dir="$project_root"/test
bin_dir="$project_root"/bin

bin_name="program"
test_name="test_app"

if [ "$1" == "clean" ]
then
    echo "$project_root"
    rm -rf "$project_root"/bin
    rm -rf "$project_root"/lib
    rm -rf "$project_root"/debug
    rm -rf "$project_root"/build
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
    mkdir -p "$build_dir"
    cd "$build_dir"
    cmake ..
    make
}

build_project

if [ "$1" == run ]
then
    "$bin_dir"/"$bin_name" $2
fi

if [ "$1" == "test" ]
then
    "$bin_dir/$test_name"
fi
