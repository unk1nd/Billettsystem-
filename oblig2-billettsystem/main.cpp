// test på lagring og skriving til fil

/*
 Tittel                  : Billettsystem
 Kort beskrivelse        : Program som simulerer et billettsystem
 Skrevet av              : Lisa Marie Sørensen(LMS) og Mikael Bendiksen(MB)
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

string forestilling = "?";

int antall_redusertPris;
int antall_fullPris;
int antall_billett;
int valg;
int totalInntekt;
const int RADER = 16;
const int KOLONNER = 31;

const string salData = "salData.txt";
const string inntektData = "inntektData.txt";
const string forestillings_navn = "forNavn.txt";
const string radInntektData = "radInntektData.txt";

int inntekt_rad[16];


string sal[ RADER ][ KOLONNER ];/* =
{
    {"-----", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"},
    {"Rad01", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad02", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad03", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad04", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad05", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad06", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad07", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad08", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad09", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad10", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad11", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad12", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad13", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad14", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"Rad15", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"}
};

*/

void save()
{
	//inntektfil
	ofstream utfil;	
	utfil.open(inntektData.c_str(), ios::out);
	utfil << antall_redusertPris << " " << antall_fullPris << " " << antall_billett << endl;
	utfil.close();

	// salfil	
	utfil.open(salData.c_str(), ios::out); 
	
	for (int i=0; i < RADER; i++)
	{
		for (int j=0; j<KOLONNER; j++)
		{
			utfil << sal[i][j] << endl;
		}	
	}
	utfil.close();

	// salinntekt	
	utfil.open(radInntektData.c_str(), ios::out); 
	
	for (int i=1; i<RADER; i++)
    {
        utfil << inntekt_rad[i] << endl;     
    }
	utfil.close();


	//forestillingsnavnfil		
	utfil.open(forestillings_navn.c_str(), ios::out);
	utfil << forestilling;
	utfil.close();
	
}//slutten på lagring


void open()
{
	ifstream innfil;	//deklarerer fil-variabelen/objektet
	string tekstlinje;

	//inntektfil
	innfil.open(inntektData.c_str(), ios::in);
	if (innfil.fail()) {
		cout << "Det oppsto en feil ved " << (char)134 << "pning av fila, kontroller at fila \"inntektData.txt\" eksisterer!" << endl;
	} 
	else 
	{
		innfil >> antall_redusertPris >> antall_fullPris >> antall_billett;
	}
	innfil.close();

	//radinntektfil
	innfil.open(radInntektData.c_str(), ios::in);
	if (innfil.fail()) {
		cout << "Det oppsto en feil ved " << (char)134 << "pning av fila, kontroller at fila \"radInntektData.txt\" eksisterer!" << endl;
	} 
	else 
	{
		while( !innfil.eof() )
		{
			for (int i=1; i<RADER; i++)
			{
				innfil >> inntekt_rad[i];     
			}
		}
	}
	innfil.close();

	//salfil
	cout << setiosflags(ios::fixed | ios::showpoint);
	innfil.open(salData.c_str(), ios::in);
	if (innfil.fail()) {
		cout << "Det oppsto en feil ved " << (char)134 << "pning av fila, kontroller at fila \"salData.txt\" eksisterer!" << endl;
	} 
	else 
	{
		while( !innfil.eof() )
		{
			for(int i = 0; i < RADER; ++i)
			{
				for(int j = 0; j < KOLONNER; ++j)
				{
					innfil >> sal[i][j];
					//cout << sal[i][j] << endl;
				}	 
			}		
		}
	}
	innfil.close();
	
	// forestillingsnavnfil
	
	innfil.open(forestillings_navn.c_str(), ios::in);
	if (innfil.fail()) {
		cout << "Det oppsto en feil ved " << (char)134 << "pning av fila, kontroller at fila \"forNavn.txt\" eksisterer!" << endl;
	} else {
		//Går i en løkke, leser hvert ord i hver linje inn i programvariablene nr, navn, alder og inntekt:
		while (!innfil.eof()) {
			//Ingen begrensninger i antall tegn per linje:
			getline(innfil, forestilling, '\n');
			 
		}
		innfil.close();
	}

	
}//slutten på avlesninger

// Skriver ut meny og lar brukeren velge menypunkt
int meny()
{
	
	valg = 0;
    
	cout << "Aktuell forestilling: " << forestilling << endl;
	cout << endl;
	cout << "1. Ny forestilling" << endl;
	cout << "2. Kj" << (char)155 << "p billetter" << endl;
	cout << "3. Vis ledige seter" << endl;
	cout << "4. Vis billettinntekter for denne forestillingen" << endl;
	cout << "0. Avslutt" << endl;
    cout << endl;
	cout << "Ditt valg: ";
	cout << endl;
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
		totalInntekt = 0;
        
        for(int i=1; i < RADER; i++)
        {
            inntekt_rad[i] = 0;
        }
    
        // Leser inn nytt navn for forestilling
        save();
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
	save();
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
    totalInntekt = 0;
    
	// Løkke som går igjennom alle rader og beregner inntekt
    for (int i=1; i<RADER; i++)
    {
        cout << "Rad" << i << "\t" << inntekt_rad[i] << "kr." << endl;     
    }
	totalInntekt = (antall_redusertPris * 60) + (antall_fullPris * 90);
    cout << "Total \t" << totalInntekt << "kr." << endl << endl;
}


// Skjekker hvilket menypunkt som er valgt og kjører igang funksjonen for denne
int main()
{
	open();
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









 
