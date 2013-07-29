#include <mem.h>

kmem_header *heap;

void mem_init(unsigned long pl_addr, unsigned long pl_size)
{
	// last_page - последняя страница как физической,
	// так и виртуальной памяти
        unsigned long last_page = (pl_addr&0x0FFFF000) + 0x1000;
	heap = (kmem_header *)(last_page|0xFFFFFFFFC0000000);
        printf("Last phys page is %l\n", last_page);
        page_init(&last_page);
	phys_init(&last_page);
}

void *kmalloc(unsigned long size)
{
}

void kfree(void *p)
{
}

