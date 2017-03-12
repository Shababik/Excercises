; Exercise 2
; Store in EAX the biggest value among EAX,EBX,ECX

START:
	CMP EBX, EAX
	JG CMP2
CMP1:
	CMP ECX, EAX
	JG CMP3
	JMP SOF
CMP2:
	MOV EAX, EBX
	JMP CMP1
CMP3:
	MOV EAX,ECX
SOF:
	NOP