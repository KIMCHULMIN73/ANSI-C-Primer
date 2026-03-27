# directions for this Makefile
#
# 1) to build : make build TARGET=target name
# 2) to run   : make run TARGET=target name
# 3) to clean : make clean TARGET=target name


default: build

build:
	gcc -o ./output/$(TARGET) $(TARGET).c usrlib.c

run:
	script -q -c "./output/$(TARGET)" /dev/null

clean:
	rm ./output/$(TARGET)

# end
