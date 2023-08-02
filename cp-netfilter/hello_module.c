#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>  // Include the module parameter header

// Define a module parameter named "name" of type string
static char *name = "World";
module_param(name, charp, S_IRUGO);  // S_IRUGO allows reading the parameter

//These are header files to include necessary macros and functions for kernel module development
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Amitai Shmeeda");
MODULE_DESCRIPTION("A simple example Linux module.");
MODULE_PARM_DESC(name, "The name to display in the 'Hello, World!' message"); // Parameter description
MODULE_VERSION("0.02");  // Increase the version since we made changes


// This is the initialization function (__init) that runs when the module is loaded into the kernel
static int __init lkm_example_init(void) {
    printk(KERN_INFO "Hello, %s!\n", name);  // Use the parameter in printk
    return 0;
}

// This is the exit function (__exit) that runs when the module is removed from the kernel
static void __exit lkm_example_exit(void) {
    printk(KERN_INFO "Goodbye, %s!\n", name);  // Use the parameter in printk
}

module_init(lkm_example_init);
module_exit(lkm_example_exit);









