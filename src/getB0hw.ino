
void getB0hw(){
	switch( stateB0hw ){
		/////////////////////////
		// E0 - wait for input //
		/////////////////////////   
		case 0:
			b0hw = digitalRead(B0x);	// toma muestra de B0
			flagB0 = 0;				// boton no presionado
			countB0hw = 0;			// reinicio contador
			if (b0hw){				// Si se aprieta b0
				stateB0hw = 1;		// pasa a estado 1
			}
			else {					// Si no,
				stateB0hw = 0;		// se mantiene en el estado 0
			}
		break;
		/////////////////////////
		// E1 - wait for 200ms //
		/////////////////////////
		case 1:
			flagB0 = 0;				// boton no presionado
			b0hw = digitalRead(B0x);	// toma muestra de B0
			countB0hw++; 			//aumenta en 1 el contador
			
			if (b0hw && (countB0hw >= millis200)){		//Si B0hw sigue presionado y el contador llega a 200 ms
				stateB0hw = 2;						//paso al estado 2
			}
			else if(b0hw &&(countB0hw < millis200)){	//Si el contador aun no llega a 200 ms pero el B0hw sigue presionado
				stateB0hw = 1;						//Me mantengo en el estado 1
			}
			else {									//Si ninguna de las anteriores se cumple
				stateB0hw = 0;						//vuelvo al estado 0
			}			
		break;
		///////////////////////////
		// E2 - boton presionado //
		///////////////////////////
		case 2:
			flagB0 = 1;			// boton presionado
      b0hw = digitalRead(B0x);	// toma muestra de B0

      if (b0hw){
        stateB0hw = 2;
      }
      else{
        stateB0hw = 0;
      }
		break;
		default:
			stateB0hw = 0;
		break;
	}
}