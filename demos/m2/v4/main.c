#include <stdio.h>
#include <stdint.h>

__attribute__( ( always_inline ) ) static inline uint8_t EX_Read(uint8_t * port,                                                                 uint8_t pin)
{
   return ( *port & (1 << pin) );
}
__attribute__( ( always_inline ) ) static inline void EX_Write(uint8_t * port, u
                                                               uint8_t pin,
                                                               uint8_t value)
{
   value ? ( *port |= (1 << pin) ) : ( *port &= ~(1 << pin) ) ;
}

void main()
{
  uint8_t x = 0;
  uint8_t y = 0;

  printf("X value Before: %x\n", x); 
  EX_Write(&x, 4, 1);
  printf("x Value: %x\n", x); 
  EX_Write(&x, 1, 1);
  printf("X Value: %x\n", x); 
  y = EX_Read(&x, 4);
  printf("Y Value - Pos 4: %x\n", y); 
  y = EX_Read(&x, 1);
  printf("Y Value - Pos 1: %x\n", y); 
  EX_Write(&x, 4, 0);
  printf("X Value End: %x\n", x); 
}



#if 0
__attribute__( ( always_inline ) ) static inline void IO_Read(DIO_PORT_Type * port, uint8_t pin)
{
   return ( ((port)->DIR) & (1 << pin) );
}
__attribute__( ( always_inline ) ) static inline void IO_Write(DIO_PORT_Type * port, uint8_t pin, uint8_t value)
{
   value ? ( ((port)->DIR) |= (1 << pin) ) : ( ((port)->DIR) &= ~(1 << pin) ) ;
}
#endif 
