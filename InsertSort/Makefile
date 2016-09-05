CPP=clang++
CFLAGS=
LDFLAGS=-lncurses
HEADERS=

Insert_Sort: InsertSort.cpp
	${CPP} ${CFLAGS} ${LDFLAGS} $^ -o $@

.PHONY:clean
clean:
	-@ rm Insert_Sort
