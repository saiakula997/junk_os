
#ifndef     JUNK_THREAD_H
#define     JUNK_THREAD_H

#include "common.h"

typedef enum JUNK_STATUS{
	STATUS_SUCCESS = 0,
	STATUS_ERROR,
}JUNK_STATUS_t;

typedef enum THREAD_STATUS{
	RUNNING = 0,
	WAITING,
	STOPPED,
}THREAD_STATUS_t;

typedef void (* thread_entry_function_t)(void * parms);

typedef struct JUNK_THREAD{
uint32_t thread_id;
char thread_name[MAX_THREAD_LENGHTH];
uint8_t priority;
uint32_t thread_stack_size;
uint8_t *thread_stack_curr_ptr;
THREAD_STATUS_t thread_status;

thread_entry_function_t thread_entry_fun;
uint8_t thread_stack_start[MAX_THREAD_STACK_SIZE];

struct JUNK_THREAD *prev;
struct JUNK_THREAD *next;

}JUNK_THREAD_t;

JUNK_STATUS_t junk_thread_create(JUNK_THREAD_t *thread, uint8_t priority, char *name, thread_entry_function_t thread_entry_fun);
JUNK_STATUS_t junk_thread_delete(uint32_t id);

JUNK_STATUS_t add_new_thread_to_central_list(JUNK_THREAD_t *thread);
JUNK_STATUS_t remove_thread_from_central_list(uint32_t id);
JUNK_STATUS_t find_next_thread(JUNK_THREAD_t *thread);

void junk_schedule(void);
JUNK_STATUS_t junk_thread_wait(void);

#endif