MAIN   SEGMENT
	ASSUME  CS:MAIN, DS:MAIN
	MOV	CX, 1234h
	mov	AX, 1234h
	mov	SUM, 1234h
SUM	DW	5555h
	mov AX, 1234
MAIN  	ENDS
	END