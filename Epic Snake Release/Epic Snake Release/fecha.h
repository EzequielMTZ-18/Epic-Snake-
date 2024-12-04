#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
/*
class Fecha{
   private:
       int Dia;
       int Mes;
       int Anio;

   public:

        Fecha(int d=0,int m=0,int a=0){
        Dia=d;
        Mes=m;
        Anio=a;
        }

       int Cargar();
       void Mostrar();
       ///sets
       void setDia(int d){
         Dia=d;
       }
       void setMes(int m){
         Mes=m;
         }
       void setAnio(int a){
         Anio=a;
         }
       ///gets
       int getDia(){return Dia;}
       int getMes(){return Mes;}
       int getAnio(){return Anio;}
       bool fechavalida(int dia,int mes,int anio);



};

bool FechaActual(Fecha obj){
        time_t t;
        struct tm *fecha;
        t=time(NULL);
        fecha=localtime(&t);
        int AnioActual=fecha->tm_year+1900;
        int MesActual=fecha->tm_mon+1;
        int DiaActual=fecha->tm_mday;
        if(obj.getAnio()>=AnioActual){
                if(obj.getMes()>=MesActual){
                    if(obj.getDia()>=DiaActual){
                        return false;
                    }
                }

        }
        return true;

}




bool Fecha::fechavalida(int dia,int mes,int anio){
       Fecha obj;
       bool valido;
       //int AnioActual=2022;
       if(dia<1||dia>31)return false;
       if(mes>12)return false;
       else switch(mes)
        {
        case 4: case 6: case 9: case 11:
            if(dia>30)return false;
            break;
        case 2:
            if(dia>28)return false;
            break;
        }
        obj.setDia(dia);
        obj.setMes(mes);
        obj.setAnio(anio);
        valido=FechaActual(obj);

        //if(anio>AnioActual)return false;
        //if(anio<AnioActual)return true;
        return valido;

}

int Fecha::Cargar(){
    int d,m,a;
    cout<<endl;
    cout<<"DIA: ";
    cin>>d;
    setDia(d);
    cout<<"MES: ";
    cin>>m;
    setMes(m);
    cout<<"ANO: ";
    cin>>a;
    setAnio(a);
    if(fechavalida(Dia,Mes,Anio)==false){
        return -1;
    }
    return 0;
}

void Fecha::Mostrar(){
     cout<<Dia<<"/"<<Mes<<"/"<<Anio<<endl;

}
*/
#endif // FECHA_H_INCLUDED
