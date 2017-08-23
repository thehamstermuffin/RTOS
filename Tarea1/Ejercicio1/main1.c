//Devuelve el valor mayor, terminando la cadena con un 0
long main(){
    long datos[]={3,67,34,222,45,75,54,34,44,33,22,11,66,0};
    long mayor;
    char i;
    
    mayor=datos[0];
    for(i=1;datos[i]!=0;i++){
        if(datos[i]>mayor)
        mayor=datos[i];
    }
    
    return (mayor);
}
