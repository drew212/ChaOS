# Copyright (C) 2011 Drew Cross
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.}

# Makefile for ChaOS OS
# Author - Drew Cross

SOURCES = $(MULTIBOOT).o $(CHAOSKERNEL).o $(SCREEN).o $(COMMON).o $(STARTUPUTILS).o $(TABLES).o $(ISR).o $(INTERRUPTS).o
CFLAGS = -Wall -Wextra -nostdlib -nostdinc -fno-stack-protector -nostartfiles -nodefaultlibs
LDFLAGS = -m elf_i386 -T linker.ld
ASFLAGS = -elf


# FILENAMES
STARTUPUTILS = StartupUtils
MULTIBOOT = Multiboot
CHAOSKERNEL = ChaOSKernel
SCREEN = screen
COMMON = common
TABLES = tables
ISR = isr
INTERRUPTS = interrupts

CFLAGS=-nostdlib -nostdinc -fno-builtin -fno-stack-protector
LDFLAGS=-Tlink.ld
ASFLAGS=-felf

all: $(SOURCES) link

clean:
		-rm *.o kernel

link:
		ld $(LDFLAGS) -o kernel.bin $(SOURCES)

.s.o:
		nasm $(ASFLAGS) $<
