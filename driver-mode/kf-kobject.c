/*************************************************************************
    > File Name: kf-kobject.c
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
#include <linux/slab.h>

static struct kobject *kfkobj;

static int __init kf_kobject_init(void)
{

   printk(">>>kf_kobject_init !!\n");
   kfkobj = kobject_create_and_add("kf-kobject",NULL);
   if(!kfkobj){
       kobject_del(kfkobj);
       printk("kobject add fail!\n");
   }
   return 0;

}


static void __exit kf_kobject_exit(void)
{

    printk(">>>kf_kobject_exit !!\n");
    kobject_del(kfkobj);
}
module_init(kf_kobject_init);
module_exit(kf_kobject_exit);

MODULE_AUTHOR("Koffuxu");
MODULE_LICENSE("GPL");
