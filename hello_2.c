#include <linux/init.h>     /* Needed for the macros */
#include <linux/module.h>   /* Needed by all modules */
#include <linux/kernel.h>   /* Needed for KERN_INFO */

#define DRIVER_LICENSE "GPL"

static int __init hello_2_init(void)
{
    printk(KERN_INFO "Hello, world 2\n");
    return 0;
}

static void __exit hello_2_exit(void)
{
    printk(KERN_INFO "Goodbye, world 2\n");
}

module_init(hello_2_init);
module_exit(hello_2_exit);

MODULE_LICENSE(DRIVER_LICENSE);

