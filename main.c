#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define iloscZnakowWPoleceniu sizeof(polecenie)/sizeof(polecenie[0])

int startInfo = 1;


int znakCalkowity = 0;
//int tablicaIlosciZnakow[10];
int dlugosc;
int iloscLini = 0;
int licznikLini = 0;
int boolCzyDanaFunkcja = 1;

int czyUstawionaInnaNazwa = 0;

char znak;
//char plikZmiennych[] = "pz";

char napisz[] = "napisz";
char koniec[] = "koniec";
char spij[] = "śpij";
char liczbaCalkowita[] = "liczbaCałkowita";
char pZmiennych[] = "#pZmiennych";
char usunZawartosc[] = "#usuńZawartość";
char infoS[] = "#!/bin/Polski";

char idzDo[] = "idźDo";
char wskaznikIdzDo[] = ":";


char nazwaPlikuPrzenoszona[30];
int iloscElementowNowejNazwy = 2;


int lokalizacjaDanegoTekstu(char plik[], char jeden[], int iloscZnakowTablicy)
{
    FILE *mangos = fopen(plik, "r");
    if (mangos == NULL) {return -1;}

    fseek(mangos, 0, SEEK_END);

    int dlugosc = ftell(mangos);
    char znak;


    int linia = 0;
    int punktWLini = 0;

    int iloscZgodnych = 0;

    //int j = 0 + linia;

    for (int i = 1; i < dlugosc; i++)
    {
        fseek(mangos, i, 0);
        fscanf(mangos, "%c", &znak);



        if (jeden[punktWLini] == znak && punktWLini <= iloscZnakowTablicy) {
            iloscZgodnych++;
        }

        if (iloscZgodnych == iloscZnakowTablicy)
        {
            return i - punktWLini;
        }


        punktWLini++;
        if (znak == ';') {
            i++;
            linia++;
            punktWLini = 0;
            iloscZgodnych = 0;
        }
    }
    if (iloscZgodnych != iloscZnakowTablicy) {
        return -1;
    }

    fclose(mangos);
}


void porownywanieTablic(char meow[],char Nigga[],int sizeFirst, int sizeSecond) {
    boolCzyDanaFunkcja = 1;
    if (sizeFirst >= sizeSecond   -1) {
        for (int i = 0; i < sizeSecond-1; i++) {
            if (meow[i] != Nigga[i]) {
                boolCzyDanaFunkcja = 0;
                break;
            }
        }
    }
    else {
        boolCzyDanaFunkcja = 0;
    }
}

int main() {

    FILE *plik = fopen("plik.pl","r");
    fseek(plik, 0, 0);



    char fajnyZnak;
    for  (int i = 0; i < dlugosc; i++ )
    {
        fseek(plik, i, SEEK_SET);
        fscanf(plik, "%c", &fajnyZnak);
        if (fajnyZnak == '\n') {
            iloscLini++;
        }
    }
    for (int i = 0; i < 30; i++) {
        nazwaPlikuPrzenoszona[i] = -1;
    }
    nazwaPlikuPrzenoszona[0] = 'p';
    nazwaPlikuPrzenoszona[1] = 'z';
    nazwaPlikuPrzenoszona[2] = 0;

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

        //ustawianie pliku
        //wybranie pliku

        boolCzyDanaFunkcja = 0;
        porownywanieTablic(polecenie,pZmiennych,iloscZnakowWPoleceniu,sizeof(pZmiennych)/sizeof(pZmiennych[0]) );
        if (boolCzyDanaFunkcja) {
            iloscElementowNowejNazwy = 0;
            for (int d = sizeof(pZmiennych)/sizeof(pZmiennych[0]); d < sizeof(polecenie)/sizeof(polecenie[0]); d++)
            {
                if (';' == polecenie[d]) {
                    break;
                }
                iloscElementowNowejNazwy++;
            }
            czyUstawionaInnaNazwa = 1;
        }
        char plikZmiennych[iloscElementowNowejNazwy+1];
        if (boolCzyDanaFunkcja) {
            for (int i = 0; i < 30; i++)
            {
                if (i <  iloscElementowNowejNazwy) {
                    nazwaPlikuPrzenoszona[i] = polecenie[i+sizeof(pZmiennych)/sizeof(pZmiennych[0])];
                }
                else {
                    nazwaPlikuPrzenoszona[i] = -1;
                }
            }
        }

        for (int i = 0; i < iloscElementowNowejNazwy; i++)
        {
            plikZmiennych[i] = nazwaPlikuPrzenoszona[i];
        }
        plikZmiennych[iloscElementowNowejNazwy] = 0;




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
            else if (polecenie[ sizeof(liczbaCalkowita)/sizeof(liczbaCalkowita[0]) ] == '*' )
            {


                int iloscZnakowMiedzySpacjami = 0;
                int iloscSpacji = 0;
                int lokalizacjaZaczecia = -1;

                //sprawdzamy spacje
                for (int i = 0; i < sizeof(polecenie)/sizeof(polecenie[0]) - 1; i++) {
                    if (iloscSpacji == 2 && polecenie[i] != ';') {
                        iloscZnakowMiedzySpacjami++;
                        if (lokalizacjaZaczecia == -1)
                        {
                            lokalizacjaZaczecia = i;
                        }
                    }
                    if (polecenie[i] == ' ') {
                        iloscSpacji++;
                    }
                }
                //deklaracja tablicy
                char poszukiwany[iloscZnakowMiedzySpacjami+4];
                poszukiwany[0] = 'i';
                poszukiwany[1] = 'n';
                poszukiwany[2] = 't';
                poszukiwany[3] = ' ';
                for (int i = lokalizacjaZaczecia; i < lokalizacjaZaczecia+iloscZnakowMiedzySpacjami; i++)
                {
                    poszukiwany[i-lokalizacjaZaczecia+4] = polecenie[i];
                }
                //koniec tego gówna

                int miejsceTekstu = lokalizacjaDanegoTekstu(plikZmiennych, poszukiwany, sizeof(poszukiwany)/sizeof(poszukiwany[0])-1) ;
                printf("%d",miejsceTekstu);
                FILE * zmiennee = fopen(plikZmiennych,"r");
                fseek(zmiennee,miejsceTekstu,0);
                fscanf(zmiennee, "%c", &znak);
                printf("%c",' ');
                printf("%c", znak);
            }
            else if (polecenie[ sizeof(liczbaCalkowita)/sizeof(liczbaCalkowita[0]) ] == 'R' )
            {
                int iloscZnakowMiedzySpacjami = 0;
                int iloscSpacji = 0;
                int lokalizacjaZaczecia = -1;

                //sprawdzamy spacje
                for (int i = 0; i < sizeof(polecenie)/sizeof(polecenie[0]) - 1; i++) {
                    if (iloscSpacji == 2 && polecenie[i] != ';') {
                        iloscZnakowMiedzySpacjami++;
                        if (lokalizacjaZaczecia == -1)
                        {
                            lokalizacjaZaczecia = i;
                        }
                    }
                    if (polecenie[i] == ' ') {
                        iloscSpacji++;
                    }
                }
                //deklaracja tablicy
                char poszukiwany[iloscZnakowMiedzySpacjami+4];
                poszukiwany[0] = 'i';
                poszukiwany[1] = 'n';
                poszukiwany[2] = 't';
                poszukiwany[3] = ' ';
                for (int i = lokalizacjaZaczecia; i < lokalizacjaZaczecia+iloscZnakowMiedzySpacjami; i++)
                {
                    poszukiwany[i-lokalizacjaZaczecia+4] = polecenie[i];
                }
                //koniec tego gówna

                int miejsceTekstu = lokalizacjaDanegoTekstu(plikZmiennych, poszukiwany, sizeof(poszukiwany)/sizeof(poszukiwany[0])-1) ;
                printf("%d",miejsceTekstu);
            }

        }
        //start & Info
        boolCzyDanaFunkcja = 0;
        porownywanieTablic(polecenie,infoS,iloscZnakowWPoleceniu,sizeof(infoS)/sizeof(infoS[0]) );
        if (!boolCzyDanaFunkcja && licznikLini == 0) {
            printf("Błąd, #!/bin/Polski x; wymagane na początku pliku");
            break;
        }
        else if (boolCzyDanaFunkcja && licznikLini == 0) {
            int licznik = 0;
            int czy = 0;

            while (1) {
                fseek(plik, licznik, SEEK_SET);
                fscanf(plik,"%c",&znak);
                if (znak == ';') {
                    break;
                }
                else if (znak == '1') {
                    czy = 1;
                }
                licznik++;
            }

            if (czy) {
                printf("####################################################################\n");
                printf("##################### Polski++ Aplpha 0.02 ##### ###################\n");
                printf("####################################################################\n");
                printf("##### ,,A niechaj narodowie wżdy postronni znają, ################# \n");
                printf("####### iż Polacy nie gęsi, iż swój język mają'' - Mikołaj Rej #### \n");
                printf("####################################################################\n");
            }
        }
        //usuwanie zawartości pliku
        porownywanieTablic(polecenie,usunZawartosc,iloscZnakowWPoleceniu,sizeof(usunZawartosc)/sizeof(usunZawartosc[0]) );
        if (boolCzyDanaFunkcja) {
            FILE *zmienne = fopen(plikZmiennych, "w");
            fprintf(zmienne,"%s","");
            fclose(zmienne);
        }
        //znacznik goto
        porownywanieTablic(polecenie,wskaznikIdzDo,iloscZnakowWPoleceniu,sizeof(wskaznikIdzDo)/sizeof(wskaznikIdzDo[0]) );
        if (boolCzyDanaFunkcja) {
            FILE *zmienne = fopen(plikZmiennych, "a");
            fprintf(zmienne,"%s","\ngoto ");
            for (int i = 1; i < iloscZnakowWPoleceniu-1; i++) {
                fprintf(zmienne,"%c",polecenie[i]);
            }
            fprintf(zmienne," ");
            fprintf(zmienne,"%d",znakCalkowity-iloscZnakowWPoleceniu);
            fprintf(zmienne,"%c",';');
            fclose(zmienne);

        }
        //goto wsskaźnik
        porownywanieTablic(polecenie,idzDo,iloscZnakowWPoleceniu,sizeof(idzDo)/sizeof(idzDo[0]));
        if (boolCzyDanaFunkcja)
        {
            FILE *zmienne = fopen(plikZmiennych, "r");
            fseek(zmienne,0,0);
            int znacznikZnakuWZmiennych = 0;
            char meowGoto[] = "goto ";
            fseek(zmienne,0,SEEK_END);
            int fajny = ftell(zmienne);
            int licznikOdZeraDlaPoleceniaMeowMeowMeowMeowMeow = 0;
            int czyGoto = 1;
            for (int i = 0; i < fajny; i++)
            {
                fseek(zmienne,i,SEEK_SET);
                fscanf(zmienne,"%c",&znak);
                if (znak != meowGoto[licznikOdZeraDlaPoleceniaMeowMeowMeowMeowMeow]) {
                    czyGoto = 0;
                    break;
                }

                if (licznikOdZeraDlaPoleceniaMeowMeowMeowMeowMeow >= 4 && czyGoto) {
                    if ( znak == polecenie[licznikOdZeraDlaPoleceniaMeowMeowMeowMeowMeow-3] ) {
                        printf("meow \n");
                    }
                }

                if (i == ';') {
                    i = i+2;
                    licznikOdZeraDlaPoleceniaMeowMeowMeowMeowMeow = 0;
                    czyGoto = 1;
                }
                licznikOdZeraDlaPoleceniaMeowMeowMeowMeowMeow++;
            }
            fclose(zmienne);
        }
        //goto
        porownywanieTablic(polecenie,idzDo,iloscZnakowWPoleceniu,sizeof(idzDo)/sizeof(idzDo[0]));
        if (boolCzyDanaFunkcja)
        {
            FILE *zmienne = fopen(plikZmiennych, "r");
            fseek(zmienne,0,0);
            int znacznikZnakuWZmiennych = 0;
            char meowGoto[] = "goto ";
            fseek(zmienne,0,SEEK_END);
            int fajny = ftell(zmienne);
            int licznikOdZeraDlaPoleceniaMeowMeowMeowMeowMeow = 0;
            int czyGoto = 1;
            int czyZastosowacGoto = 1;
            int wartoscLini;
            char tablicaDoZapisuZnakow[20];

            for (int i = 1; i < fajny; i++)
            {
                fseek(zmienne,i,SEEK_SET);
                fscanf(zmienne,"%c",&znak);
                if (znak != meowGoto[licznikOdZeraDlaPoleceniaMeowMeowMeowMeowMeow] && licznikOdZeraDlaPoleceniaMeowMeowMeowMeowMeow < 4) {
                    czyGoto = 0;
                    czyZastosowacGoto = 0;
                }

                if (licznikOdZeraDlaPoleceniaMeowMeowMeowMeowMeow >= 4 && czyGoto) {
                    if ( znak != polecenie[licznikOdZeraDlaPoleceniaMeowMeowMeowMeowMeow-5+7] && znak != ' ') {
                        czyZastosowacGoto = 0;
                    }
                    else {
                        czyZastosowacGoto++;
                        if (czyZastosowacGoto == 1)
                        {
                            wartoscLini = ftell(zmienne);
                        }
                    }

                }
                else {
                    czyZastosowacGoto = 0;
                }

                if (znak == ';') {
                    i = i+2;
                    licznikOdZeraDlaPoleceniaMeowMeowMeowMeowMeow = 0;
                    czyGoto = 1;
                    czyZastosowacGoto = 1;
                }
                licznikOdZeraDlaPoleceniaMeowMeowMeowMeowMeow++;
            }
            int liczbaMeowMeowUwU;
            if (czyZastosowacGoto > 0)
            {
                while (1) {
                    wartoscLini++;
                    fseek(zmienne,wartoscLini,0);
                    fscanf(zmienne,"%c",&znak);
                    if (znak == ';') {break;}
                    else if (znak == ' ')
                    {
                        wartoscLini++;
                        fscanf(zmienne,"%d",&liczbaMeowMeowUwU);
                        znakCalkowity = liczbaMeowMeowUwU;
                        break;
                    }
                }
            }


            fclose(zmienne);
        }




        licznikLini++;
        znakCalkowity++;
        printf("\n");
    }
    fclose(plik);
}
