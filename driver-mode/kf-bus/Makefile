obj-m += kf-bus.o
KERNELDIR        = /mnt/nfsroot/gangfeng.xu/work/kk-amlogic/out/target/product/k200/obj/KERNEL_OBJ
PWD := $(shell pwd)

all:
	          make -C $(KERNELDIR) M=$(PWD) modules
clean:
	          rm -rf *.o* *.ko* *.mod.c* .cmd *.symvers .tmp_version.*.cmd

