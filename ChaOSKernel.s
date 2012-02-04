; ChaOSKernel.s - ChaOS assembly kernel file
;
; This work is licensed under the Creative Commons Attribution-NonCommercial-
; ShareAlike 3.0 Unported License. To view a copy of this license, visit
; http://creativecommons.org/licenses/by-nc-sa/3.0/ or send a letter to:
; Creative Commons
; 444 Castro Street, Suite 900
; Mountain View, California, 94041, USA.
;
; Author(s): Drew Cross <drew@ddcross.com>

; External functions
[GLOBAL setGDT]
setGDT:
	lgdt [ebp+4]


[GLOBAL setIDT]
setIDT:
	lidt [ebp+4]
