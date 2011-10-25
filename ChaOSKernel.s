; ChaOS Kernel file
; External functions

[GLOBAL setGDT]
setGDT:
	lgdt [ebp+4]


[GLOBAL setIDT]
setIDT:
	lidt [ebp+4]
