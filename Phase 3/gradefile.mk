a.exe:main.o grade_card.c
	gcc main.c grade_card.c
main.o:main.c grade_card.h
	gcc -c main.c
grade_card.c:grade_card.c grade_card.h
	gcc -c grade_card.c