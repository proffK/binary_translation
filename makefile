CC=gcc
CCFLAGS=-Wall -c -g
AR=ar
ARFLAGS=rcs
PROG_NAME=kvm2avr

$(PROG_NAME): main.o FSM.o command_convert.o libintel_hex.a
	$(CC) $^ -o $@ -L. -lintel_hex
main.o: main.c
	$(CC) $(CCFLAGS) $< 
libintel_hex.a: intel_hex.o
	$(AR) $(ARFLAGS) $@ $<
intel_hex.o: intel_hex.c
	$(CC) $(CCFLAGS) $<
FSM.o: FSM.c 
	$(CC) $(CCFLAGS) $<
command_convert.o: command_convert.c
	$(CC) $(CCFLAGS) $<
clean:
	rm *.o 


