#include "register.h"

int flash_init_t(void)
{
	return 0;
}

int flash_erase_t(int addr,int msg_len)
{
	return 0;
}

int flash_read_t(int addr,char* msg,int msg_len)
{
	return 0;
}

int flash_write_t(int addr,char* msg,int msg_len)
{
	return 0;
}

static module_register flash_register = {
	.init  = flash_init_t,
	.erase = flash_erase_t,
	.read  = flash_read_t,
	.write = flash_write_t,
};

static register_callback c_register_callback;

void module_register_init(register_callback callback)
{
	c_register_callback = callback;
	c_register_callback(&flash_register);
}

