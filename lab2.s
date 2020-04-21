.section .data 
str_d:
        .asciz "%d\n"
array_start:
        .long 7,1,4,5,8,13,2,98,3,56
.set count_el, (.-array_start)/4
.globl main
.type main, @function
.text 
main:

        movl $0, %ecx 
        movl array_start, %ebx 
        movl array_start, %edx
        jmp check_el 
cycle:
        movl array_start(,%ecx,4), %eax 
        cmpl %ebx, %eax
        jge  max
        cmpl %edx, %eax 
        jle min
        jmp next 
max:
        movl %eax, %ebx
        jmp next
min:
        movl %eax, %edx
        jmp next
next:
        inc %ecx 
check_el:
        cmpl $count_el, %ecx 
        jl cycle 

pushl %edx
pushl $str_d 
call printf
addl $8, %esp
movl  $0, %eax
pushl %ebx
pushl $str_d 
call printf
addl $8, %esp
movl  $0, %eax
ret 
