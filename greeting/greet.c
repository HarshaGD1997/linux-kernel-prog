#include <linux/module.h>
#include <linux/netlink.h>
#include <net/sock.h>
#include <linux/string.h>

#define NETLINK_TEST_PROTOCOL 31

static struct sock *nl_sk = NULL;

static void netlink_rcv_msg_fn(struct sk_buff *skb_in)


static struct netlink_kernel_cfg cfg= {
	.input = netlink_rcv_msg_fn, 

}

static int __init Greeting_init(void){
	printk(KERN_INFO "Module loaded\n");
	nl_sk = netlink_kernel_create(&init_net, NETLINK_TEST_PROTOCOL, &cfg);
	if(!nl_sk){
		printk(KERN_INFO "NETLINK SOCKET FAILED\n");
		return -ENOMEM;
	}
	printk(KERN_INFO "NETLINK MOD CREATED\n");
	return 0;
}

static int __exit Greeting_exit(void){
	printk(KERN_INFO "Module exited\n");
	netlink_kernel_release(nl_sk);
	nl_sk = NULL;
}

module_init(Greeting_init);
module_exit(Greeting_exit);

MODULE_LICENSE("GPL");
