#include <iostream>
#include <math.h>
using namespace std;
void lanzamientoEnemigo(float *punto, float Voy, float Vox,float g, float *tfinal);

int main()
{   float g=9.81;
    float Ho=0;
    cout << "-------informacion de infiltrado----------"<< endl;
    cout << "ingrese altura del cañon desde el suelo: " << endl;
    cin >>Ho;
    float Oangulo=0;
    cout << "ingrese el angulo de lanzamiento: "<< endl;
    cin >>Oangulo;
    float Ovo;
    cout << "ingrese la velocidad inicial de lanzamiento: "<< endl;
    cin >> Ovo;
    float Ovox=Ovo*cos(Oangulo);
    float Ovoy=Ovo*sin(Oangulo);
    float punto[2]={0,Ho};//valor inicial de la posición del proyectil enemigo
    float tfinal=0;







}
void lanzamientoEnemigo(float *punto, float Voy, float Vox,float g, float *tfinal){

    float Vy=Voy;//Velocidad inicial y
    float Vx=Vox;
    float Y=0;
    float X=0;

    float t=0;
    while(Vy>0){

        Y=*(punto+1)+(Vy*t)-((1/2)*g*(pow(t,2)));
        Vy=Vy-(g*t);
        cout<<t<<endl;

        X=*(punto)+(Vx*t);


        *punto=X;
        *(punto+1)=Y;

        cout<<X<<" "<<Y<<endl;
        t+=0.01;
        *tfinal=t;
    }


}

