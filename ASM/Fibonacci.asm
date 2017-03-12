; Fibo (unsigned n in ECX) -> EAX (nth number in Fibonacci Sequence)
; Corrupts EAX, EBX
FIBO:
	PUSH EBP ; cdecl operations
	MOV EBP,ESP
	PUSH ESI
	PUSH EDI

	; Recursion termination for first 2 numbers in Fibonacci Sequence (1, 1)
	CMP ECX, 2
	JLE INIT
	DEC ECX ; n-1 -> n
	CALL FIBO ; calculate Fibo(n-1)
	INC ECX ; n+1 -> n
	
	; Applying Fibonacci algorithm
	XCHG EAX, EBX
	ADD EAX, EBX
	JMP RESTORE ; Return Fibo(current n)
INIT:
	MOV EAX, 1 ; Fibo(2)
	MOV EBX, 1 ; Fibo(1)
	
RESTORE: ; cdecl operations
	POP EDI
	POP ESI
	MOV ESP, EBP
	POP EBP
	RET