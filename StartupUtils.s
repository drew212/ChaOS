; ChaOS Kernel file
; External functions

[GLOBAL setGDT]
set_gdt:
	mov eax, [esp+4]
	lgdt [eax]

	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	jmp 0x80:.flush


.flush:
	ret

[GLOBAL setIDT]
set_idt:
	mov eax, [esp+4]
	lidt [esp+4]
	ret
