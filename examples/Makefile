CC = avr-gcc

AVR_LIB_DIR = /usr/lib/avr
PORT := ''

INCLUDES = \
	-I../ \
	-I$(AVR_LIB_DIR)/include/ \


CFLAGS = \
	-Os -Wall \
	-DARDUINO=106 \
	-mmcu=atmega328p \
	-DF_CPU=16000000UL \
	-MMD \
	-DUSB_VID=null \
	-DUSB_PID=null \
	-fdata-sections \
	-ffunction-sections \
	-fno-exceptions \
	-Wno-pointer-arith \
	$(INCLUDES) \
	-flto \
	-DNDEBUG \


UPLOAD = \
	avrdude -v \
	-p atmega328p \
	-c arduino \
	-P $(PORT) \
	-b 115200 \
	-D -U 


TARGETS = blink.hex blink.hex.upload

all: $(TARGETS)

blink.hex: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -c -Os -g -Wall blink.c -o blink.o
	$(CC) $(CFLAGS) -o blink blink.o
	avr-objcopy -j .text -j .data -O ihex blink blink.hex

blink.hex.upload:
ifeq ($(PORT), '')
	$(error PORT is not specified. Example: make PORT=/dev/ttyACM0 blink.hex.upload)
endif
	$(UPLOAD) flash:w:blink.hex:i

clean:
	rm -fr *.o *.d blink blink.hex

.PHONY: all
