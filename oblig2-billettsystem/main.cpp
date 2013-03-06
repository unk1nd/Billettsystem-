/*
 Tittel                  : Billettsystem
 Kort beskrivelse        : Program som simulerer et billettsystem
 Skrevet av              : Lisa Marie Sørensen(LMS) og Mikael Bendiksen(MB)
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
int antall_billett;
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

// Skriver ut meny og lar brukeren velge menypunkt
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

// Lar bruker lage en ny forestilling, da slettes alt av tidligere lagret data
void nyForestilling()
{
   
    // Bekrefte ny forestilling
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
    
        // Nullstiller kinosalen
        for (int i=1; i < RADER; i++)
        {
            for (int j=1; j<KOLONNER; j++)
            {
                sal[i][j] = "*";
            }
        }
     
		// forestillingsnavn med input som støtter "spaces"
        string input = "";
        cout << endl << "Hva heter forestillingen:\n>";
		getline(cin, input);

		// en fix for å få det til å fungere ordentlig
		forestilling = input;
		getline(cin, forestilling);
    
        // Tømmer priskalkulasjon
        antall_redusertPris = 0;
        antall_fullPris = 0;
        antall_billett = 0;
        
        for(int i=1; i < RADER; i++)
        {
            inntekt_rad[i] = 0;
        }
    
        // Leser inn nytt navn for forestilling
        
        cout << endl;
    }
}

// Lar bruker kjøpe billett til gitt forestilling
void billettKjop()
{
    int rad;
    int sete;
    char redusert_pris;
    
	// Lar brukeren velge sete
    cout << endl << "Velg rad:" << endl;
    cin >> rad;
    cout << "Velg sete" << endl;
    cin >> sete;
    
	// Skjekker om valgt sete allerede er solgt
    string checker = sal[rad][sete];
    
    if (checker == "#")
    {
        cout << "Rad " << rad << " sete " << sete << " er allerede solgt." << endl;
    }
    else
    {
        // Spør bruker om hvilken pris sete skal selges for
        cout << "Fullpris: 90,-" << endl;
        cout << "Redusert pris: 60,-" << endl;
        cout << "Redusert pris? (y/n)" << endl;
        cin >> redusert_pris;
        
		// Bekreftelse av kjøp
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
			// Legger beløpet inn i inntekt for aktuell rad
            sal[rad][sete] = "#";
            if (redusert_pris == 'y')
            {
                int temp_pris = inntekt_rad[rad];
                temp_pris = 60 + temp_pris;
                inntekt_rad[rad] = temp_pris;
                antall_redusertPris++;
                antall_billett++;
            }
            else
            {
                int temp_pris = inntekt_rad[rad];
                temp_pris = 90 + temp_pris;
                inntekt_rad[rad] = temp_pris;
                antall_fullPris++;
                antall_billett++;
            }
        }
    }
    cout << endl;
}

// Viser hvilke seter som er opptatt/ledig
void ledigeSeter()
{
	// Løkke som printer ut alle rader og kolonner
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

// Viser billettinntekter for hver rad og totalt.
void billettInntekter()
{
    cout << endl;
    cout << "Antall solgte billetter: " << antall_billett << endl;
    cout << "Antall redusert pris billetter: " << antall_redusertPris << endl;
    cout << "Antall full pris billetter: " << antall_fullPris << endl;
    cout << endl;
    int totalInntekt = 0;
    
	// Løkke som går igjennom alle rader og beregner inntekt
    for (int i=1; i<RADER; i++)
    {
        cout << "Rad" << i << "\t" << inntekt_rad[i] << "kr." << endl;
        int tempInntekt = inntekt_rad[i];
        totalInntekt = totalInntekt + tempInntekt;
        
    }
    cout << "Total \t" << totalInntekt << "kr." << endl << endl;
}

// Skjekker hvilket menypunkt som er valgt og kjører igang funksjonen for denne
int main()
{
	valg = meny();
    
	// Løkke som lar bruker velge menypunkt
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


