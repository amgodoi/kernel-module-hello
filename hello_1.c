#include <linux/init.h>        /* Needed for the macros */
#include <linux/module.h>      /* Needed by all modules */
#include <linux/kernel.h>      /* Needed for KERN_INFO */
#include <linux/printk.h>

#define DRIVER_LICENSE "GPL"
#define DRIVER_AUTHOR  "Alexandre Maia Godoi"
#define DRIVER_DESC    "Hello world kernel module"

static char *p1;
static char *p2;
static char *p3;

module_param(p1, charp, 0);
module_param(p2, charp, 0);
module_param(p3, charp, 0);

//int init_module(void) // do not need to be registered
static int hello_init(void) 
{ 
    printk(KERN_INFO "Hello, world\n"); 
    printk(KERN_INFO "'%s', '%s', '%s'\n", p1, p2, p3);
    return 0; 
}

//void cleanup_module(void) // do not need to be registered
static void hello_exit(void) 
{ 
    printk(KERN_INFO "Goodbye cruel world\n"); 
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE(DRIVER_LICENSE);
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_SUPPORTED_DEVICE("testdevice");

