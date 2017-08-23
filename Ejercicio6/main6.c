//Devuelve el valor mayor, finalizando una vez que llegue a cierta cantidad de datos
long main(){
    long datos[]={3,67,34,222,45,75,54,34,44,33,22,11,66,0};
    long mayor;
    char i;
    
    mayor=datos[0];
    for(i=1;i!=13;i++){     // 13   ==  14(datos) - 1
        if(datos[i]>mayor)
        mayor=datos[i];
    }
    
    return (mayor);
}
