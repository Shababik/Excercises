; Exercise 3	
; Mirror the bytes horizontally in EAX

START:
	MOV EDI, 4 ; Bytes in 32-bit register (external loop counter)
	XOR EBX, EBX ; EBX holds the flipped bytes
PREP:
	MOV ECX, 8 ; Bits in byte to shift from EAX through CF
	XOR EDX, EDX ; EDX receives the rolled bits through CF
AGAIN:
	SHL EAX, 1 ; Left bit goes into CF, 0 to right bit of EAX
	RCL EDX, 1 ; Rolled bit goes to right bit of EDX, 0 to CF
	LOOP AGAIN ; Do this for 1 more bit
	OR EBX, EDX ; Copy the rolled byte to the lowest part of EBX
	ROR EBX, 8 ; Make space for another byte in EBX
	SUB EDI, 1 ; Decrease 1 from byte counter
	JZ SOF ; If counter is zero go to SOF
	JMP PREP ; If counter is not zero, copy another byte
SOF:
	OR EAX,EBX ; Since EAX is now 0, copy relevant bits from EBX
	NOP