CC = gcc
IN = main.c sistema_ventas.c
OUT = pia_mate
CFLAGS = -ggdb -Wall -Wextra

default:
	$(CC) $(CFLAGS) $(IN) -o $(OUT)
