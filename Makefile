CC = clang
CFLAGS = -Wall
LDFLAGS = -framework Cocoa -framework AppKit -framework Foundation -lobjc
OBJ = main.o delegate.o util/args.o util/win.o util/str.o
TARGET = main

main: $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@

clean:
	rm -rf *.o utils/*.o main