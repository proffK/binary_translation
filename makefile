CC=gcc
CCFLAGS=-Wall -c -g
AR=ar
ARFLAGS=rcs
PROG_NAME=avrdump

$(PROG_NAME): main.o libintel_hex.a
	$(CC) $< -o $@ -L. -lintel_hex
main.o: main.c
	$(CC) $(CCFLAGS) $< 
libintel_hex.a: intel_hex.o
	$(AR) $(ARFLAGS) $@ $<
intel_hex.o: intel_hex.c
	$(CC) $(CCFLAGS) $<



