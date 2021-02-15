int minimo(int a, int b){
    if(a<b){
        return a;
    }else{
        return b;
    }





}

int maximo(int a, int b){
    if(a<b){
        return b;
    }else{
        return a;
    }





}







int mcd(int a, int b){

    int i;
    int Num=1;
    for(i=1;i<=minimo(a,b);i++){
        if(a%i==0 && b%i==0){
            Num=i;
        }
    }
    return Num;

}

int mcm(int a, int b){

    int i;
    int Num=1;
    for(i=(a*b);i>=maximo(a,b);i--){
        if(i%a==0 && i%b==0){
            Num=i;
        }
    }
    return Num;

}


