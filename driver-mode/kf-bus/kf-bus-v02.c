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
#include <linux/kdev_t.h>
//#include "./kf_device.h"

#define KFMAJOR 96
//-----\\class moduel
static struct class kf_class={
    .name = "kf-class",
    .owner = THIS_MODULE,
}; 
static int kf_class_register(void){
    int ret = -1;
    ret = class_register(&kf_class);
    //kf_class = class_create(THIS_MODULE,"kfclass");
    if(ret < 0){
        printk("kf-class register error!\n");
        //return kf_class_unregister(&kf_class);
    }
    printk("kf-class register ok!\n");
    return 0;
}

static void kf_class_unregister(void){
   class_unregister(&kf_class); 
   //class_destroy(&kf_class);
}
//------\\bus moduel
static int kf_bus_type_match(struct device *dev, struct device_driver *drv)
{
    printk("enter %s\n",__func__);
   return 1;
}
/*static int kf_bus_type_probe(struct device *dev){
    int ret = -1;
    printk("enter %s\n",__func__);
   if (dev->driver->probe)
       ret = dev->driver->probe(dev);
   return ret;
}*/
static void kf_bus_release(struct device *dev){
    //need to do
    printk("%s\n",__func__);
}

static struct bus_type kf_bus_type = {

   .name = "kf-bus-type",
   .match = kf_bus_type_match,
 //  .probe = kf_bus_type_probe, 
};
static struct device kf_bus = {
    .init_name = "kf-bus",
    .release = kf_bus_release,
};

static int kf_bus_register(void){
    int bus_ret = -1;
    //kf_bus.class = &kf_class;
    bus_ret = device_register(&kf_bus);
    
    if(bus_ret < 0){
        printk("bus device reister error!\n");
    }
    bus_ret = bus_register(&kf_bus_type);
    if(bus_ret < 0){
        printk("bus type reister error!\n");
    }
    printk("kf_bus & kf_bus_type register ok\n");
    return bus_ret;
}
static void kf_bus_unregister(void){
    bus_unregister(&kf_bus_type);
    device_unregister(&kf_bus);
}

//-----\\device module
static void kf_device_release(struct device *dev){
    printk("%s\n",__func__);


}
static struct device kf_device={
    .init_name = "kf-device0",
    .devt = MKDEV(KFMAJOR,1),
    .release = kf_device_release,
};
static int kf_device_register(void){

    int ret = -1;
    //Do not point this class
    //kf_device.class = &kf_class;
    kf_device.bus = &kf_bus_type;
    kf_device.parent = &kf_bus;
    ret = device_register(&kf_device);
    if(ret < 0){
        printk("kf device reister error!\n");
    }
    printk("kf device reister ok!\n");
    return ret;
}
static void kf_device_unregister(void){
    device_unregister(&kf_device);
}


//------\\driver module
/*
struct kf_device_driver{
    char *name;
    struct device_driver driver;
};*/
static int kf_device_driver_probe(struct device *dev){
    printk("enter drive probe\n");
    return 0;

}

static struct device_driver kf_device_driver={
    .name = "kf-device-driver",
    .probe = kf_device_driver_probe, 

};
static int kf_device_dirver_register(void){
    int ret = -1;
    kf_device_driver.bus = &kf_bus_type;
    ret = driver_register(&kf_device_driver);
    printk("kf_device_driver reister ok!\n");
    return ret;
}

static void kf_device_dirver_unregister(void){
    driver_unregister(&kf_device_driver);
}

//-----\\init func
static int __init kf_bus_init(void)
{
    int com_ret;    
    printk(">>>kf_bus_init successed!!\n");
    com_ret =kf_class_register(); 
    com_ret = kf_bus_register();
    com_ret = kf_device_register();
    com_ret = kf_device_dirver_register();
    if(com_ret < 0){
        printk(">>>kf_bus_register error\n");
        //kf_bus_unregister();
    }
    return 0;
}

static void __exit kf_bus_exit(void)
{

    printk(">>>kf_bus_exit successed!!\n");
    kf_device_dirver_unregister();
    kf_device_unregister();
    kf_bus_unregister();
    kf_class_unregister();
}
module_init(kf_bus_init);
module_exit(kf_bus_exit);

MODULE_AUTHOR("Koffuxu");
MODULE_LICENSE("GPL");
