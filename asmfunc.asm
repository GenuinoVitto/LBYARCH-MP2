; Initialization
section .data
section .text
	bits 64
	default rel		
	global dotProduct

; Dot Product Function 
dotProduct:
	; Reset Values to 0
	pxor XMM0, XMM0
	pxor XMM1, XMM1
	pxor XMM2, XMM2
	pxor XMM3, XMM3
	pxor XMM4, XMM4

	; Loop 
	L1:
		MOVSS XMM1, [RDX]
		MOVSS XMM2, [R8]
		VMULSS XMM3, XMM1, XMM2
		ADDSS XMM4, XMM3
		ADD RDX, 4
		ADD R8, 4
		LOOP L1

	; Result is placed inside XMM0
	MOVSS XMM0, XMM4
	ret