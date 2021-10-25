all:	main.o	linked_list.o	library.o
	gcc	-o	main	main.o	linked_list.o	library.o
main.o:main.c	linked_list.h	library.h
	gcc	-c	main.c
linked_list.o:	linked_list.h	linked_list.c
	gcc	-c	linked_list.c
library.o:	library.h	library.c	linked_list.h
	gcc	-c	library.c
run:
	./main
