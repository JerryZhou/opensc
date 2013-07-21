#!/bin/sh

#make -f Makefile.opensc
#make -f Makefile.test

function build_proj_cmd()
{
    echo "------------------begin build----------------------------------------------------"
    if [ "$2" == "c" ]; then
	echo "clean project"
	make clean -f $1
    else
	make -f $1
    fi
    echo "------------------end build----------------------------------------------------"
    echo "\n"
}

#$(build_proj_cmd "Makefile.opensc" "c")
#$(build_proj_cmd "Makefile.test" "c")

if [ "$1" == "all" ]; then
    echo "build all proj"
    build_proj_cmd "Makefile.opensc" $2
    build_proj_cmd "Makefile.test" $2
else
    mkfile="Makefile.$1"
    if [ -f $mkfile ]; then
	build_proj_cmd $mkfile $2
    fi
fi

