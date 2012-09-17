/* 
 * File:   main.cpp
 * Author: radigue
 *
 * Created on 14 septembre 2012, 09:42
 */

#include <cstdlib>
#include <iostream>
#include <sys/types.h>  
#include <unistd.h>  
#include <stdio.h>
#include <sys/wait.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int iChoice = 0;
    cout << "Menu :" << endl << "1.Branches" << endl << "2.Suite" << endl << "3.Arborescence" << endl;
    cout << "Choix : ";
    cin >> iChoice;
    switch (iChoice) {
        //Cas arbre avec branche
        case 1:
        {
            cout << "Nombre de Branches ?" << endl;
            int iNombreBranche = 0, etat = 0, pid;
            cin >> iNombreBranche;
            bool bPereMarque = false;
            for (int i = 0; i < iNombreBranche; i++) {
                pid = fork();
                if (!pid) {
                    cout << "Fils " << i + 1 << " " << getpid() << " " << getppid() << endl;
                    sleep(2);
                    exit(0);
                }
                else
                    if (!bPereMarque) {
                    cout << "Père " << getpid() << endl;
                    bPereMarque = !bPereMarque;
                }
            }
            for (int i = 0; i < iNombreBranche; i++)wait(NULL);
            break;
        }
        //Cas de suite p->f->f->f
        case 2:
        {
            int iNombreSuite = 0;
            cout << "Nombre de suite ?" << endl;
            cin >> iNombreSuite;
            cout << "Père " << getpid() << endl;
            for(int i=0; i<iNombreSuite;i++){
                if(!fork()){
                    cout << "Fils " << i+1 << " " <<getpid() << " " << getppid() << endl;
                }
                else{
                    wait(NULL);
                    exit(0);
                }
            }
            break;
        }
        //Cas arborescence
        case 3:
        {
            int iNombreLigne = 0, pid=0;
            cout << "Nombre de ligne ?" << endl;
            cin >> iNombreLigne;
            for(int i=0; i<iNombreLigne;i++)
            {
                if(!fork()){
                    cout << "Fils " << i+1 << " " <<getpid() << " " << getppid() << endl;
                }
                else{
                    wait(NULL);
                }
            }
            break;
        }
        default:
            cout << "Mauvais choix !" << endl;
    }
    cout << "FIN" << endl;
    return 0;
}