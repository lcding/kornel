/*************************************************************************
    > File Name: kf-bus.c
    > Author: koffuxu
    > Mail: koffuxu@gmail.com 
    > Created Time: Mon 08 Dec 2014 04:16:41 PM CST
 ************************************************************************/

#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/stat.h>
#include <linux/slab.h>
#include <linux/kobject.h>

static int kf_bus_match(struct device *dev, struct device_driver *drv)
{

   return 0;
}

static struct bus_type kf_bus_type = {

   .name = "kf-bus",
   .match         = kf_bus_match,
};


static int __init kf_bus_init(void)
{

   printk(">>>kf_bus_init successed!!\n");
   return bus_register(&kf_bus_type);
}

static void __exit kf_bus_exit(void)
{

    printk(">>>kf_bus_exit successed!!\n");
    bus_unregister(&kf_bus_type);
}
module_init(kf_bus_init);
module_exit(kf_bus_exit);

MODULE_AUTHOR("Koffuxu");
MODULE_LICENSE("GPL");
