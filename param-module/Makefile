# Virtual gsensor driver
#
# USAGE:
# To install driver -
#        make inst (The Makefile will check the module and compile and link it automatically. It will also remove
#                   the loaded USB-Serial driver)
#
# To uninstall driver -
#        make uninst
#
# To uninstall all drivers (including base driver) -
#        make uninst_all
#
# To remove module (*.o) files -
#        make clean
#


# Set the KDIR to your kernel root directory, and the kernel has been compiled successfully.

#export KERNEL_PATH:=/mnt/nfsroot/gangfeng.xu/work/kk-amlogic/out/target/product/k200/obj/KERNEL_OBJ
#export KERNEL_PATH:=/home/hejian/qvod-3066/jb.rk3066/kernel.rk3066


#all:
#	make -C idong200_alg
#	make -C vmic
#	make -C vTs
#	make -C vgsensor_drv
#	mkdir -p modules
#	cp ./idong200_alg/idong200alg.ko ./modules/
#	cp ./vmic/idongvmic.ko ./modules/
#	cp ./vTs/vTs.ko ./modules/
#	cp ./vgsensor_drv/mma8452.ko ./modules/

#clean:
#	rm -rf modules
#	make -C idong200_alg clean
#	make -C vmic clean
#	make -C vTs clean
#	make -C vgsensor_drv clean

KERNEL_PATH:=/mnt/nfsroot/gangfeng.xu/work/kk-amlogic/out/target/product/k200/obj/KERNEL_OBJ
PWD:=$(shell pwd)
obj-m+=param_module.o
all:
	make -C $(KERNEL_PATH) M=$(PWD) modules  
clean:
	rm -rf *.o* *.ko* *.mod.c* .cmd *.symvers .tmp_version.*.cmd
