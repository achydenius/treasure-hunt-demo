main.tap: main.c data.h map.h
	zcc +zx -vn -clib=sdcc_iy -startup=0 main.c -o main -create-app
clean:
	rm -f main.tap
