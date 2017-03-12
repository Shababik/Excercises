; Exercise 1
; Summarize numbers 1-100
START:
	MOV ECX,100
	XOR EAX,EAX
AGAIN:
	ADD EAX,ECX
	LOOP AGAIN
	NOP