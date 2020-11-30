CC = clang
CFLAGS = -Wall
LDFLAGS = -framework Cocoa -framework AppKit -framework Foundation -lobjc
OBJ = main.o delegate.o cls/controller.o util/args.o util/drawing.o util/win.o util/str.o
TARGET = main

main: $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@

clean:
	find . -name '*.o' -exec rm -rf {} \;

objc:
	$(CC) main.m -o objc $(LDFLAGS)