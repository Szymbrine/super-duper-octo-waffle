#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

const int LICZBA_PROB = 5;

void trybGraczZgaduje() {
    int wylosowana = rand() % 21;
    int strzal;
    std::cout << "\n--- TRYB 1: Zgadnij liczbe z przedzialu <0, 20> ---\n";
    for (int proba = 1; proba <= LICZBA_PROB; proba++) {
        std::cout << "Proba " << proba << "/" << LICZBA_PROB << ". Podaj liczbe: ";
        std::cin >> strzal;
        if (strzal == wylosowana) {
            std::cout << "zgadles\n";
            return;
        }
        else if (strzal > wylosowana)
            std::cout << "duzo\n";
        else
            std::cout << "malo\n";
    }
    std::cout << "Przegrales! Wyczerpano limit prob. Szukana liczba to: " << wylosowana << "\n";
}

void trybKomputerZgaduje() {
    int minZakres = 0;
    int maxZakres = 20;
    std::string odpowiedz;
    std::cout << "\n--- TRYB 2: Wymysl liczbe z przedzialu <0, 20> ---\n";
    std::cout << "Odpowiadaj: \"zgadles\", \"duzo\" lub \"malo\".\n";
    for (int proba = 1; proba <= LICZBA_PROB; proba++) {
        if (minZakres > maxZakres) {
            std::cout << "Blad! Podales sprzeczne podpowiedzi - brak liczb w przedziale.\n";
            return;
        }
        int strzalKomputera = minZakres + rand() % (maxZakres - minZakres + 1);
        std::cout << "Proba " << proba << "/" << LICZBA_PROB << ". Czy Twoja liczba to " << strzalKomputera << "? ";
        std::cin >> odpowiedz;
        if (odpowiedz == "zgadles") {
            std::cout << "Komputer odgadl Twoja liczbe!\n";
            return;
        }
        else if (odpowiedz == "duzo")
            maxZakres = strzalKomputera - 1;
        else if (odpowiedz == "malo")
            minZakres = strzalKomputera + 1;
        else {
            std::cout << "Nieznana komenda! Wpisz dokladnie: zgadles, duzo lub malo.\n";
            proba--;
        }
    }
    std::cout << "Komputer przegral! Nie udalo sie odgadnac w " << LICZBA_PROB << " probach.\n";
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int wybor;
    bool dziala = true;
    while (dziala) {
        std::cout << "\n=== MENU GLOWNE ===\n";
        std::cout << "1. Tryb 1: Zgaduje uzytkownik\n";
        std::cout << "2. Tryb 2: Zgaduje komputer\n";
        std::cout << "0. Zakoncz program\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> wybor;
        switch (wybor) {
        case 1:
            trybGraczZgaduje();
            break;
        case 2:
            trybKomputerZgaduje();
            break;
        case 0:
            std::cout << "Zamykanie programu...\n";
            dziala = false;
            break;
        default:
            std::cout << "Nieprawidlowy wybor. Sprobuj ponownie.\n";
            break;
        }
    }
    return 0;
}