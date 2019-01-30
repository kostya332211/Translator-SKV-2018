.586
	.model flat, stdcall
	includelib libucrt.lib
	includelib kernel32.lib
 ExitProcess PROTO :DWORD

		EXTRN OutStr: proc
		EXTRN OutNum: proc
		EXTRN PowNum: proc
		EXTRN InputNum: proc
		EXTRN Strlen: proc
		EXTRN MinNum: proc
		EXTRN MaxNum: proc

.stack 4096
.const
	L1 BYTE 'SKV-2019' , 0
	L2 BYTE 'SKV-2018' , 0
	L3 BYTE 'a less b' , 0
	L4 DWORD 5
	L5 DWORD 10
	L6 DWORD 100
	L7 DWORD 10
	L8 DWORD 100
	L9 DWORD 1
.data
	c_aa SDWORD ?
	z_bb DWORD ?
	a_main SDWORD ?
	b_main SDWORD ?
	c_main SDWORD ?
	from_main SDWORD ?
	to_main SDWORD ?
	d_main DWORD ?
	e_main DWORD ?
.code
	aa  PROC a_aa :  sdword , b_aa :  sdword 
push a_aa
push b_aa
pop ebx
pop eax
add eax,  ebx
push eax
mov c_aa, eax
mov eax, c_aa
ret
	aa ENDP

	bb  PROC y_bb :  byte 
push offset L1
pop eax
mov z_bb, eax
mov eax, z_bb
ret
	bb ENDP

main PROC
push offset L2
pop eax
mov d_main, eax
push offset L3
pop eax
mov e_main, eax
push 5
pop eax 
mov a_main, eax
push 10
pop eax 
mov b_main, eax
