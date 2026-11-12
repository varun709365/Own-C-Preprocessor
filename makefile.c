
exe: prepro.o header_suparator.o macro.o comment.o prepro_fun.o
        cc prepro.o header_suparator.o macro.o comment.o prepro_fun.o -o exe

prepro.o:prepro.c
        cc -c prepro.c
header_spuarator.o:header_suparator.c
        cc -c header_suparator.c
macro.o:macro.c
        cc -c macro.c
comment.o:comment.c
        cc -c comment.c
prepro_fun.o:prepro_fun.c
        cc -c prepro_fun.c
clear:
        @echo "cleaning up..."
        @rm -r *.o

