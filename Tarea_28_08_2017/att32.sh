# la manera de ejecutar esto es por consola escribiendo:
# sh att32.sh power

as --32 $1.s main.s -o $1.o #Se ensambla el archivo
ld -melf_i386 $1.o -o $1    #Se enlaza el archivo
./$1                        #Se ejecuta el archivo
echo $?                     #Se visualiza el resultado
rm power power.o            #Se elimiman archivos
