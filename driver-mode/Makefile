
KERNEL_PATH:=/mnt/nfsroot/gangfeng.xu/work/kk-amlogic/out/target/product/k200/obj/KERNEL_OBJ
PWD:=$(shell pwd)
obj-m+=kf-kobject.o
obj-m+=kf-driver.o
all:
	make -C $(KERNEL_PATH) M=$(PWD) modules
clean:
	rm -rf *.o* *.ko* *.mod.c* .cmd *.symvers .tmp_version.*.cmd
