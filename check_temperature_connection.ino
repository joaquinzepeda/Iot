int max_tries = 10;                                 // Definicion de maximos intentos de revision de conexion
int flag_B4 = 0;                                    // Definicion de flag de estado de conexion
int count_t4 = 0;                                   // Definicion de contador t1
int count_E4 = 0;                                   // Definicion de contador de intentos fallidos
int E_4 = 0;                                        // Definicion de flag de error de conexion


void check_connection_lora(){                       // Se definen los estados
    enum Connection_Lora{
        COUNT,                                      // Estado de contar
        CHECKING_CONNECTION,                        // Estado de revisar conexion
        CONNECTION_SUCCESSFUL,                      // Estado de conexion exitosa
        CONNECTION_FAILED,                          // Estado de conexion fallida
    };

    Connection_Lora currentState;

    //////////////////////////////
    // E1 - CHECKING CONNECTION //
    //////////////////////////////
    switch (currentState)
    {
    case CHECKING_CONNECTION:

        if (flag_B4 == 1){                          // Si hay conexion exitosa
            currentState = CONNECTION_SUCCESSFUL;   // Se cambia el estado a conexion exitosa
            count_E4 = 0;                           // Se reinicia el contador de intentos fallidos
            E_4 = 0;                                // Se lleva el flag de error a 0
        }
        else{                                       // En el caso contrario
            currentState = COUNT;                   // Se va al estado de contar
        }
        break;

    //////////////////
    //  E2 - COUNT  //
    //////////////////
    case COUNT:                                     
        count_t4 ++;                                // Se cuenta una iteracion en tiempo
        count_E4 ++;                                // Se cuenta un intento fallido
        if ((count_t4 > 1000) && (count_E4 = max_tries)){  // Si se supera el contador y se alcanza el numero maximo de intentos fallidos
            currentState = CONNECTION_FAILED;       // Se va al estado de conexion fallida
            count_t4 = 0;                           // Se reinicia el contador de tiempo
            count_E4 = 0;                           // Se reinicia el contador de intentos fallidos
            E_4 = 1;                                // Se lleva el flag de error a 1
        }

        else if ((count_t4 > 1000) && (E_4 != max_tries)){ // Si se supera el contador y no se alcanza el numero maximo de intentos fallidos
            currentState = CHECKING_CONNECTION;     // Se va al estado de revisar conexion
            count_t4 = 0;                           // Se reinicia el contador de tiempo
        }

        else{                                       // En el caso contrario
            currentState = COUNT;                   // Se va al estado de contar
        }

        break;

    ///////////////////////
    //  E2 - SUCCESSFUL  //
    ///////////////////////
    case CONNECTION_SUCCESSFUL:
        count_t4 = 0;                               // Se reinicia el contador de tiempo
        count_E4 = 0;                               // Se reinicia el contador de intentos fallidos
        E_4 = 0;                                    // Se lleva el flag de error a 0
        break;
    }
}