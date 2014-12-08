GET_PLATFORM=k200

if [ $# -ne 0 ]; then
    if [ -n $1 ]; then
    TARGET_PLATFORM=$1
    fi  
fi
make -C '/mnt/nfsroot/gangfeng.xu/work/kk-amlogic/out/target/product/'$TARGET_PLATFORM'/obj/KERNEL_OBJ/' M='/home/gangfeng.xu/gator/driver-src/gator-driver' ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- modules

