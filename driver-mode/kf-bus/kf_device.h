/*************************************************************************
    > File Name: kf_device.h
    > Author: koffuxu
    > Mail: koffuxu@gmail.com 
    > Created Time: Tue 09 Dec 2014 03:00:26 PM CST
 ************************************************************************/

#ifndef _KF_DEVICE_H
#define _KF_DEVICE_H
#include<linux/device.h>
#include<linux/mod_devicetable.h>


struct kf_device{
    const char *name;
    int id;
    struct device kfdev;
    struct resource *kfresource;
};
struct kf_device_driver{
    char * name;
    int (*probe) (struct kf_device*);
    int (*remove) (struct kf_device*);
    int (*shutdown) (struct kf_device*);
    int (*suspend) (struct kf_device*);
    int (*resume) (struct kf_device*);
    struct device_driver driver;

};
#endif/*_KF_DEVICE_H*/
