/*************************************************************************
    > File Name: kf-dirver.c
    > Author: koffuxu
    > Mail: koffuxu@gmail.com 
    > Created Time: Tue 09 Dec 2014 02:42:44 PM CST
 ************************************************************************/

#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/stat.h>
#include <linux/slab.h>
#include <linux/kobject.h>

#include "./kf-bus/kf_device.h"
/*
struct kf_device_driver{
    char *name;
    struct device_driver driver;
};*/
static struct kf_device_driver kf_inst_driver={
    .name = "kf-device-driver",

};


static int __init kf_driver_init(void){
    printk(">>>kf_dirver_init");
    kf_inst_driver.driver.name = kf_inst_driver.name; 
    kf_inst_driver.driver.bus = &kf_bus_type;
    return driver_register(&kf_ins_driver.driver);
}
module_init(kf_driver_init);
//module_exit(kf_driver_exit);

MODULE_AUTHOR("Koffuxu");
MODULE_LICENSE("GPL");
