#ifndef     COMMON_H
#define     COMMON_H

/* All the standard libraries goes here */
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

/* All the platform related files goes here */


/* All the local libraries goes here */
#include "junk_numbers.h"
#include "junk_thread.h"

#define DEV_ASSERT(status)  {if(status){}  else {printf("Assert in %s() at line %u \n", __func__, __LINE__);}}  


#ifdef INCLUDE_TEST_SUIT
#include <stdio.h>
void test_suit(void);
#endif

#endif