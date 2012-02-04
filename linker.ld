/* linker.ld - Linker script
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-
 * ShareAlike 3.0 Unported License. To view a copy of this license, visit
 * http://creativecommons.org/licenses/by-nc-sa/3.0/ or send a letter to:
 * Creative Commons
 * 444 Castro Street, Suite 900
 * Mountain View, California, 94041, USA.
 *
 * Author(s): Drew Cross <drew@ddcross.com>
 */


ENTRY(start)
SECTIONS
{
    .text 0x100000 :
    {
        code = .; _code = .; __code = .;
        *(.text)
        . = ALIGN(4096);
    }

    .data :
    {
        data = .; _data = .; __data = .;
        *(.data)
        *(.rodata)
        . = ALIGN(4096);
    }

    .bss :
    {
        bss = .; _bss = .; __bss = .;
        *(.bss)
        . = ALIGN(4096);
    }

    end = .; _end = .; __end = .;
}
