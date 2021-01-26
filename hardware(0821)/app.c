#include "register.h"

/*app*/
static p_module_register p_flash_register;

static void module_register_con_add(p_module_register *p)
{
	p_flash_register = &p;
}

int main()
{
	module_register_init(module_register_con_add);

	
	
	return 0;
}