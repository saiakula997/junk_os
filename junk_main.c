#include "common.h"

void  first_thread_entry_function(void *parms);

int main(){
    
    JUNK_THREAD_t first;
    JUNK_THREAD_t second;
    JUNK_THREAD_t third;
    JUNK_THREAD_t fourth;
    JUNK_STATUS_t status;
    
    status = junk_thread_create(&first, 10, "first", first_thread_entry_function);
    DEV_ASSERT(status == STATUS_SUCCESS);
    
    status = junk_thread_create(&second, 11, "second", NULL);
    DEV_ASSERT(status == STATUS_SUCCESS);

    status = junk_thread_create(&third, 12, "third", NULL);
    DEV_ASSERT(status == STATUS_SUCCESS);

    status = junk_thread_create(&fourth, 13, "fourth", NULL);
    DEV_ASSERT(status == STATUS_SUCCESS);

    junk_schedule();

    #ifdef INCLUDE_TEST_SUIT
    test_suit();
    #endif

    return 0;
}

void  first_thread_entry_function(void *parms){

}