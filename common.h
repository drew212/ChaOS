/* common.h -- Typedefs and global functions
 *
 * ChaOS Kernel
 * Author - Drew Cross <mstngdrew212@gmail.com>
 */

#ifndef COMMON_H
#define COMMON_H

typedef unsigned int    uint32_t;
typedef          int    int32_t;
typedef unsigned short  uint16_t;
typedef          short  int16_t;
typedef unsigned char   uint8_t;
typedef          char   int8_t;


void outb(uint16_t port, uint8_t value);
u8int inb(uint16_t port);
u16int inw(uint16_t port);

#endif

