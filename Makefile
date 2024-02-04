CLOCK=16000000
DEVICE=attiny88
PROGRAMMER=micronucleus

CC = avr-gcc

AVRDUDE = avrdude -c $(PROGRAMMER) -p $(DEVICE)

CC_FLAGS = -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE) -c -I ./usbdrv -I .
LD_FLAGS = -Os -mmcu=$(DEVICE) -Wall

USBDRV_SOURCES += usbdrv/usbdrv.c usbdrv/usbdrvasm.S
USBDRV_OBJECTS += usbdrv/usbdrv.o usbdrv/usbdrvasm.o



# SOURCES += usbdrv/oddebug.c
# OBJECTS += usbdrv/oddebug.o

%.o: %.c
	$(CC) $(CC_FLAGS) $< -o $@

%.o: %.S
	$(CC) $(CC_FLAGS) -x assembler-with-cpp $< -o $@


%.hex: %.elf
	rm -f $@
	avr-objcopy -j .text -j .data -O ihex $< $@
	avr-size --format=avr --mcu=$(DEVICE) $<


master.elf: $(USBDRV_OBJECTS) master.o utils.o
	$(CC) $^ -o $@ $(LD_FLAGS)

slave.elf: slave.o utils.o
	$(CC) $^ -o $@ $(LD_FLAGS)


flash: master.hex
	micronucleus master.hex --run
	# micronucleus slave.hex --run

clean:
	rm -f *.o *.hex *.elf usbdrv/*.o
