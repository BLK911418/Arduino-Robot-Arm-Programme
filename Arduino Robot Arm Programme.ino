#include <SoftwareSerial.h>
#include <Servo.h>

Servo servo01;
Servo servo02;
Servo servo03;
Servo servo04;
Servo servo05;
Servo servo06;
Servo gripper;

SoftwareSerial Bluetooth(3, 4); // Arduino(RX, TX) - HC-05 Bluetooth (TX, RX)

int servo1Pos, servo2Pos, servo3Pos, servo4Pos, servo5Pos, servo6Pos, gripper; // position actuelle
int servo1PPos, servo2PPos, servo3PPos, servo4PPos, servo5PPos, servo6PPos, gripperPPOS; // position précédente
int servo01SP[50], servo02SP[50], servo03SP[50], servo04SP[50], servo05SP[50], servo06SP[50], grippersp[50]; // pour mémoriser les positions/pas
int speedDelay = 20;
int index = 0;
String dataIn = "";

void setup() {
  servo01.attach(3);
  servo02.attach(5);
  servo03.attach(6);
  servo04.attach(9);
  servo05.attach(10);
  servo06.attach(11);
  gripper.attach(13);
  Bluetooth.begin(38400); // Débit en bauds par défaut du module Bluetooth
  Bluetooth.setTimeout(1);
  delay(20);
  // Position initiale du bras du robot
  servo1PPos = 90;
  servo01.write(servo1PPos);
  servo2PPos = 150;
  servo02.write(servo2PPos);
  servo3PPos = 35;
  servo03.write(servo3PPos);
  servo4PPos = 140;
  servo04.write(servo4PPos);
  servo5PPos = 85;
  servo05.write(servo5PPos);
  servo6PPos = 80;
  servo06.write(servo6PPos);
  gripperPPos = 80;
  gripper.write(gripperPPos); 
}

void loop() {
  // Vérifier les données entrantes
  if (Bluetooth.available() > 0) {
    dataIn = Bluetooth.readString();  // Lire les données sous forme de chaîne(string)
    
    // Si le curseur "waist" a changé de valeur - Déplacez le Servomoteur 1 en position
    if (dataIn.startsWith("s1")) {
      String dataInS = dataIn.substring(2, dataIn.length()); // Extraire uniquement le nombre. E.g. de "s1120" à "120"
      servo1Pos = dataInS.toInt();  // Convertir la chaîne en entier (string into integer)
      // Nous utilisons des boucles pour pouvoir contrôler la vitesse du servo
      // Si la position précédente est supérieure à la position actuelle
      if (servo1PPos > servo1Pos) {
        for ( int j = servo1PPos; j >= servo1Pos; j--) {   // Exécutez le servo vers le bas
          servo01.write(j);
          delay(20);    // définit la vitesse à laquelle le servo tourne
        }
      }
      // Si la position précédente est inférieure à la position actuelle
      if (servo1PPos < servo1Pos) {
        for ( int j = servo1PPos; j <= servo1Pos; j++) {   // Run servo up
          servo01.write(j);
          delay(20);
        }
      }
      servo1PPos = servo1Pos;   // définir la position actuelle comme position précédente
    }
    
    // tourner le servomoteur 2
    if (dataIn.startsWith("s2")) {
      String dataInS = dataIn.substring(2, dataIn.length());
      servo2Pos = dataInS.toInt();

      if (servo2PPos > servo2Pos) {
        for ( int j = servo2PPos; j >= servo2Pos; j--) {
          servo02.write(j);
          delay(50);
        }
      }
      if (servo2PPos < servo2Pos) {
        for ( int j = servo2PPos; j <= servo2Pos; j++) {
          servo02.write(j);
          delay(50);
        }
      }
      servo2PPos = servo2Pos;
    }
    // tourner le servomoteur 3
    if (dataIn.startsWith("s3")) {
      String dataInS = dataIn.substring(2, dataIn.length());
      servo3Pos = dataInS.toInt();
      if (servo3PPos > servo3Pos) {
        for ( int j = servo3PPos; j >= servo3Pos; j--) {
          servo03.write(j);
          delay(30);
        }
      }
      if (servo3PPos < servo3Pos) {
        for ( int j = servo3PPos; j <= servo3Pos; j++) {
          servo03.write(j);
          delay(30);
        }
      }
      servo3PPos = servo3Pos;
    }
    // tourner le servomoteur 4
    if (dataIn.startsWith("s4")) {
      String dataInS = dataIn.substring(2, dataIn.length());
      servo4Pos = dataInS.toInt();
      if (servo4PPos > servo4Pos) {
        for ( int j = servo4PPos; j >= servo4Pos; j--) {
          servo04.write(j);
          delay(30);
        }
      }
      if (servo4PPos < servo4Pos) {
        for ( int j = servo4PPos; j <= servo4Pos; j++) {
          servo04.write(j);
          delay(30);
        }
      }
      servo4PPos = servo4Pos;
    }
    // tourner le servomoteur 5
    if (dataIn.startsWith("s5")) {
      String dataInS = dataIn.substring(2, dataIn.length());
      servo5Pos = dataInS.toInt();
      if (servo5PPos > servo5Pos) {
        for ( int j = servo5PPos; j >= servo5Pos; j--) {
          servo05.write(j);
          delay(30);
        }
      }
      if (servo5PPos < servo5Pos) {
        for ( int j = servo5PPos; j <= servo5Pos; j++) {
          servo05.write(j);
          delay(30);
        }
      }
      servo5PPos = servo5Pos;
    }
    // tourner le servomoteur 6
    if (dataIn.startsWith("s6")) {
      String dataInS = dataIn.substring(2, dataIn.length());
      servo6Pos = dataInS.toInt();
      if (servo6PPos > servo6Pos) {
        for ( int j = servo6PPos; j >= servo6Pos; j--) {
          servo06.write(j);
          delay(30);
        }
      }
      if (servo6PPos < servo6Pos) {
        for ( int j = servo6PPos; j <= servo6Pos; j++) {
          servo06.write(j);
          delay(30);
        }
      }
      servo6PPos = servo6Pos; 
    }
    // tourner le servomoteur gripper
    if (dataIn.startsWith("sg")) {
      String dataInS = dataIn.substring(2, dataIn.length());
      gripperPos = dataInS.toInt();

      if (gripperPPos > gripperPos) {
        for ( int j = gripperPPos; j >= gripperPos; j--) {
          gripper.write(j);
          delay(50);
        }
      }
      if (gripperPPos < gripperPos) {
        for ( int j = gripperPPos; j <= gripperPos; j++) {
          gripper.write(j);
          delay(50);
        }
      }
      gripperPPos = gripperPos;
    }
    // If button "SAVE" is pressed
    if (dataIn.startsWith("SAVE")) {
      servo01SP[index] = servo1PPos;  // enregistrer la position dans le tableau
      servo02SP[index] = servo2PPos;
      servo03SP[index] = servo3PPos;
      servo04SP[index] = servo4PPos;
      servo05SP[index] = servo5PPos;
      servo06SP[index] = servo6PPos;
      index++;                        // Augmenter l'index du tableau
    }
    // Si bouton "RUN" est pressé
    if (dataIn.startsWith("RUN")) {
      runservo();  // Mode automatique - exécuter les étapes enregistrées 
    }
    // Si bouton "RESET" est pressé
    if ( dataIn == "RESET") {
      memset(servo01SP, 0, sizeof(servo01SP)); // Effacer les données du tableau à 0
      memset(servo02SP, 0, sizeof(servo02SP));
      memset(servo03SP, 0, sizeof(servo03SP));
      memset(servo04SP, 0, sizeof(servo04SP));
      memset(servo05SP, 0, sizeof(servo05SP));
      memset(servo06SP, 0, sizeof(servo06SP));
      index = 0;  // Index à 0
    }
  }
}

// Fonction personnalisée du mode automatique - exécuter les étapes enregistrées
void runservo() {
  while (dataIn != "RESET") {   // Exécutez les étapes encore et encore jusqu'à ce que le bouton "RESET" est pressé
    for (int i = 0; i <= index - 2; i++) {  // Parcourez toutes les étapes(index)
      if (Bluetooth.available() > 0) {      // Vérifier les données entrantes
        dataIn = Bluetooth.readString();
        if ( dataIn == "PAUSE") {           // Si le bouton "PAUSE" est pressé
          while (dataIn != "RUN") {         // attendre jusqu'à le bouton "RUN" est de nouveau pressé
            if (Bluetooth.available() > 0) {
              dataIn = Bluetooth.readString();
              if ( dataIn == "RESET") {     
                break;
              }
            }
          }
        }
        // Si le curseur de vitesse est modifié
        if (dataIn.startsWith("ss")) {
          String dataInS = dataIn.substring(2, dataIn.length());
          speedDelay = dataInS.toInt(); // Changer la vitesse des servomoteurs (delay time)
        }
      }
      // Servo 1
      if (servo01SP[i] == servo01SP[i + 1]) {
      }
      if (servo01SP[i] > servo01SP[i + 1]) {
        for ( int j = servo01SP[i]; j >= servo01SP[i + 1]; j--) {
          servo01.write(j);
          delay(speedDelay);
        }
      }
      if (servo01SP[i] < servo01SP[i + 1]) {
        for ( int j = servo01SP[i]; j <= servo01SP[i + 1]; j++) {
          servo01.write(j);
          delay(speedDelay);
        }
      }

      // Servo 2
      if (servo02SP[i] == servo02SP[i + 1]) {
      }
      if (servo02SP[i] > servo02SP[i + 1]) {
        for ( int j = servo02SP[i]; j >= servo02SP[i + 1]; j--) {
          servo02.write(j);
          delay(speedDelay);
        }
      }
      if (servo02SP[i] < servo02SP[i + 1]) {
        for ( int j = servo02SP[i]; j <= servo02SP[i + 1]; j++) {
          servo02.write(j);
          delay(speedDelay);
        }
      }

      // Servo 3
      if (servo03SP[i] == servo03SP[i + 1]) {
      }
      if (servo03SP[i] > servo03SP[i + 1]) {
        for ( int j = servo03SP[i]; j >= servo03SP[i + 1]; j--) {
          servo03.write(j);
          delay(speedDelay);
        }
      }
      if (servo03SP[i] < servo03SP[i + 1]) {
        for ( int j = servo03SP[i]; j <= servo03SP[i + 1]; j++) {
          servo03.write(j);
          delay(speedDelay);
        }
      }

      // Servo 4
      if (servo04SP[i] == servo04SP[i + 1]) {
      }
      if (servo04SP[i] > servo04SP[i + 1]) {
        for ( int j = servo04SP[i]; j >= servo04SP[i + 1]; j--) {
          servo04.write(j);
          delay(speedDelay);
        }
      }
      if (servo04SP[i] < servo04SP[i + 1]) {
        for ( int j = servo04SP[i]; j <= servo04SP[i + 1]; j++) {
          servo04.write(j);
          delay(speedDelay);
        }
      }

      // Servo 5
      if (servo05SP[i] == servo05SP[i + 1]) {
      }
      if (servo05SP[i] > servo05SP[i + 1]) {
        for ( int j = servo05SP[i]; j >= servo05SP[i + 1]; j--) {
          servo05.write(j);
          delay(speedDelay);
        }
      }
      if (servo05SP[i] < servo05SP[i + 1]) {
        for ( int j = servo05SP[i]; j <= servo05SP[i + 1]; j++) {
          servo05.write(j);
          delay(speedDelay);
        }
      }

      // Servo 6
      if (servo06SP[i] == servo06SP[i + 1]) {
      }
      if (servo06SP[i] > servo06SP[i + 1]) {
        for ( int j = servo06SP[i]; j >= servo06SP[i + 1]; j--) {
          servo06.write(j);
          delay(speedDelay);
        }
      }
      if (servo06SP[i] < servo06SP[i + 1]) {
        for ( int j = servo06SP[i]; j <= servo06SP[i + 1]; j++) {
          servo06.write(j);
          delay(speedDelay);
        }
      }
    }
  }
}
