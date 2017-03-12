; Pow(signed base,unsigned exponent) -> EAX (Quotient), EDX (Remainder)
; Corrupts EAX, EDX
POW:
	PUSH EBP ; cdecl operations
	MOV EBP,ESP
	PUSH ESI
	PUSH EDI
	PUSH EBX

	; Initial values
	MOV EAX, 1
	MOV EDX, 0
	MOV EBX, [EBP+8] ; Base parameter
	MOV ECX, [EBP+12] ; Exponent parameter
	CMP ECX, 0 ; If exponent is 0,
	JE RESTORE ; Return 1
EXP:
	IMUL EBX ; Signed multiplication of 1 by base -
	LOOP EXP ; Exponent times
	
RESTORE: ; cdecl operations
	POP EBX 
	POP EDI
	POP ESI
	MOV ESP, EBP
	POP EBP
	RET