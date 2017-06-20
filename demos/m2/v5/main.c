#include <stdint.h>
#include <stdio.h>

void main()
{
  uint32_t var = 0x1234abcd;
  uint32_t * varptr = &var;

  void * ptr1 = (void*)varptr;
  void ** ptr2 = &ptr1;
  uint32_t * restrict ptr3;
  uint32_t ** ptr4 = &varptr;

  ptr3 = &var;

  printf("Pointer Sizes:\n");
  printf("   Sizeof(void *): %ld\n",sizeof(void *));
  printf("   Sizeof(void **): %ld\n",sizeof(void **));
  printf("   Sizeof(uint32_t **): %ld\n",sizeof(uint32_t **));
  printf("   Sizeof(restrict uint32_t*): %ld\n",sizeof(uint32_t * restrict));

  printf("Pointer Data Sizes:\n");

#ifdef SHOW_ERRORS
  printf("   *ptr1: %ld\n", *ptr1);
#else
  printf("   *ptr1: ERROR! Can't dereference Void* Pointer\n");
  printf("   *((uint32_t*)ptr1): %x\n\n", *((uint32_t*)ptr1));
#endif
  printf("   *ptr2: %p  --> (Pointer Type)\n", *ptr2);

#ifdef SHOW_ERRORS
  printf("   **ptr2: %d\n", **ptr2);
#else
  printf("   **ptr2: ERROR! Can't double dereference Void** Pointer\n");
  printf("   **((uint32_t**)ptr2): %x\n\n", **(((uint32_t**)ptr2)));
#endif

  printf("   *ptr3: %x\n", *ptr3);
  printf("   *ptr4: %p  --> (Pointer Type)\n", *ptr4);
  printf("   **ptr4: %x\n", **ptr4);
}
