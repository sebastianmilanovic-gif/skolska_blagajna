
#include <cstdio>
using namespace std;

     //Globalne konstante
const double CIJENA_ULAZNICE = 5.0;
const int PRAG_POPUSTA = 5;
const double STOPA_POPUSTA = 0.10;

     //Globalne varijable
int ukupnoUlaznica = 0;
double ukupniPrihod = 0;

     //Deklaracije funkcija
bool ispravanUnos(int kolicina);
double izracunajIznos(int kolicina);
void evidentirajKupnju(int kolicina, double iznos);
void ispisiKupnju(int redniBroj, double iznos);
void ispisiSazetak();

int main() {
    for (int i = 1; i <= 3; i++) {
        int kolicina;
        double iznos;

        do {
            printf("Kupnja %d, unesi broj ulaznica (1-30) ", i);
            scanf("%d", &kolicina);

            if (!ispravanUnos(kolicina))
                printf("Neispravan unos\n");
                }
        while (!ispravanUnos(kolicina));

        iznos = izracunajIznos(kolicina);
        evidentirajKupnju(kolicina, iznos);
        ispisiKupnju(i, iznos);
    }

    ispisiSazetak();

    return 0;
}

     //Definicije funkcija
bool ispravanUnos(int kolicina) {
    return kolicina >= 1 && kolicina <= 30;
}

double izracunajIznos(int kolicina) {
    double osnovniIznos = kolicina * CIJENA_ULAZNICE;
    double konacniIznos = osnovniIznos;

    if (kolicina >= PRAG_POPUSTA)
        konacniIznos = osnovniIznos * (1 - STOPA_POPUSTA);

    return konacniIznos;
}

void evidentirajKupnju(int kolicina, double iznos) {
    ukupnoUlaznica = ukupnoUlaznica + kolicina;
    ukupniPrihod = ukupniPrihod + iznos;
}

void ispisiKupnju(int redniBroj, double iznos) {
    printf("Kupnja %d: %.2f EUR\n", redniBroj, iznos);
}

void ispisiSazetak() {
    printf("Ukupno prodanih ulaznica: %d\n", ukupnoUlaznica);
    printf("Ukupni prihod: %.2f EUR\n", ukupniPrihod);
}
