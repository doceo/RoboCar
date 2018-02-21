# RoboCar
Il progetto RoboCar è stato pensato e realizzato a scopo didattico dal  prof. Fabrizio Tamigi. 
Le successive modifiche, sempre a scopo didattico, dal prof Diomede Mazzone

## Descrizione

RoboCar è una macchina su base arduino. Utilizza motori DC per le ruote pilotati da un doppio ponte L298n. Arduino Nano è collegato 
ad un dispositivo per la connessione Wifi, l'ESP01.
la libreria per la gestione di tale dispositivo è stata scritta dal prof. Tamigi ed è contenuta nel file ESP8266.h.

## Funzionamento
All'accensione l'ESP01 viene configurato come AP, così da permettere la connessione di un qualunque dispositivo attraverso un browser, all'indirizzo 192.168.1.1.
Stabilita la connessione viene inviato al client collegato un file html, contenuto in Webpage.h, così da poter pilotare l'auto.
Il file html contiene codice javascript tale da permettere ad arduino di pilotare i motori in modo adeguato.
