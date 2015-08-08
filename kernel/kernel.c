#include <ktty.h>
#include <klibc.h>
#include <cpuid.h>
#include <gdt.h>
#include <task.h>
#include <intr.h>
#include <smp.h>
#include <phys.h>
#include <page.h>
#include <multiboot.h>
#include <mutex.h>

#include <ata_pio.h>

#include <debug.h>

/* 
 * Главная функция 
 */
long kernel_start(uint64_t mb_magic, multiboot_info_t *mb)
{
  GDT_init();
  tss_init();
  ktty_init();

  if (mb_magic != MULTIBOOT_LOADER_MAGIC)
  {
    printf("Sorry, this kernel relies heavily on information,\n");
    printf("provided by Multiboot-compiliant bootloader!\n");
    printf("System halted.");
    return -1;
  }

  // Общая информация о памяти
  //printf ("mem_lower = %dKB, mem_upper = %dKB\n",
  //       (uint32_t) mb->mem_lower, (uint32_t) (mb->mem_upper));
  intr_init();

  printf("OS_64 build date: %s %s\n", __DATE__, __TIME__);

  extern uint64_t kernel_end;
  uint64_t pool = &kernel_end;
  mem_init(pool, (mb->mem_upper>>10)+2, mb);  // TODO: Исправить!

  smp_init();
  task_init();

  printf("Kernel alive, up and running!\n");

  //char *test_text = "Syscall %d test\n";
  char *text_video = 0xFFFFFFFFC00B8000;
  char c = 0;
  // Тест многозадачности
  if (task_fork() == 0)
  {
    // Дочерняя задача
    // Крутим циферку в верхнем левом углу
    for(;;) 
    {
      //ktty_putc('C');
      // Тест системных вызовов
      //syscall_test_out(test_text, 51);
      text_video[1] = c++;
      asm("hlt");
    }
  } else {
    // Тест ATA
#if 0
    char *bootsect = kmalloc(512);
    ata_pio_read(bootsect, 0, 1);
    int i;
    for (i = 0; i < 512; i++)
      printf("%x", bootsect[i]);
    kfree(bootsect);
#endif

    fs_test_main(0, 0);

    // Крутим циферку в верхнем правом углу
    for(;;) 
    {
      //ktty_putc('P');
      text_video[159] = c++;
      asm("hlt");
    }
  }
  return 0;
}

