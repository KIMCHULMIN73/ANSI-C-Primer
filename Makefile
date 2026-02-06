default: build

build:
	gcc -o ./output/$(TARGET) $(TARGET).c usrlib.c

run:
	script -q -c "./output/$(TARGET)" /dev/null

clean:
	rm ./output/$(TARGET)
