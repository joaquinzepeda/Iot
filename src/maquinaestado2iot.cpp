const int SEGUNDO = 1000;  // Duración de 1 segundo en milisegundos
int RE_1 = 0;              // Variable RE_1 para indicar error
int count_t5 = 0;          // Contador count_t5 para el tiempo de espera
int E_1 = 0;               // Flag de error E_1

enum Estado {
  CHEQUEAR_TEMPERATURA,    // Estado de chequeo de temperatura
  CHEQUEAR_HUMEDAD,        // Estado de chequeo de humedad
  ESPERA,                  // Estado de espera
  CHEQUEAR_ERROR           // Estado de chequeo de error
};

Estado estadoActual = CHEQUEAR_TEMPERATURA;  // Estado actual inicial: CHEQUEAR_TEMPERATURA


void loop() {
  switch (estadoActual) {

    //////////////////////////////
    // E1 - CHECKING TEMPERATURE LECTURE //
    //////////////////////////////
    case CHEQUEAR_TEMPERATURA:
      if (lecturaTemperatura() == 1) {           // Si la temperatura está dentro del rango
        estadoActual = CHEQUEAR_HUMEDAD;         // Ir al estado de CHEQUEAR_HUMEDAD
      } else {
        estadoActual = ESPERA;                    // Ir al estado de ESPERA
      }
      break;

    //////////////////////////////
    // E2 - CHECKING HUMIDITY LECTURE //
    //////////////////////////////

    case CHEQUEAR_HUMEDAD:
      if (lecturaHumedad() == 1) {               // Si la humedad está dentro del rango
        RE_1 = 0;                                // Establecer el flag de error a 0
        count_t5 = 0;                            // Reiniciar el contador count_t5
        estadoActual = CHEQUEAR_ERROR;           // Ir al estado de CHEQUEAR_ERROR
      } else {
        estadoActual = ESPERA;                    // Ir al estado de ESPERA
      }
      break;

    //////////////////////////////
    // E3 - WAITING //
    //////////////////////////////
    case ESPERA:
      esperar();                                // Realizar la función de espera
      estadoActual = CHEQUEAR_ERROR;             // Ir al estado de CHEQUEAR_ERROR
      break;

    //////////////////////////////
    // E3 - CHECKING ERROR //
    //////////////////////////////
    case CHEQUEAR_ERROR:
      if (RE_1 > 10) {                           // Si el valor de RE_1 es mayor a 10
        E_1 = 1;                                 // Establecer el flag de error a 1
      } else {
        estadoActual = CHEQUEAR_TEMPERATURA;      // Volver al estado de CHEQUEAR_TEMPERATURA
      }
      break;
  }
}

void esperar() {
  delay(SEGUNDO);  // Esperar 1 segundo
  RE_1++;              // Incrementar el valor de RE_1

}
