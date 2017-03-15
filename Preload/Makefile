.PHONY: all clean

all: wrapper

wrapper: 
	gcc -fPIC -shared pwndir.c -o /tmp/pwndir.so

clean:
	rm -f /tmp/pwndir.so
