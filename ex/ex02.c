#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>

#include <asm/uaccess.h>
#include <linux/errno.h>


#include <linux/device.h>
//#include <linux/string.h>
//#include <linux/types.h>
//#include <linux/kernel.h>
#include "ex02_cmd.h"

#define DEV_SIZE 100
static struct class *ex_class;

struct chardev_ex 
{
  char buf[DEV_SIZE];
  unsigned int major;
  unsigned int minor;
  unsigned int cur_size;
  dev_t cdevno;
  struct cdev ex02;
};

int ex02_open(struct inode *node,struct file *filp)
{ 
  struct chardev_ex *cdevp;
  cdevp = container_of(node->i_cdev,struct chardev_ex,ex02);
  filp->private_data=cdevp; 
  printk("open is ok\n");
  return 0;
}

int ex02_close(struct inode *node,struct file *filp)
{
 printk("close is ok\n");
 return 0;
}

ssize_t ex02_read(struct file *filp,char __user *buf,size_t count,loff_t *offset)
{
int ret;
struct chardev_ex *cdevp = filp->private_data;
if(!cdevp->cur_size)
   {
     return 0;
   }

if(copy_to_user(buf,cdevp->buf,count))
   {
     ret = -EFAULT;
     printk("kernel read is fail\n");
   }
else
   {
     ret = count;
     cdevp->cur_size = count;
     printk("kernel read is ok  ");
     printk("cur_size:%d\n",cdevp->cur_size);
     printk("buf=%s\n",cdevp->buf);
   }

   return ret;
}

ssize_t ex02_write(struct file *filp,char __user *buf,size_t count, loff_t *offset)
{
  int ret;
  struct chardev_ex *cdevp = filp->private_data;
  
  if(copy_from_user(cdevp->buf,buf,count))
    {
       ret = -EFAULT;
       printk("kernel write is wrong\n");
    }
  else
    {
       ret = count;
       printk("kernel write is ok  ");
       cdevp->cur_size = count;
       printk("cur_size=%d\n",cdevp->cur_size);    
    }
  
   return ret;

}


static int ex02_ioctl(struct file *filp,unsigned int cmd,unsigned long arg)
{
  printk("ioctl ok\n");
  struct chardev_ex *cdevp = filp->private_data;
  int ret = 0;
	switch(cmd){
		case ex02_CLEAR:
			memset(cdevp->buf, 0, DEV_SIZE);
			cdevp->cur_size = 0;
			filp->f_pos = 0;
			ret = 0;
                        printk("buf is clear\n");
			break;
		default:	/*命令错误时的处理*/
			printk("cmd is error\n");
			ret = - EINVAL;
			break;
                    }
    return ret;
}


struct file_operations ex02_fops = {
     .owner = THIS_MODULE,
     .open = ex02_open,    
     .write = ex02_write,
     .unlocked_ioctl =ex02_ioctl,
     .read = ex02_read,  
     .release = ex02_close,
};


struct chardev_ex chardev;

static int __init ex02_init(void)
{
   int result = 0;
   chardev.cur_size = 0;
   chardev.major = 0;
   chardev.minor = 0;

  if(chardev.major)
    {
     chardev.cdevno = MKDEV(chardev.major,chardev.minor);
     result = register_chrdev_region(chardev.cdevno,1,"ex02");
    }
  else
    {
     result = alloc_chrdev_region(&chardev.cdevno,chardev.minor,1,"alloc driver");
     chardev.major = MAJOR(chardev.cdevno);
     chardev.minor = MINOR(chardev.cdevno);    
    }
  if(result < 0)
    {
      printk("register is wrong\n");
       return result;
    }
   
   printk("major[%d] minor[%d]\n", chardev.major, chardev.minor);

cdev_init( &chardev.ex02, &ex02_fops);

if(!cdev_add(&chardev.ex02,chardev.cdevno,1))
  {
    printk("cdev_add is ok\n"); 
  }
 else
  {
  printk("cdev_add is error\n"); 
  unregister_chrdev_region(chardev.cdevno,1);
  }
/*
*Creat class and device.
*/
ex_class = class_create(THIS_MODULE,"ex_class");
if(IS_ERR(ex_class))
{
printk("creat ex_class failed!\n");
return -1;
}
device_create(ex_class,NULL,chardev.cdevno,NULL,"%s","ex02");
    printk("hello kernel!\n");

  return 0;
}

static void __exit ex02_exit(void)
{
  cdev_del(&chardev.ex02);
  unregister_chrdev_region(chardev.cdevno,1);
  printk("exit kernel is ok\n");
}


module_init(ex02_init);
module_exit(ex02_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Tenix Xu");
MODULE_VERSION("v0.1");

