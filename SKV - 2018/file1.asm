.586
	.model flat, stdcall
	includelib libucrt.lib
	includelib kernel32.lib

 EXTRN output: proc 
 ExitProcess PROTO :DWORD


.stack 4096
.const
	L1 DWORD 1
	L2 DWORD 0
.data
	x SDWORD ?
.code
main PROC
	push L1
	pop x
	push x
	call output
	push 0 
	call ExitProcess
main ENDP
end main