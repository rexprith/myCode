TARGET_MODULE = sample_driver
obj-m := sample_driver.o

KERNELDIR ?= /lib/modules/4.15.0-213-generic/build/

all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
load:
	insmod ./$(TARGET_MODULE).ko
unload:
	rmmod ./$(TARGET_MODULE).ko
clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean

