# /bin/sh

make -f Makefile.opensc
make -f Makefile.test

#function build_proj_cmd(){
#    proj=$1
#    cmd=$2
#
#    if [ "$cmd" -eq "c" ]; then
#	make clean -f $proj
#    else
#	make -f $proj
#    fi
#}

#$(build_proj_cmd "Makefile.opensc" "c")
#$(build_proj_cmd "Makefile.test" "c")

#allproj=all
#proj=$1
#cmd=$2

#echo $proj
#echo $cmd

#if [ $proj -eq "$allproj" ]; then
#    $(build_proj_cmd "Makefile.opensc" $cmd)
#    $(build_proj_cmd "Makefile.test" $cmd)
#else
#    mkfile="Makefile.$proj"
#    if [ -f $mkfile ]; then
#	$(build_proj_cmd $mkfile $cmd)
#    fi
#fi

