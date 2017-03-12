; Exercise 4
; Store 0 in EAX if value in ECX is an exponentiation of 2, 0FFFFFFFFh otherwise
; Assuming ECX value is unsigned

START:
	MOV EAX, ECX ; Working copy of value in ECX
	MOV EBX, ECX ; Backup copy of value in ECX
	MOV ECX, 32 ; Checking all 32 bits
	XOR EDI,EDI	; DI counts occurrences of 1
AGAIN:
	SHR EAX, 1 ; Unsigned division by 2 
	JNC CONT ; Continue if CF isn't 1
	INC EDI ; Increase occurrences of 1 counter by 1
CONT:
	LOOP AGAIN ; Divide again
	XOR EAX, EAX ; EAX = 0
	CMP EDI, 1 ; If there was 1 occurrence of 1
	JE SOF ; return 0
	NOT EAX ; Else, return 0FFFFFFFFh
SOF:
	MOV ECX, EBX ; Restore original value of ECX from backup copy