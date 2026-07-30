MCU = atmega328p
CC = avr-gcc
OBJCOPY = avr-objcopy

CFLAGS = -mmcu=$(MCU) -Os -DF_CPU=16000000UL

TARGET = main
BUILD_DIR = build

ELF = $(BUILD_DIR)/$(TARGET).elf
HEX = $(BUILD_DIR)/$(TARGET).hex

all: $(HEX)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(ELF): main.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) main.c -o $(ELF)

$(HEX): $(ELF)
	$(OBJCOPY) -O ihex -R .eeprom $(ELF) $(HEX)

clean:
	rm -rf $(BUILD_DIR)