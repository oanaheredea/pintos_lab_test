#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/init.h"
#include "threads/synch.h"
#include "threads/thread.h"

static thread_func func1;
static thread_func func2;
static thread_func func3;

void my_threads_exam()
{
	thread_create("t1", PRI_DEFAULT, func1, NULL);
	thread_create("t2", PRI_DEFAULT, func2, NULL);
	thread_create("t3", PRI_DEFAULT, func3, NULL);
}

static void
func1(void *aux UNUSED)
{
}

static void
func2(void *aux UNUSED)
{
	thread_yield();
}

static void
func3(void *aux UNUSED)
{
	for (int i = 0; i < 1000; i++)
	{
		thread_yield();
	}
}
