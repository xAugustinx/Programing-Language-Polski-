#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>

#define iloscZnakowWPoleceniu sizeof(polecenie)/sizeof(polecenie[0])

int znakCalkowity = 0;
//int tablicaIlosciZnakow[10];
int dlugosc;
int iloscLini = 0;
int boolCzyDanaFunkcja = 1;

char znak;
char plikZmiennych[] = "pz";

char napisz[] = "napisz";
char koniec[] = "koniec";
char spij[] = "śpij";
char liczbaCalkowita[] = "liczbaCałkowita";
char pZmiennych[] = "#pZmiennych";

void porownywanieTablic(char meow[],char Nigga[],int sizeFirst, int sizeSecond) {
    boolCzyDanaFunkcja = 1;
    if (sizeFirst >= sizeSecond   -1) {
        for (int i = 0; i < sizeSecond-2; i++) {
            if (meow[i] != Nigga[i]) {
                boolCzyDanaFunkcja = 0;
                break;
            }
        }
    }
}

int main() {
    // printf("####################################################################\n");
    // printf("##################### Polski++ Aplpha 0.02 ##### ###################\n");
    // printf("####################################################################\n");
    // printf("##### ,,A niechaj narodowie wżdy postronni znają, ################# \n");
    // printf("####### iż Polacy nie gęsi, iż swój język mają'' - Mikołaj Rej #### \n");
    // printf("####################################################################\n");

    FILE *plik = fopen("plik.pl","r");
    fseek(plik, 0, 0);

    fseek(plik, 0, SEEK_END);

    dlugosc = ftell(plik);

    char fajnyZnak;
    for  (int i = 0; i < dlugosc; i++ )
    {
        fseek(plik, i, SEEK_SET);
        fscanf(plik, "%c", &fajnyZnak);
        if (fajnyZnak == '\n') {
            iloscLini++;
        }
    }

    fseek(plik, 0, 0);

    while (1)
    {

        int iloscZnakowWPetli = 0;

        while (1) {
            fseek(plik, znakCalkowity, 0);
            fscanf(plik,"%c",&znak);

            iloscZnakowWPetli++;
            znakCalkowity++;
            if (znak == ';') {
                break;
            }
        }

        char polecenie[iloscZnakowWPetli];

        for (int i = 0; i < iloscZnakowWPetli; i++)
        {
            fseek(plik,znakCalkowity-i-1,0);
            fscanf(plik,"%c",&polecenie[i]);
            if (polecenie[i] == '\n') {
                break;
            }
        }

        int licznikFajny = sizeof(polecenie) / sizeof(polecenie[0]);
        for (int i = 0; i < sizeof(polecenie) / sizeof(polecenie[0]) /2; i++) {
            znak = polecenie[i];
            polecenie[i] = polecenie[licznikFajny-1];
            polecenie[licznikFajny-1] = znak;
            licznikFajny--;
        }


        //sprawdzanie czy funkcja to napisz
        porownywanieTablic(polecenie,napisz,sizeof(polecenie)/sizeof(polecenie[0]),sizeof(napisz)/sizeof(napisz[0])  );
        int czyZnalazloSieOtwarcie = 0;
        int czyWypisywacBool = 0;


        if (boolCzyDanaFunkcja) {
            for (int i = znakCalkowity - iloscZnakowWPetli; i < znakCalkowity; i++) {
                fseek(plik, i, 0);
                fscanf(plik,"%c",&znak);
                if (znak == '(') {
                    czyZnalazloSieOtwarcie = 1;
                }
                else if (znak == ')') {
                    break;
                }


                if (czyWypisywacBool && czyZnalazloSieOtwarcie && znak != '"')
                {
                    printf("%c", znak);
                }

                if (znak == '"') {
                    if (czyWypisywacBool) {
                        czyWypisywacBool = 0;
                    }
                    else {
                        czyWypisywacBool = 1;
                    }
                }
            }
        }
        //koniec sprawdzania czy to funkcja napisz
        //funkcja koniec
        porownywanieTablic(polecenie,koniec,sizeof(polecenie)/sizeof(polecenie[0]),sizeof(koniec)/sizeof(koniec[0]) );
        if (boolCzyDanaFunkcja) {
            break;
        }
        boolCzyDanaFunkcja = 0;

        //spanie
        porownywanieTablic(polecenie,spij,sizeof(polecenie)/sizeof(polecenie[0]),sizeof(spij)/sizeof(spij[0]) );

        if (boolCzyDanaFunkcja) {
            int czyNawias = 0;
            int iloscLiczbWNawiasie = 0;
            int punktZaczeciaSieLiczb;
            int czyLiczbaZmiennoPrzecinkowa = 0;
            int lokalizacjaLiczbPoPrzecinka = -1;

            for (int i = znakCalkowity - iloscZnakowWPetli; i < znakCalkowity; i++) {
                fseek(plik, i, 0);
                fscanf(plik,"%c",&znak);

                if (znak == ')') {
                    czyNawias = 0;
                    break;
                }
                else if (czyNawias) {
                    iloscLiczbWNawiasie++;
                    if (znak == ',') {
                        //czyLiczbaZmiennoPrzecinkowa = 1;
                        lokalizacjaLiczbPoPrzecinka = i + 1;
                    }
                }

                if (znak == '(' ) {
                    czyNawias = 1;
                    punktZaczeciaSieLiczb = i + 1;
                }
            }

            int wartoscOstateczna;

            if (lokalizacjaLiczbPoPrzecinka == -1)
            {
                int licznikDodatkowy = 0;
                fseek(plik, punktZaczeciaSieLiczb, 0);
                fscanf(plik,"%d",&wartoscOstateczna);
                sleep(wartoscOstateczna);
            }
            else {
                int przedPrzecinkiem;
                fseek(plik, punktZaczeciaSieLiczb, 0);
                fscanf(plik,"%d",&przedPrzecinkiem);
                int poPrzecinku;
                fseek(plik, lokalizacjaLiczbPoPrzecinka, 0);
                fscanf(plik,"%d",&poPrzecinku);
                double poPrzecinkuTylkoZeDouble = poPrzecinku;
                while (1)
                {
                    if (poPrzecinkuTylkoZeDouble < 1)
                    {
                        break;
                    }
                    poPrzecinkuTylkoZeDouble = poPrzecinkuTylkoZeDouble / 10;
                }
                double jednolitaLiczba = poPrzecinkuTylkoZeDouble + przedPrzecinkiem;
                usleep(jednolitaLiczba * 1000000);

            }
        }
        //deklarowanie intów


        boolCzyDanaFunkcja = 0;
        porownywanieTablic(polecenie,liczbaCalkowita,iloscZnakowWPoleceniu,sizeof(liczbaCalkowita)/sizeof(liczbaCalkowita[0]) );
        if (boolCzyDanaFunkcja) {

            if (polecenie[ sizeof(liczbaCalkowita)/sizeof(liczbaCalkowita[0]) ] == 'n' ) {
                FILE *zmienne = fopen(plikZmiennych,"a");
                fprintf(zmienne,"%s","\nint");

                for (int i = sizeof(liczbaCalkowita)/sizeof(liczbaCalkowita[0])+1; i < iloscZnakowWPoleceniu; i++) {
                    fprintf(zmienne,"%c",polecenie[i]);
                }
                fclose(zmienne);
            }
        }
        //wybranie pliku
        boolCzyDanaFunkcja = 0;
        porownywanieTablic(polecenie,pZmiennych,iloscZnakowWPoleceniu,sizeof(pZmiennych)/sizeof(pZmiennych[0]) );
        if (boolCzyDanaFunkcja) {
            for (int i = 0; i < 2; i++) {
                plikZmiennych[i] = polecenie[i+sizeof(pZmiennych)/sizeof(pZmiennych[0])];
            }
        }

        znakCalkowity++;
        printf("\n");
    }
    fclose(plik);
}