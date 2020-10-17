#include <iostream>
#include <math.h>
using namespace std;
void lanzamientoEnemigo(float *punto, float Voy, float Vox,float g, float *tfinal);
void lanzamientoDefensa(float *punto, float Voy, float Vox, float angulo, float g, float *tfinal, float *puntoD);
void infoImpactoCaso1(float Xini, float Yini, float Voy, float Vox, float angulo);
int main()
{   float g=9.81;
    float Ho=0;
    cout << "-------informacion de infiltrado----------"<< endl;
    cout << "ingrese altura del cañon desde el suelo: " << endl;
    cin >>Ho;
    float Oangulo=0;
    cout << "ingrese el angulo de lanzamiento: "<< endl;
    cin >>Oangulo;
    float Ovo=0;
    cout << "ingrese la velocidad inicial de lanzamiento: "<< endl;
    cin >> Ovo;
    float Ovox=Ovo*cos(Oangulo);
    float Ovoy=Ovo*sin(Oangulo);
    float punto[2]={0,Ho};//valor inicial de la posición del proyectil enemigo
    float tfinal=0;


     cout << "---------informacion de defensa--------------------"<< endl;
     float Hd=0;
     cout << "ingrese la altura desde el cañon del suelo" << endl;
     cin >> Hd;

     float Dangulo=0;
     cout << "ingrese el angulo desde el lanzamiento: "<< endl;
     cin >> Dangulo;
     float Dvo=0;
     cout << "ingrese la velocidad inicial del lanzamiento: "<< endl;

    lanzamientoEnemigo(&punto[0], Ovoy, Ovox, g, &tfinal);


    return 0;





}
void lanzamientoEnemigo(float *punto, float Voy, float Vox,float angulo, float g, float *tfinal, float *puntoD){

    float Vy=Voy;//Velocidad inicial y
    float Vx=Vox;
    float Y=0;
    float X=0;

    float Yini=*punto;
    float Xini=*(punto+1);
    float t=0;
    while(Y>=0){//Mientras Y sea mayor a 0 es decir no este tocando el suelo

        Y=*(punto+1)+(Vy*t)-((1/2)*g*(pow(t,2)));//Posición en Y
        Vy=Vy-(g*t);//Velocidad Y
        //cout<<Vy<<endl;

        X=*(punto)+(Vx*t);//Posicion en X

        if (X<=*puntoD + 0.05 && Y<=*(puntoD+1) + 0.05){

            cout<<"Impacto"<<endl;
            cout<<"CASO1"<<endl;
            infoImpactoCaso1(Xini, Yini, Voy, Vox, angulo);
            break;

        }else{

            *punto=X;
            *(punto+1)=Y;

            //cout<<X<<" "<<Y<<endl;
            t+=0.0001;
            *tfinal=t;
        }


    }
    }
void infoImpactoCaso1(float Xini, float Yini, float Voy, float Vox, float angulo){

    float Vinicial=sqrt(pow(Voy,2)+ pow(Vox,2));
    cout<<"Punto inciail: x: "<<Xini<<" y: "<<Yini<<" Velocidad inicial: "<<Vinicial<<" Angulo de lanzamiento: "<<angulo<<endl;
}


void lanzamientoDefensa(float *punto, float Voy, float Vox, float angulo, float g, float *tfinal, float *puntoD){

            float Vy=Voy;//Velocidad inicial y
            float Vx=Vox;
            float Y=0;
            float X=0;

            float Yini=*punto;
            float Xini=*(punto+1);

            float t=0;
            while(Y>=0){//Mientras Y sea mayor a 0 es decir no este tocando el suelo

                Y=*(punto+1)+(Vy*t)-((1/2)*g*(pow(t,2)));//Posición en Y
                Vy=Vy-(g*t);//Velocidad Y
                cout<<Vy<<endl;

                X=-*(punto)+(Vx*t);//Posicion en X

                if (X<=*puntoD + 0.05 && Y<=*(puntoD+1) + 0.05){

                    cout<<"Impacto"<<endl;
                    infoImpactoCaso1(Xini, Yini, Voy, Vox, angulo);
                    break;

                }else{

                    *punto=X;
                    *(punto+1)=Y;

                    //cout<<X<<" "<<Y<<endl;
                    t-=0.0001;
                    *tfinal=t;
                }


            }

        }
