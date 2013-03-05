/*

 Tittel                  : Billettsystem
 Kort beskrivelse        : Program som simulerer et billettsystem
 Skrevet av              : Lisa Marie Sørensen(LMS) og Mikael Bendiksen(MB)
 Dato                    : 28.02.2013
 
 Endringshistorikk:
 
 Endret dato:    Endret av:	Endring:
 28.02.2013      LMS         La inn menysystem
 28.02.2013      MB          Ny forestilling - navn



 TIPS:
 //skriver ut æ, ø, å;
cout << (char)145 << (char)155 << (char)134 << endl;

//skriver ut Æ, Ø, Å;
cout << (char)146 << (char)157 << (char)143 << endl;


*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int meny();
void nyForestilling();
void billettKjop();
void ledigeSeter();
void billettInntekter();
string forestilling = "?";

int antall_redusertPris;
int antall_fullPris;
int antall_bilett;
int valg;
const int RADER = 16;
const int KOLONNER = 31;

int inntekt_rad[16];

string sal[ RADER ][ KOLONNER ] =
{
    {"     \t", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"},
    {"Rad 1\t", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad 2\t", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad 3\t", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad 4\t", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad 5\t", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad 6\t", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad 7\t", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad 8\t", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad 9\t", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad 10\t", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad 11\t", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad 12\t", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad 13\t", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad 14\t", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad 15\t", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"}
};

/*
 Utf¯rer	: Skriver ut meny og lar brukeren velge menypunkt
 Inndata	: Valg
 Returnerer : Valg
 */

int meny()
{
	valg = 0;
    
	cout << "Aktuell forestilling: " << forestilling << endl;
	cout << "1. Ny forestilling" << endl;
	cout << "2. Kj" << (char)155 << "p billetter" << endl;
	cout << "3. Vis ledige seter" << endl;
	cout << "4. Vis billettinntekter for denne forestillingen" << endl;
	cout << "0. Avslutt" << endl;
    
	cout << "Ditt valg: ";
	cin >> valg;
	return valg;
}

void nyForestilling()
{
   
    //bekrefte ny forestilling
    string bekreftelse;
    cout << endl << (char)157 << "nsker du " << (char)134 << " sette opp ny forestilling?" << endl;
    cout << "Dette vil slette alt av tidligere data." << endl;
    cout << "Bekreft med " << (char)134 << " skrive \"bekreft\":" << endl;
    cin >> bekreftelse;
    if (bekreftelse != "bekreft")
    {
        cout << "Ingen endringer gjort." << endl << "Sender deg tilbake til menyen." << endl << endl;
    }
    else
    {
    
        // nullstiller kinosalen
        for (int i=1; i < RADER; i++)
        {
            for (int j=1; j<KOLONNER; j++)
            {
                sal[i][j] = "*";
            }
        }
     
        
        cout << endl << "Hva heter forestillingen:" << endl;
        //getline(cin,forestilling);
        //cin.ignore();
    
        // tømmer priskalkulasjon
        antall_redusertPris = 0;
        antall_fullPris = 0;
        antall_bilett = 0;
        
        for(int i=1; i < RADER; i++)
        {
            inntekt_rad[i] = 0;
        }
    
        // leser inn nytt navn for forestilling
        cin >> forestilling;
        cout << endl;
    }
}

void billettKjop()
{
    int rad;
    int sete;
    char halv_pris;
    
    cout << endl << "Velg rad:" << endl;
    cin >> rad;
    cout << "Velg sete" << endl;
    cin >> sete;
    
    string checker = sal[rad][sete];
    
    if (checker == "#")
    {
        cout << "Rad " << rad << " sete " << sete << " er allerede solgt." << endl;
    }
    else
    {
        
        
        cout << "Fullpris: 90,-" << endl;
        cout << "Redusert pris: 60,-" << endl;
        cout << "Redusert pris? (y/n)" << endl;
        cin >> halv_pris;
        
        cout << "Selge Rad " << rad << " sete " << sete << " ?" << endl;
        string bekreftelse_kjop;
        cout << "Bekreft med " << (char)134 << " skrive \"bekreft\":" << endl;
        cin >> bekreftelse_kjop;
        if (bekreftelse_kjop != "bekreft")
        {
            cout << "Ingen endringer gjort." << endl << "Sender deg tilbake til menyen." << endl << endl;
        }
        else
        {
            sal[rad][sete] = "#";
            if (halv_pris == 'y')
            {
                int temp_pris = inntekt_rad[rad];
                temp_pris = 60 + temp_pris;
                inntekt_rad[rad] = temp_pris;
                antall_redusertPris++;
                antall_bilett++;
            }
            else
            {
                int temp_pris = inntekt_rad[rad];
                temp_pris = 90 + temp_pris;
                inntekt_rad[rad] = temp_pris;
                antall_fullPris++;
                antall_bilett++;
            }
        }
    }
    cout << endl;
}

void ledigeSeter()
{
	cout << endl;
	for (int i=0; i < RADER; i++)
	{
		for (int j=0; j<KOLONNER; j++)
		{
			cout << sal[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
}

void billettInntekter()
{
    cout << endl;
    cout << "Antall solgte biletter: " << antall_bilett << endl;
    cout << "Antall redusert pris biletter: " << antall_redusertPris << endl;
    cout << "Antall full pris biletter: " << antall_fullPris << endl;
    cout << endl;
    int totalInntekt = 0;
    
    for (int i=1; i<RADER; i++)
    {
        cout << "Rad" << i << "\t" << inntekt_rad[i] << "kr." << endl;
        int tempInntekt = inntekt_rad[i];
        totalInntekt = totalInntekt + tempInntekt;
        
    }
    cout << "Total \t" << totalInntekt << "kr." << endl << endl;
}

int main()
{
	valg = meny();
    

	while (valg != 0)
	{
		switch (valg)
		{
            case 1:
                cout << "Du valgte '1. Ny forestilling'" << endl;
                nyForestilling();
                break;
            case 2:
                cout << "Du valgte '2. Kj" << (char)155 << "p billetter'" << endl;
                billettKjop();
                break;
            case 3:
                cout << "Du valgte '3. Vis ledige seter'" << endl;
                ledigeSeter();
                break;
            case 4:
                cout << "Du valgte '4. Vis billettinntekter for denne forestillingen'" << endl;
                billettInntekter();
                break;
            default:
                cout << "Feil brukerinput! Velg p" <<  (char)134 << " nytt." << endl;
                break;
		}
        
		valg = meny();
	}
    
	return 0;
}


