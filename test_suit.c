#include "test_suit.h"

void print_test_suit_menu(){
    printf("1. Print central thread list details \n");
    printf("2. Delete thread \n");
    printf("3. Find next thread \n");
    printf("0. Exit test suit \n");
}

void test_suit(void){
    uint32_t choice;
    do{
       print_test_suit_menu();
       printf("Enter Choice :");
       scanf("%u", &choice);

        switch(choice){
            case 1:
            {
                print_central_thread_list_details();
            }
            break;

            case 2:
            {
               uint32_t id = 0;
               printf("Enter thread Id : ");
               scanf("%u", &id);
               DEV_ASSERT(junk_thread_delete(id) == STATUS_SUCCESS);
            }
            break;

            case 3:
            {
                JUNK_THREAD_t *thread;
                DEV_ASSERT(find_next_thread(thread) == STATUS_SUCCESS);
                printf("thread %s priority %u \n", thread->thread_name, thread->priority);
            }
            break;

            case 0:
            {
                printf("Exiting test suit\n");
            }
            break;
            default:
                printf("Invalid Choice \n");
        }

    } while (choice);
}


void print_central_thread_list_details(void){
    JUNK_THREAD_t *head = central_thread_list;
    
    while(head != NULL){
        printf("Thread [ id = %u ] [ name = %s ] [ priority = %u ] [ stack start = %p ] [ stack curr = %p] \n", \
        head->thread_id, head->thread_name, head->priority, (void *)head->thread_stack_start, (void *)head->thread_stack_curr_ptr);
        head = head->next;
    }
}