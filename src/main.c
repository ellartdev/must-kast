#include <system.h>

/* You will need to code these up yourself!  */
void *memcpy(void *dest, const void *src, int count) {
    /* Add code here to copy 'count' bytes of data from 'src' to
    *  'dest', finally return 'dest' */

   // Typecast src and dest addresses to (char *)
   const char *csrc = (const char *)src;
   char *cdest = (char *)dest;

   // Copy source (src) to destination (dest)
   for (int i = 0; i < count; i++) {
       cdest[i] = csrc[i];
   }
   return dest;
}

void *memset(void *dest, char val, int count) {
    /* Add code here to set 'count' bytes in 'dest' to 'val'.
    *  Again, return 'dest' */
   char *p = (char *)dest;
   for ( ; count != 0; count--) *p++ = val;
   return dest;
}

uint16 *memsetw(uint16 *dest, uint16 val, int count)
{
    /* Same as above, but this time, we're working with a 16-bit
    *  'val' and dest pointer. Your code can be an exact copy of
    *  the above, provided that your local variables if any, are
    *  unsigned short */
   uint16 *p = (uint16 *)dest;
   for ( ; count != 0; count--) *p++ = val;
   return dest;
}

int strlen(const char *str)
{
    /* This loops through character array 'str', returning how
    *  many characters it needs to check before it finds a 0.
    *  In simple words, it returns the length in bytes of a string */
   int retval;
   for (retval = 0; *str != '\0'; str++) retval++;
   return retval;
}

/* We will use this later on for reading from the I/O ports to get data
*  from devices such as the keyboard. We are using what is called
*  'inline assembly' in these routines to actually do the work */
uint8 inportb(uint16 _port)
{
    uint8 rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

/* We will use this to write to I/O ports to send bytes to devices. This
*  will be used in the next tutorial for changing the textmode cursor
*  position. Again, we use some inline assembly for the stuff that simply
*  cannot be done in C */
void outportb(uint16 _port, uint8 _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

/* This is a very simple main() function. All it does is sit in an
*  infinite loop. This will be like our 'idle' loop */
int main() {
    /* You would add commands after here */

    // Preparing GDT, IDT, ISRs and installing 'em
    gdt_install(); idt_install(); isrs_install();

    init_video(); must_kast_logo();

    /* ...and leave this loop in. There is an endless loop in
    *  'start.asm' also, if you accidentally delete this next line */
    for (;;);
}
