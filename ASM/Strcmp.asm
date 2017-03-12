; Strcmp (LEA[str1], LEA[str2], length in ECX)
; Store 0 in EAX if str1 equals str2, 0FFFFFFFFh otherwise
; Corrupts EAX, ECX
;;;
; Assuming definition of str1, str2 in Data segment:
; str1 DB 'STRING'
; str2 DB 'HAHAHA'
; (in this case ECX will be changed to 6 before calling Strcmp)
STRCMP:
	PUSH EBP ; cdecl operations
	MOV EBP,ESP
	PUSH ESI
	PUSH EDI
	PUSH EBX

	MOV ESI, [EBP+8] ; Address of str1
	MOV EDI, [EBP+12] ; Address of str2
	CLD ; Reset DF
AGAIN:
	LODSB ; Read char from str1
	XCHG AL, BL ; Store it
	LODSB ; Read char from str2
	CMP AL, BL ; Compare chars
	JNE NO ; If different, return FALSE
	LOOP AGAIN ; do for 'length' received chars
	XOR EAX,EAX ; Return TRUE
	JMP RESTORE
NO: ; Return False
	XOR EAX,EAX 
	NOT EAX
	
RESTORE: ; cdecl operations
	POP EBX
	POP EDI
	POP ESI
	MOV ESP, EBP
	POP EBP
	RET