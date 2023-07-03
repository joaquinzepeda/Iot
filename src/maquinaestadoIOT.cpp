
const int SEGUNDO = 10000;  // Duración de 10 segundo.
int R = 0;                // Variable R para indicar si se riega o no.

// Posbles estados
enum Estado {
  CHEQUEAR_TEMPERATURA,
  CHEQUEAR_HUMEDAD,
  ESPERA
};

Estado estadoActual = CHEQUEAR_TEMPERATURA;


void loop() {
  switch (estadoActual) {

    //////////////////////////////
    // E1 - CHECKING TEMPERATURE //
    //////////////////////////////
    case CHEQUEAR_TEMPERATURA:
      if (chequearTemperatura() == 1) {
        estadoActual = CHEQUEAR_HUMEDAD;
      } else {
        estadoActual = ESPERA;
      }
      break;

    //////////////////////////////
    // E2 - CHECKING HUMIDITY //
    //////////////////////////////

    case CHEQUEAR_HUMEDAD:
      if (chequearHumedad() == 1) {
        R = 1;
        estadoActual = ESPERA;
      } else {
        estadoActual = CHEQUEAR_TEMPERATURA;
      }
      break;

    
    //////////////////////////////
    // E3 - WAITING //
    //////////////////////////////
    case ESPERA:
      esperar();
      estadoActual = CHEQUEAR_TEMPERATURA; //vuelve al estado de chequeo de temperatura
      break;
  }
}

void esperar() {
  delay(SEGUNDO);  // Pausa durante 10 segundo
}