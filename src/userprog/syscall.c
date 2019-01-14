#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"
#include "userprog/pagedir.h"

static void syscall_handler (struct intr_frame *);

void map_page_zero();
void unmap_page_zero();

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler (struct intr_frame *f UNUSED) 
{
	int syscall_no = ((int*)f->esp)[0];
	char *buffer;
	int fd, size;
	switch (syscall_no) {
		case SYS_EXIT:
			thread_exit();
			break;
		case SYS_WRITE:
			fd = ((int*)f->esp)[1];
			buffer = (char*)((int*)f->esp)[2];
			size = ((int*)f->esp)[3];
			if (fd == 1)
			{
				putbuf(buffer, size);
				return;
			}
			return;
		case SYS_MAP_PAGE_ZERO:
			map_page_zero();
			return;
		case SYS_UNMAP_PAGE_ZERO:
			unmap_page_zero();
			return;

	}
	thread_exit ();
}

void map_page_zero()
{
	struct thread *current = thread_current();
	current->usable = true;
}

void unmap_page_zero()
{
	struct thread *current = thread_current();
	current->usable = false;
}


