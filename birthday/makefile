obj-m += birthday.o
all:
	make -C /lib/modules/4.15.0-34-generic/build/ M=$(PWD) modules
clean:
	rm -f *.ko *.o *.mod.o *.mod.c .symvers

