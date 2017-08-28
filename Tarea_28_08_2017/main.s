#PURPOSE:   Program to illustrate how functions work
#           This program will compute the value of
#           2^3 + 5^2
#
#Everything in the main program is stored in registers,
#so the data section doesn’t have anything.
.section .data

.section .text

.globl _start
_start:
pushl $3        #push second argument
pushl $2        #push first argument
call power      #call the function
addl $8, %esp   #move the stack pointer back
pushl %eax      #save the first answer before
                #calling the next function
                
pushl $2        #push second argument
pushl $5        #push first argument
call power      #call the function
addl $8, %esp   #move the stack pointer back

popl %ebx       #The second answer is already
                #in %eax. We saved the
                #first answer onto the stack,
                #so now we can just pop it
                #out into %ebx
                
addl %eax, %ebx #add them together
                #the result is in %ebx
movl $1, %eax
int $0x80       #exit (%ebx is returned)
