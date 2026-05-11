#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init mydriver_init(void)
{
    printk(KERN_ALERT "Driver Loaded Successfully\n");
    return 0;
}

static void __exit mydriver_exit(void)
{
    printk(KERN_ALERT "Driver Removed Successfully\n");
}

module_init(mydriver_init);
module_exit(mydriver_exit);

MODULE_LICENSE("GPL");
