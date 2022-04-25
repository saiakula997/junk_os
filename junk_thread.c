#include "common.h"

JUNK_THREAD_t *central_thread_list = NULL;

uint32_t new_thread_id(){
    static uint32_t new_thread_id = 0;
    return new_thread_id++;
}

JUNK_STATUS_t junk_thread_create(JUNK_THREAD_t *thread, uint8_t priority, char *name, thread_entry_function_t thread_entry_fun){
   /* Assign values to the new junk thread  */
   thread->thread_id = new_thread_id();
   strncpy(thread->thread_name, name, MAX_THREAD_LENGHTH);
   thread->priority = priority;
   thread->thread_stack_size = MAX_THREAD_STACK_SIZE;
   thread->thread_stack_curr_ptr = (uint8_t *) thread->thread_stack_start;
   thread->thread_status = RUNNING;
   thread->thread_entry_fun = thread_entry_fun;
   thread->prev = NULL;
   thread->next = NULL;

   /* Add thread to the list */ 
   JUNK_STATUS_t status = add_new_thread_to_central_list(thread);
   if(status == STATUS_ERROR){
       /* Todo : handle error case */
       return status;
   }
   return status;
}

JUNK_STATUS_t add_new_thread_to_central_list(JUNK_THREAD_t *thread){
    JUNK_STATUS_t status = STATUS_ERROR;
    JUNK_THREAD_t *head = central_thread_list;
    
    if(head == NULL){
        central_thread_list = thread;
        return STATUS_SUCCESS; 
    }
    do{
        if(head->next == NULL){
            thread->prev = head;
            head->next = thread;
            status = STATUS_SUCCESS;
            break;
        }
        else{
            head = head->next;
        }
    }while(head);

    return status;
}

JUNK_STATUS_t remove_thread_from_central_list(uint32_t id){
    JUNK_STATUS_t status = STATUS_ERROR;
    JUNK_THREAD_t *head = central_thread_list;
    while(head && status == STATUS_ERROR){
        /* First & last node */
        if(head->thread_id == id && head->prev == NULL && head->next == NULL){
            central_thread_list = NULL;
            status = STATUS_SUCCESS;
        }
        /* First node */
        else if(head->thread_id == id && head->prev == NULL){
            central_thread_list = head->next;
            head->next->prev = NULL;
            status = STATUS_SUCCESS;
        }
        /* Last node */
        else if(head->thread_id == id && head->next == NULL){
            head->prev->next = NULL; 
            status = STATUS_SUCCESS;
        }
        /* Middle node */
        else if (head->thread_id == id) {
           head->prev->next = head->next; 
           head->next->prev = head->prev;
           status = STATUS_SUCCESS;
        }
        head = head->next;
    }
    return status;
}

JUNK_STATUS_t junk_thread_delete(uint32_t id){
    /* Todo : Do preliminary checks and proceed */
    JUNK_STATUS_t status = STATUS_ERROR;
    status = remove_thread_from_central_list(id);
    return status;
}

JUNK_STATUS_t find_next_thread(JUNK_THREAD_t *thread){
    JUNK_STATUS_t status = STATUS_ERROR;
    JUNK_THREAD_t *head = central_thread_list;
    uint8_t priority = 0;

    while (head)
    {
        if(head->priority > priority){
            thread = head;
            priority = head->priority;
            status = STATUS_SUCCESS;
        }
        head = head->next;
    }

    return status;
}

void junk_schedule(void){
    
}