CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2
TARGET = genllvm
SOURCES = lrparser.tab.c lex.yy.c ast.c genllvm.c main.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

lrparser.tab.c lrparser.tab.h: lrparser.y
	bison -d lrparser.y

lex.yy.c: lrlex.l lrparser.tab.h
	flex lrlex.l

clean:
	rm -f $(TARGET) $(TARGET).exe lrparser.tab.c lrparser.tab.h lex.yy.c

.PHONY: all clean
