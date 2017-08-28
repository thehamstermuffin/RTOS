//Devuelve el valor mayor, terminando con una direccion especifica en la cadena de datos
long main(){
    long datos[]={3,67,34,222,45,75,54,34,44,33,22,11,66,0};
    long mayor;
    long *i_dir=datos;
    long *f_dir=datos+14;
    
    
    mayor=*i_dir;
    for(i_dir++;i_dir!=f_dir;i_dir++){
        if(*i_dir>mayor)
        mayor=*i_dir;        
    }
    
    return (mayor);
}
