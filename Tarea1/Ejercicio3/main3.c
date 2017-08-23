//Devuelve el valor menor
long main(){
    long datos[]={3,67,34,222,45,75,54,34,44,33,22,11,66,0};
    long menor;
    char i;
    
    menor=datos[0];
    for(i=1;datos[i]!=0;i++){
        if(datos[i]<menor)
        menor=datos[i];
    }
    
    return (menor);
}
