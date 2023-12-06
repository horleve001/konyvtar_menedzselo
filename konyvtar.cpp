#include <iostream>
#include "konyv.h"

int szam_check();
void options(int option, int *p, Konyv konyv[]);
void konyv_felvet(int *p, Konyv konyv[]);
void konyv_listazas(int *p, Konyv konyv[]);
void konyv_kereses(int *p, Konyv konyv[]);
void konyv_torles(int *p, Konyv konyv[]);
void konyv_szerkesztes(int *p, Konyv konyv[]);
void adat_szerkeszt(int *p, int y,Konyv konyv[]);


int main(){
    int opcio = 0;
    int counter = 0;
    int *counter_ptr = &counter;
    Konyv konyv[100];

    do{
        std::cout << "Konyvtar Program" << std::endl << std::endl;
        std::cout << "1. Konyv felvetele" << std::endl;
        std::cout << "2. Konyv listazasa" << std::endl;
        std::cout << "3. Konyv keresese" << std::endl;
        std::cout << "4. Konyv torlese" << std::endl;
        std::cout << "5. Konyv szerkesztese" << std::endl;
        std::cout << "0. Kilepes" << std::endl;
        std::cout << "Kerem valasszon: ";

        opcio = szam_check();
        options(opcio, counter_ptr,konyv);

    } while (opcio != 0);

    return 0;
}

void options(int option, int *p, Konyv konyv[]){
    
    switch(option){
        case 1:
            system("CLS");
            if(*p == 100){
                std::cout << "A konyvtar tele van!" << std::endl;
                break;
            }
            konyv_felvet(p, konyv);
            break;
        case 2:
            system("CLS");
            konyv_listazas(p, konyv);
            break;
        case 3:
            system("CLS");
            konyv_kereses(p, konyv);
            break;
        case 4:
            system("CLS");
            konyv_torles(p, konyv);
            break;
        case 5:
            system("CLS");
            konyv_szerkesztes(p, konyv);
            break;
        case 0:
            std::cout << "Viszont latasra!" << std::endl;
            break;
        default:
            std::cout << "Nincs ilyen opcio!" << std::endl;
            break;
    }
}

int szam_check(){
    int szam;
    std::cin >> szam;

    while (std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Kerem szamot adjon meg!" << std::endl;
        std::cin >> szam;
    }
    return szam;
}

void konyv_felvet(int *p, Konyv konyv[]){
    std::string cim, szerzo;
    int kiadas_eve, kod;

    std::cout << "Konyv felvetele" << std::endl << std::endl;
    std::cout << "Konyv cime: ";
    std::cin.ignore();
    std::getline(std::cin, cim);
    std::cout << "Konyv szerzoje: ";
    std::getline(std::cin, szerzo);
    std::cout << "Konyv kiadasanak eve: ";
    kiadas_eve = szam_check();
    std::cout << "Konyv kodja: ";
    kod = szam_check();
    konyv[*p].set_cim(cim);
    konyv[*p].set_szerzo(szerzo);
    konyv[*p].set_kiadas_eve(kiadas_eve);
    konyv[*p].set_kod(kod);
    *p = *p + 1;
    std::cout << "Konyv felveve!" << std::endl;
    system("PAUSE");
    system("CLS");
}

void konyv_listazas(int *p, Konyv konyv[]){
    std::cout << "Konyv listazasa" << std::endl << std::endl;
    if(*p == 0){
        std::cout << "Nincs konyv a konyvtarban!" << std::endl;
    }
    else{
        for (int i = 0; i < *p; i++){
            std::cout << "Konyv cime: " << konyv[i].get_cim() << std::endl;
            std::cout << "Konyv szerzoje: " << konyv[i].get_szerzo() << std::endl;
            std::cout << "Konyv kiadasanak eve: " << konyv[i].get_kiadas_eve() << std::endl;
            std::cout << "Konyv kodja: " << konyv[i].get_kod() << std::endl << std::endl;
        }
    }
    system("PAUSE");
    system("CLS");
}

void konyv_kereses(int *p, Konyv konyv[]){
    std::cout << "Konyv keresese" << std::endl << std::endl;
    if(*p == 0){
        std::cout << "Nincs konyv a konyvtarban!" << std::endl;
    }
    else{
        std::string cim, szerzo;
        int kiadas_eve, kod;
        std::cout << "Mi alapjan szeretne keresni?" << std::endl;
        std::cout << "1. Cim" << std::endl;
        std::cout << "2. Szerzo" << std::endl;
        std::cout << "3. Kiadas eve" << std::endl;
        std::cout << "4. Kod" << std::endl;
        std::cout << "Kerem valasszon: ";
        int opcio = szam_check();
        switch(opcio){
            case 1:
                std::cout << "Kerem adja meg a konyv cimet: ";
                std::cin.ignore();
                std::getline(std::cin, cim);
                for (int i = 0; i < *p; i++){
                    if(cim == konyv[i].get_cim()){
                        system("CLS");
                        std::cout << "Konyv cime: " << konyv[i].get_cim() << std::endl;
                        std::cout << "Konyv szerzoje: " << konyv[i].get_szerzo() << std::endl;
                        std::cout << "Konyv kiadasanak eve: " << konyv[i].get_kiadas_eve() << std::endl;
                        std::cout << "Konyv kodja: " << konyv[i].get_kod() << std::endl << std::endl;
                    }
                    else{
                        std::cout << "Nincs ilyen konyv!" << std::endl;
                    }
                }
                break;
            case 2:
                std::cout << "Kerem adja meg a konyv szerzojet: ";
                std::cin.ignore();
                std::getline(std::cin, szerzo);
                for (int i = 0; i < *p; i++){
                    if(szerzo == konyv[i].get_szerzo()){
                        system("CLS");
                        std::cout << "Konyv cime: " << konyv[i].get_cim() << std::endl;
                        std::cout << "Konyv szerzoje: " << konyv[i].get_szerzo() << std::endl;
                        std::cout << "Konyv kiadasanak eve: " << konyv[i].get_kiadas_eve() << std::endl;
                        std::cout << "Konyv kodja: " << konyv[i].get_kod() << std::endl << std::endl;
                    }
                    else{
                        std::cout << "Nincs ilyen konyv!" << std::endl;
                    }
                }
                break;
            case 3:
                std::cout << "Kerem adja meg a konyv kiadasanak evet: ";
                kiadas_eve = szam_check();
                for (int i = 0; i < *p; i++){
                    if(kiadas_eve == konyv[i].get_kiadas_eve()){
                        system("CLS");
                        std::cout << "Konyv cime: " << konyv[i].get_cim() << std::endl;
                        std::cout << "Konyv szerzoje: " << konyv[i].get_szerzo() << std::endl;
                        std::cout << "Konyv kiadasanak eve: " << konyv[i].get_kiadas_eve() << std::endl;
                        std::cout << "Konyv kodja: " << konyv[i].get_kod() << std::endl << std::endl;
                    }
                    else{
                        std::cout << "Nincs ilyen konyv!" << std::endl;
                    }
                }
                break;
            case 4:
                std::cout << "Kerem adja meg a konyv kodjat: ";
                kod = szam_check();
                for (int i = 0; i < *p; i++){
                    if(kod == konyv[i].get_kod()){
                        system("CLS");
                        std::cout << "Konyv cime: " << konyv[i].get_cim() << std::endl;
                        std::cout << "Konyv szerzoje: " << konyv[i].get_szerzo() << std::endl;
                        std::cout << "Konyv kiadasanak eve: " << konyv[i].get_kiadas_eve() << std::endl;
                        std::cout << "Konyv kodja: " << konyv[i].get_kod() << std::endl << std::endl;
                    }
                    else{
                        std::cout << "Nincs ilyen konyv!" << std::endl;
                    }
                }
                break;
            default:
                std::cout << "Nincs ilyen opcio!" << std::endl;
                break;
        }
    }
    system("PAUSE");
    system("CLS");
}

void konyv_torles(int *p, Konyv konyv[]){
    std::cout << "Konyv torlese" << std::endl << std::endl;
    if(*p == 0){
        std::cout << "Nincs konyv a konyvtarban!" << std::endl;
    }
    else{
        std::string cim, szerzo;
        int kiadas_eve, kod;
        std::cout << "Mi alapjan szeretne torolni?" << std::endl;
        std::cout << "1. Cim" << std::endl;
        std::cout << "2. Szerzo" << std::endl;
        std::cout << "3. Kiadas eve" << std::endl;
        std::cout << "4. Kod" << std::endl;
        std::cout << "Kerem valasszon: ";
        int opcio = szam_check();
        switch(opcio){
            case 1:
                std::cout << "Kerem adja meg a konyv cimet: ";
                std::cin.ignore();
                std::getline(std::cin, cim);
                for (int i = 0; i < *p; i++){
                    if(cim == konyv[i].get_cim()){
                        for (int j = i; j < *p; j++){
                            konyv[j] = konyv[j+1];
                        }
                        konyv[*p].set_cim("");
                        konyv[*p].set_szerzo("");
                        konyv[*p].set_kiadas_eve(0);
                        konyv[*p].set_kod(0);
                        *p = *p - 1;
                        system("CLS");
                        std::cout << "Konyv torolve!" << std::endl;
                    }
                    else{
                        std::cout << "Nincs ilyen konyv!" << std::endl;
                    }
                }
                break;
            case 2:
                std::cout << "Kerem adja meg a konyv szerzojet: ";
                std::cin.ignore();
                std::getline(std::cin, szerzo);
                for (int i = 0; i < *p; i++){
                    if(szerzo == konyv[i].get_szerzo()){
                        for (int j = i; j < *p; j++){
                            konyv[j] = konyv[j+1];
                        }
                        konyv[*p].set_cim("");
                        konyv[*p].set_szerzo("");
                        konyv[*p].set_kiadas_eve(0);
                        konyv[*p].set_kod(0);
                        *p = *p - 1;
                        system("CLS");
                        std::cout << "Konyv torolve!" << std::endl;
                    }
                }
                break;
            case 3:
                std::cout << "Kerem adja meg a konyv kiadasanak evet: ";
                kiadas_eve = szam_check();
                for (int i = 0; i < *p; i++){
                    if(kiadas_eve == konyv[i].get_kiadas_eve()){
                        for (int j = i; j < *p; j++){
                            konyv[j] = konyv[j+1];
                        }
                        konyv[*p].set_cim("");
                        konyv[*p].set_szerzo("");
                        konyv[*p].set_kiadas_eve(0);
                        konyv[*p].set_kod(0);
                        *p = *p - 1;
                        system("CLS");
                        std::cout << "Konyv torolve!" << std::endl;
                    }
                }
                break;
            case 4:
                std::cout << "Kerem adja meg a konyv kodjat: ";
                kod = szam_check();
                for (int i = 0; i < *p; i++){
                    if(kod == konyv[i].get_kod()){
                        for (int j = i; j < *p; j++){
                            konyv[j] = konyv[j+1];
                        }
                        konyv[*p].set_cim("");
                        konyv[*p].set_szerzo("");
                        konyv[*p].set_kiadas_eve(0);
                        konyv[*p].set_kod(0);
                        *p = *p - 1;
                        system("CLS");
                        std::cout << "Konyv torolve!" << std::endl;
                    }
                }
                break;
            default:
                std::cout << "Nincs ilyen opcio!" << std::endl;
                break;
        }
    }
}

void konyv_szerkesztes(int *p, Konyv konyv[]){
    std::cout << "Konyv szerkesztese" << std::endl << std::endl;
    if(*p == 0){
        std::cout << "Nincs konyv a konyvtarban!" << std::endl;
    }
    else{
        std::string cim, szerzo;
        int kiadas_eve, kod;
        std::cout << "Mi alapjan szeretne szerkeszteni?" << std::endl;
        std::cout << "1. Cim" << std::endl;
        std::cout << "2. Szerzo" << std::endl;
        std::cout << "3. Kiadas eve" << std::endl;
        std::cout << "4. Kod" << std::endl;
        std::cout << "Kerem valasszon: ";
        int opcio = szam_check();
        switch(opcio){
            case 1:
                std::cout << "Kerem adja meg a konyv cimet: ";
                std::cin.ignore();
                std::getline(std::cin, cim);
                for (int i = 0; i < *p; i++)
                {
                    if(cim == konyv[i].get_cim()){
                        adat_szerkeszt(p, i, konyv);
                    }
                    else{
                        std::cout << "Nincs ilyen konyv!" << std::endl;
                    }
                }
                break;
            case 2:
                std::cout << "Kerem adja meg a konyv szerzo: ";
                std::cin.ignore();
                std::getline(std::cin, szerzo);
                for (int i = 0; i < *p; i++)
                {
                    if(szerzo == konyv[i].get_szerzo()){
                        adat_szerkeszt(p, i, konyv);
                    }
                    else{
                        std::cout << "Nincs ilyen konyv!" << std::endl;
                    }
                }
                break;
            case 3:
                std::cout << "Kerem adja meg a konyv kiadasanak evet: ";
                kiadas_eve = szam_check();
                for (int i = 0; i < *p; i++)
                {
                    if(kiadas_eve == konyv[i].get_kiadas_eve()){
                        adat_szerkeszt(p, i, konyv);
                    }
                    else{
                        std::cout << "Nincs ilyen konyv!" << std::endl;
                    }
                }
                break;
            case 4:
                std::cout << "Kerem adja meg a konyv kodjat: ";
                kod = szam_check();
                for (int i = 0; i < *p; i++)
                {
                    if(kod == konyv[i].get_kod()){
                        adat_szerkeszt(p, i, konyv);
                    }
                    else{
                        std::cout << "Nincs ilyen konyv!" << std::endl;
                    }
                }
                break;
            default:
                std::cout << "Nincs ilyen opcio!" << std::endl;
                break;
        }
    }
}

void adat_szerkeszt(int *p, int y,Konyv konyv[]){
    system("CLS");
    std::string cim, szerzo;
    int kiadas_eve, kod;
    int opcio = 0;
    std::cout << "Mit szeretne szerkeszteni?" << std::endl;
    std::cout << "1. Cim" << std::endl;
    std::cout << "2. Szerzo" << std::endl;
    std::cout << "3. Kiadas eve" << std::endl;
    std::cout << "4. Kod" << std::endl;
    std::cout << "Kerem valasszon: ";
    opcio = szam_check();

    switch(opcio){
        case 1:
            std::cout << "Kerem adja meg a konyv uj cimet: ";
            std::cin.ignore();
            std::getline(std::cin, cim);
            konyv[y].set_cim(cim);
            system("CLS");
            std::cout << "Konyv cime modositva!" << std::endl;
            break;

        case 2:
            std::cout << "Kerem adja meg a konyv uj szerzojet: ";
            std::cin.ignore();
            std::getline(std::cin, szerzo);
            konyv[y].set_szerzo(szerzo);
            system("CLS");
            std::cout << "Konyv szerzoje modositva!" << std::endl;
            break;

        case 3:
            std::cout << "Kerem adja meg a konyv uj kiadasanak evet: ";
            kiadas_eve = szam_check();
            konyv[y].set_kiadas_eve(kiadas_eve);
            system("CLS");
            std::cout << "Konyv kiadasanak eve modositva!" << std::endl;
            break;

        case 4:
            std::cout << "Kerem adja meg a konyv uj kodjat: ";
            kod = szam_check();
            int i;
            for (i = 0; i < *p; i++){
                if(kod == konyv[i].get_kod()){
                    std::cout << "Ilyen koddal mar van konyv!" << std::endl;
                    break;
                }
            }
            if(!(kod == konyv[i].get_kod())){
                konyv[y].set_kod(kod);
                system("CLS");
                std::cout << "Konyv kodja modositva!" << std::endl;
            }
            break;

        default:
            std::cout << "Nincs ilyen opcio!" << std::endl;
            break;
    }
}
