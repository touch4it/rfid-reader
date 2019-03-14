default: build

build: read_from_event.c
	clang read_from_event.c -o read_from_event

clean:
	-rm -f read_from_event
