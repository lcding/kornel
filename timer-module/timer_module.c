#include <linux/module.h>
#include <linux/kernel.h>

static int num= 10;
module_param(num, int, 0664);
MODULE_PARM_DESC(num, "hello word num parameter");
static int __init hello_init(void){
    printk("hello moudle init\n");
    printk("num = %d \n",num);
    return 0;
}

static void __exit hello_exit(void){
    printk("exit hello module!\n");

}
module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("KF");
MODULE_DESCRIPTION("Timer Module");
