const unsigned long tiempoMuestra = 86400000; // Tiempo en milisegundos para la muestra del sensor, luego de 1 día tratará de capturar datos


const unsigned long tiempoEspera = 10000; // Tiempo en milisegundos para esperar antes de reintentar la captura (si hay errores se esperan 10 segundos antes de volver a intentar)


unsigned long tiempoUltimaMuestra = 0; // Variable para almacenar el tiempo de la última muestra realizada

// Estados de la máquina
enum Estado {
  APAGADO,
  ESPERANDO_MUESTRA,
  TOMANDO_MUESTRA,
  MUESTRA_EXITOSA,
  MUESTRA_FALLIDA
};

Estado estadoActual; // Seteamos el estado inicial

////////////////////
// E0 - Esperando //
////////////////////

void setup() {
  pinMode(ledPin, OUTPUT); 
  estadoActual = APAGADO; // Se define el estado como apagado
}

void loop() {
  switch (estadoActual) {
    case APAGADO:
      // Apagar el LED
      digitalWrite(ledPin, LOW);

      // Verificar si ha pasado suficiente tiempo para realizar una muestra
      if (millis() - tiempoUltimaMuestra >= tiempoMuestra) {
        
        estadoActual = TOMANDO_MUESTRA; // Pasar al estado de toma de muestra
      }
      break;

    case ESPERANDO_MUESTRA:
      
      delay(tiempoEspera); // Esperar antes de intentar capturar nuevamente
      estadoActual = TOMANDO_MUESTRA; // Pasar al estado de toma de muestra
      break;

    case TOMANDO_MUESTRA:
      
      if (capturarDatosSensor()) { // Realizar la captura de datos del sensor
        estadoActual = MUESTRA_EXITOSA; // Muestra exitosa
      } else {
        estadoActual = MUESTRA_FALLIDA; // Falló la captura de muestras
      }
      break;

    ///////////////////////
    // E1 - Encender LED //
    ///////////////////////

    case MUESTRA_EXITOSA:
      // Encender el LED durante 5 segundos
      digitalWrite(ledPin, HIGH);
      delay(5000);
      digitalWrite(ledPin, LOW);

      
      tiempoUltimaMuestra = millis(); // Actualizar el tiempo de la última muestra realizada
      estadoActual = APAGADO; // Volver al estado de apagado para esperar la próxima muestra
      break;

    case MUESTRA_FALLIDA:
      tiempoUltimaMuestra = millis(); // Actualizar el tiempo de la última muestra realizada
      estadoActual = ESPERANDO_MUESTRA; // Volver al estado de espera para intentar capturar nuevamente
      break;
  }
}

bool capturarDatosSensor() {
  // Simulación de una captura exitosa para el ejemplo
  return true;
}
