all: exec

main.o : main.c
	gcc -o main.o -c main.c

produit.o : produit.c
	gcc -o produit.o -c produit.c

gestion.o : gestion.c 
	gcc -o gestion.o -c gestion.c

client.o : client.c
	gcc -o client.o -c client.c

achat.o : achat.c 
	gcc -o achat.o -c achat.c

exec : main.o produit.o gestion.o client.o achat.o
	gcc -o exec main.o produit.o gestion.o client.o achat.o
