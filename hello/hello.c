#include <linux/module.h>
#include <linux/kernel.h>

static int __init Print_Hello(void){
	printk(KERN_INFO "hello world\n");
	return 0;
}

static void __exit Exit_Hello(void){
	printk(KERN_INFO "exiting\n");
	
}

module_init(Print_Hello);
module_exit(Exit_Hello);

MODULE_LICENSE("GPL");
