#ifndef KONYV_H
#define KONYV_H
#include <string>


class Konyv
{
    private:
        std::string cim;
        std::string szerzo;
        int kiadas_eve;
        int kod;
    public:
        void set_cim(std::string cim);
        void set_szerzo(std::string szerzo);
        void set_kiadas_eve(int kiadas_eve);
        void set_kod(int kod);

        std::string get_cim(){return cim;}
        std::string get_szerzo(){return szerzo;}
        int get_kiadas_eve(){return kiadas_eve;}
        int get_kod(){return kod;}
};

void Konyv::set_cim(std::string cim){
    this->cim = cim;
}

void Konyv::set_szerzo(std::string szerzo){
    this->szerzo = szerzo;
}

void Konyv::set_kiadas_eve(int kiadas_eve){
    this->kiadas_eve = kiadas_eve;
}

void Konyv::set_kod(int kod){
    this->kod = kod;
}

#endif