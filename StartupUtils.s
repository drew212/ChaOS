; StartupUtils.s - External functions
;
; ChaOS Kernel
; Author - Drew Cross <mstngdrew212@gmail.com>

[GLOBAL setGDT]
setGDT:
	lgdt [ebp]


[GLOBAL setIDT]
setIDT:
	lidt [ebp]
