CC = gcc
IN = main.c sistema_ventas.c
OUT = pia_mate
CFLAGS = -ggdb

default:
	$(CC) $(CFLAGS) $(IN) -o $(OUT)
