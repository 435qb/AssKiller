#!/usr/bin/bash

function build_asskiller(){
    current_dir="${PWD}"

    echo "Entering folder ${build_dir}"
    cd $build_dir

    echo "Start building asskiller ..."
    cmake .. -DCMAKE_BUILD_TYPE=release
    #If errors then exit
    if [ "$?" != "0" ]; then
            exit -1
    fi
    make
    #If errors then exit
    if [ "$?" != "0" ]; then
            exit -1
    fi
    echo "Reloading ..."
    systemctl reload AssKiller

    cd $current_dir
}

git pull
build_dir = './build'

if [ ! -d $build_dir ]; then 
    mkdir build_dir
fi
build_asskiller