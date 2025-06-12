# SystemyOperacyjne2

Projekt 1: Problem jedzących filozofów

Problem jedzących filozofów wymyślony przez Dijkstrę jest problem dostępu do ograniczonego zasobu. Jest to problem synchronizacji. 
W problemie zdefiniowani są filozofowie oraz widelce. Jednych i drugich jest taka sama liczba i znajdują się naprzemian, tak że każdy filozof sąsiaduje z dwoma widelcami. Widelec może znajdować się w dwóch stanach: zajęty oraz wolny. Filozof może znajdować się w trzech stanach: jedzenia, myślenia oraz starania się o widelec. 

-Stan jedzenia jest wtedy, gdy filozof posiada dwa widelce.

-Stan myślenia jest wtedy, gdy filozof nie robi nic oraz nie posiada żadnych widelców.

-Stan starania się o widelec jest wtedy, gdy filozof próbuje zdobyć dwa widelce. Mogą one być zajęte więc filozof czeka aż oczekiwany przez niego widelec będzie wolny. Stan kończy się gdy filozof zdobędzie oba widelce

Wątkami są filozofowie.

Sekcją krytyczną są widelce. W problemie występuje wyścig o przejęcie widelców. Aby zapobiec całkowitego zablokowania programu zostały zastosowane dwie metody:
1. zróżnicowanie czasu jaki każdy z filozofów spędza w stanie myślenia
2. Numeracja widelców, gdzie każdy z filozofów próbuje najpierw wziąć widelec o niższym numerze.
Jako, że dwóch filozofów ma widelec o numerze 0 jako najniższy, gwarantuje to, że jeden z filozofów nie weźmie do ręki dokładnie jednego widelca. Dzięki temu minimalnie jeden filozof będzie miał dostęp do dwóch widelców.


Działanie programu:
1. uruchomienie pliku filozof.cpp
2. Podanie ilości filozofów (std::cin)
3. Sprawdzenie czy jest co njamniej 2 filozofów
4. stworzenie wektora struktur widelcy (numeracja widelców oraz mutex)
5. stworzenie wątków
6. zapewnienie synchronizacji
7. program nie ma warunku końcowego

Projekt 2: Wielowątkowy chat w architekturze klient serwer

Problem wielowątkowego chatu polega na stworzeniu serwera, który będzie obsługiwał komunikaty od wielu użytkowników jednocześnie i zapewniał ich działanie.
W problemie zdefiniowany jest serwer oraz klienci. Jest jeden serwer i dowolna liczba klientów. Serwer przyjmuje wiadomości od klientów i broadcastuje je do wszystkich klientów. Klient dołącza do serwera i ma możliwość wysyłania wiadomości oraz wyświetlenia wiadomości broadcastowanych.

Wątkami są klienci.

Sekcją krytyczną jest serwer. W problemie występuje wyścig o kolejność przesłania wiadomości. Klient blokuje wysyłanie wiadomości innym wątkom do czasu zakończenia procedury przesłania wiadomości.

Dodatkowo klient też jest podzielony na dwa wątki, do wysyłania wiadomości oraz do odbierania wiadomości z broadcastu. 

Działanie programu:
1. Uruchomienie server.py (python server.py)
2. Serwer tworzy się na porcie
3. Uruchomienie client.py (python client.py)
4. Serwer wykrywa nowego klienta i tworzy dla niego wątek
5. Klient tworzy wątek odbierania informacji od serwera
6. Klient tworzy wątek wysyłania wiadomości na serwer
7. Jeśli ma być więcej klientów powrócić do kroku 3
8. Klient wysyła wiadomość
9. Serwer jest blokowany, wiadomość jest wykryta na serwerze
10. Serwer wysyła broadcast
11. Klienci odbierają wiadomość wątkiem odbierania wiadomości
