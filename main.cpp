#include <iostream>
#include <string>
#include <fstream>

#include "Angajat.h"

using namespace std;

void SortareDataNastere(Angajat *, const int &);
void swap_a(Angajat &, Angajat &);
int NumarDeAngajati(Angajat *vec, const int dim);

int main()
{
    // 1.
    // Angajat a;
    // cin >> a;
    // if(a.ePart_time() == 1) {
    //     cout << a << "-> Lucreaza Part_Time";
    // }
    // else {
    //     cout << a << "-> Nu lucreaza Part_Time";
    // }

    // 2.
    int dim;
    cout << "Dimensiune vector: ";
    cin >> dim;

    Angajat *vec = new Angajat[dim];
    // for(int i = 0; i < dim; i++) {
    //     cin>>vec[i];
    // }

    // fstream file("angajati.txt", ios::out);
    // for(int i = 0; i < dim; i++) {
    //     file << vec[i];
    // }

    // file.close();
    // redeschidere fisier sau variabila noua

    // 3.
    fstream file_in("angajati.txt", ios::in);
    for(int i = 0; i < dim; i++) {
        file_in >> vec[i];
    }

    cout<<"\nAngajati Full-Time:\n";
    for(int i = 0; i < dim; i++) {
        if(vec[i].ePart_time() == false) {
            cout<<vec[i];
        }
    }    

    // 4. - done

    // 5.
    SortareDataNastere(vec, dim);
    cout << "\nVector sortat - Data de Nastere:\n";
    for(int i = 0; i < dim; i++) {
            cout<<vec[i];
    }   

    // 6.
    cout << "\nSunt " << NumarDeAngajati(vec, dim) << " angajati care au mai multe prenume [scrisi in prenume.txt]";

    return 0;
}

// 2000+
void SortareDataNastere(Angajat *vec, const int &dim) {
    for(int i = 0; i < dim; i++) {
        for(int j = 0; j < dim; j++){
            string CNPi = vec[i].getCNP();
            int ani = stoi(CNPi.substr(1, 2));
            int lunai = stoi(CNPi.substr(3, 2));
            int ziuai = stoi(CNPi.substr(5, 2));
            string CNPj = vec[j].getCNP();
            int anj = stoi(CNPj.substr(1, 2));
            int lunaj = stoi(CNPj.substr(3, 2));
            int ziuaj = stoi(CNPj.substr(5, 2));

            if(CNPi[0] == '1' || CNPi[0] == '2')
                ani = ani + 1900;
            else 
                ani = ani + 2000;
            
            if(CNPj[0] == '1' || CNPj[0] == '2')
                anj = anj + 1900;
            else 
                anj = anj + 2000;

            int datai = ani * 360 + lunai * 30 + ziuai;
            int dataj = anj * 360 + lunaj * 30 + ziuaj;

            if(datai < dataj) {
                swap_a(vec[i], vec[j]);
            }
        }
    }
}

// Functii:

void swap_a(Angajat &a, Angajat &b) {
    Angajat temp = a;
    a = b;
    b = temp;
}

int NumarDeAngajati(Angajat *vec, const int dim) {
    int nr = 0;
    fstream file("prenume.txt", ios::out);

    for(int i = 0; i < dim; i++) {
        if(vec[i].getCatePrenume() > 1) {
            file << vec[i];
            nr ++;
        }
    }
    // se inchide automat
    return nr;
}