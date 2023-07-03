
unsigned long startTime = 0;    ///< TIEMPO DE INICIO DEL LOOP
unsigned long elapsedTime = 0;  ///< TIEMPO DE LOOP
const int superloop = 10;             ///< Superloop

int stateB0hw;		              ///< estado del boton 0 de hardware
bool flagB0;		                ///< bandera B0 presionado
bool b0hw;			                ///< muestra de B0	

int B0x = 6;			                ///< pin de hardware de B0
int LED = 5;                    ///< pin de hardware de LED

int countB0hw;                  ///< contador B0hw
int millis200 = 200/superloop;  ///constate igual a 200 ms

bool flagB1;

int countLed0;
int stateLed0;

void setup(){

    ////////////
    // SERIAL //
    ////////////
    
    Serial.begin(9600);

    //////////////////////////
    // HARDWARE DECLARATION //
    //////////////////////////
    pinMode(B0, INPUT);
    pinMode(LED, OUTPUT);
}

void loop(){
    startTime = millis();  						// INICIO DE SUPERLOOP
    getB0hw();

    
    elapsedTime = millis() - startTime;  		// TIEMPO DEL SUPERLOOP

    if (elapsedTime < superloop) {     			// SI SOBRA TIEMPO
      delay(superloop - elapsedTime);  		// ESPERA PARA COMPLETAR SUPERLOOP
    }
}