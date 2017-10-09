
#main: main.o stack.o maze.o
#	gcc main.o stack.o maze.o -o main
#
#main.o: main.c main.h stack.h maze.h
#	gcc -c main.c
#
#stack.o: stack.c stack.h main.h
#	gcc -c stack.c
#
#maze.o: maze.c maze.h main.h
#	gcc -c maze.c
#
#clean:
#	@echo "cleanning projects"
#	-rm main *.o
#	@echo "clean complete"

main: main.o stack.o maze.o
	gcc $^ -o $@











#$@，表示规则中的目标。

#$<，表示规则中的第一个条件。

#$?，表示规则中所有比目标新的条件，组成一个列表，以空格分隔。

#$^，表示规则中的所有条件，组成一个列表，以空格分隔。
