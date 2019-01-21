# Build the memory eaten bin file

object = memeat.o

memeat.bin: $(object)

	$(CC) -o memeat.bin $(object)

memeat.o: memeat.c

	$(CC) -c memeat.c

.PHONY clean:
	rm -rf memeat.bin memeat.o
