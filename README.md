# Administrare-Retea-de-Magazine-Online

**Important:** Acest proiect este conceput pentru a demonstra aplicarea principiilor Programării Orientate pe Obiecte (OOP) utilizând limbajul C++. Scopul este de a oferi o înțelegere profundă a modului în care conceptele OOP pot fi aplicate în dezvoltarea de software real.

**Descriere:** Sistemul dezvoltat este menit să funcționeze integral în consola de comandă, oferind un mediu interactiv prin care utilizatorii pot accesa și gestiona diferite funcționalități ale unui sistem de administrare a unei rețele de magazine online. Proiectul se împarte în două secțiuni principale: „Client” și „Magazin”, fiecare având roluri și funcții specifice care contribuie la funcționalitatea generală a sistemului.

## Funcționalități

### Secțiunea Client
- **Creare Cont Nou:** Utilizatorii pot crea conturi noi furnizând detalii personale și respectând criteriile de securitate pentru parolă.
- **Autentificare:** Există posibilitatea de autentificare folosind seturi de credențiale predefinite pentru scopuri de testare.  ( (Nume_de_utilizator; Parolă): (Ion; Ion12345), (Andrei; Andrei123), (Rares; Rares123), (Diana; Diana123) )
- **Parcurgere Produse:** Utilizatorii pot naviga prin baza de date de produse, organizată pe furnizori.
- **Coș de Cumpărături:** Funcționalitatea de gestionare a coșului de cumpărături, inclusiv adăugarea și eliminarea produselor.
- **Finalizarea Comenzii:** Generarea unui raport de comandă în format .txt, cu detaliile complete ale comenzii.

### Secțiunea Magazin
- **Autentificare Administrator:** Acces pentru administratorii magazinelor, cu credențiale predefinite. ( (ID_Magazin; Nume_de_utilizator; Parolă): (1; Maria; Maria123), (2; Violeta; Violeta123), (3; Cornel; Cornel123) )
- **Gestionarea Produselor:** Adăugarea și modificarea informațiilor produselor în baza de date.
- **Procesarea Comenzilor:** Administrarea comenzilor efectuate și generarea de rapoarte dedicate pentru fiecare magazin.

## Caracteristici Principale

- **Programare Orientată pe Obiecte:** Implementarea eficientă a conceptelor OOP pentru o structură cod modulară și ușor de întreținut.
- **Interfață Consolă:** Un sistem complet accesibil prin linia de comandă, oferind interactivitate și accesibilitate.
- **Gestionarea Datelor:** Capacitatea de a manipula și stoca date local, permițând o gestionare eficientă a informațiilor.

## Instalare și Rulare

Pentru a începe, asigură-te că ai configurat un mediu de dezvoltare C++ adecvat. Urmărește pașii de mai jos pentru a clona repository-ul și a compila codul:

```bash
git clone https://github.com/alexjilavu29/Administrare-Retea-de-Magazine-Online
cd Program Administrare Retea de Magazine Online
g++ -o program Program Administrare Rețea de Magazine Online.cpp
./program
```

## Contribuții

Suntem deschiși la orice contribuții din partea comunității. Dacă dorești să contribui, te rugăm să urmezi pașii standard de contribuție prin pull requests.

