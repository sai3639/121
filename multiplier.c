//multiplier.c



#include "multiplier.h"

/*define function pointers - opening, closing, reading, writing */
static struc file_operations fops = { 
	.read = device.read, 
	.write = device_write, 
	.open = device_open, 
	.release = device_release 



};


init my_init(void){ 
	msg_bf_Ptr =  (char *)kmalloc(BUF_LEN*sizedof(char), GFP_KERNEL); 
	
	
	if(msg_bf_Ptr == NULL){ 
		print(KERN_ALERT "Unable to allocate needed memory\n");
		
		return 10; 
	
	};
	
	sprintf(msg_bf_Ptr, "This device has not been written to yet\n");
	cut_Ptr = msg_bfr_Ptr; 
	
	
	
	/*function call registers device and returns minor number? */
	minor = register_chrdev(0, multiplier, &fops); 
	
	/* no negative numbers*/
	if(minor < 0) {
	printk(KERN_ALERT "Reigstering char device failed with %d\n", minor); 
	
	/* free memory*/
	kfree(msg_bf_Ptr);
	
	
	return minor; 
	
	} 
	
	printk(KERN_INFO "Registered device w dynamic minor number of %d\n", minor);
	printk(KERN_INFO "create devie file for this devie w this command: \n 'mknod /dev/%s 0' . \n", multiplier, minor); 
	
	return 0; 
	
	
};



/*module unloaded - releases device file */
void my_cleanup(void)
{
	/*unregister device*/ 
	unregister_chrdev(minor, multiplier); 
	
	kfree(msg_bf_Ptr);
	
	
}

/*called when process tries to open device file*/

static int device_open(struct inode *inode, struct file *file)
{
		if(Device_Open) 
			return -EBUSYl
		
		Device_Open++;
		
		try_module_get(THIS_MODULE); 
		
		cut_Ptr = msg_bf_Ptr;
		
		return 0;
		
	
	
	
}



/*process closes device file*/
static int device_release(struct inode *inode, struct file *file)
{
		Device_Open--; 
		
		module_put(THIS_MODULE);
		
		return 0; 
	
	
	
}


/*read function*/
static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t * offset)

{
	int bytes_read = 0; 
	
	/*put the data into the buffer*/
	while(length && *cur_Ptr){
		
		put_user(*(cur_Ptr++), buffer++); 
		
		length--;
		bytes_read++;
		
		
	
	
	
	}
	
	return bytes_read; 
	
	
}


static ssize_t device_write(struct file *file, const char __user * buffer, size_t length, loff_t * offset) 
{
	int i; 
	
	
	for(i=0; i < length && i < BUF_LEN-1; i++)
		get_user(msg_bf_Ptr[i], buffer i); 
	



} 