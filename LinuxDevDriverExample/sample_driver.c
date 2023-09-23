#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>

ssize_t sd_read (struct file *fileOp,char *buffPtr, size_t len,loff_t *offset);

static int device_major_num = 0;
static const char device_name[] = "Sample_Driver";
static struct file_operations sd_file_ops = 
{
	.owner = THIS_MODULE,
	.read  = sd_read,
};

ssize_t sd_read (struct file *fileOp,char *buffPtr, size_t len,loff_t *offset)
{
	return 0;
}

ssize_t	sd_write (struct file *fileOp, char *buffPtr, size_t len, loff_t *offset)
{
	return 0;
}

static int sd_init(void)
{
	printk(KERN_ALERT "sample driver init module\n");
	return 0;
}

static void sd_exit(void)
{

	printk(KERN_ALERT "sample driver exit module\n");
}

int register_sd(void)
{
	int ret = 0;
	ret = register_chrdev(0,device_name,&sd_file_ops);
	if (ret < 0)
	{
		printk(KERN_ALERT "Failed to register char device\n");
		device_major_num = ret;
	}
	else {
		printk(KERN_ALERT "Char device created\n");
	}
	return ret;
}

void unregister_sd(void)
{
	if (device_major_num != 0)
	{
		unregister_chrdev(device_major_num,device_name);
	}
}



module_init(sd_init);
module_exit(sd_exit);

MODULE_AUTHOR("Prithwiraj Shome");
MODULE_LICENSE("GPL-2.0");
MODULE_DESCRIPTION("Sample driver");		
