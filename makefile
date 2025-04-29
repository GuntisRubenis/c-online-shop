CC = gcc
C_FLAGS = -Wall

shop: shop.o buyer.o items.o
	$(CC) $(C_FLAGS) -o shop shop.o buyer.o items.o

shop.o: shop.c buyer.h items.h
	$(CC) $(C_FLAGS) -c shop.c

buyer.o: buyer.c
	$(CC) $(C_FLAGS) -c buyer.c

items.o: items.c
	$(CC) $(C_FLAGS) -c items.c
