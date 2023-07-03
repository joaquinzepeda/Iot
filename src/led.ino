


void led0(){
  
  switch (stateLed0){
    
    //////////////////
    // E0 - LED OFF //
    //////////////////
    
    case 0:

      digitalWrite(LED, LOW);       // El pin del led en OFF

      if ( flagB0 ){                //
        stateLed0 = 1;              //
      }
      else if ( flagB1 ){           //
        stateLed0 = 3;              //
      }
      else{                         //
        stateLed0 = 0;              //
      }
    break;

    ///////////////////////
    // E1 - LED ON 200MS //
    ///////////////////////

    case 1:
      digitalWrite(LED, HIGH);        //
      countLed0++;                    //

      if ( flagB0 &&(countLed0 > millis200) ){        //
        stateLed0 = 2;                              //
      }
      else if( !flagB0 && (countLed0 > millis200) ){   //
        stateLed0 = 0;                              //   
      }
      else{                                         //
        stateLed0 = 1;                              //
      }

    break;

    ////////////////////////
    // E2 - RESET COUNTER //
    ////////////////////////

    case 2:
      digitalWrite(LED, HIGH);  //
      countLed0 = 0;            //
      
      stateLed0 = 1;            //
    break;

    case 3:
    break;

    case 4:
    break;

    default:
    break;
  
  }
}