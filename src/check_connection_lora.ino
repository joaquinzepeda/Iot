int flag_B1 = 0;
int count_t1 = 0;
int count_E1 = 0;
int E_1 = 0;


void check_connection_lora(){
    enum Connection_Lora{
        COUNT,
        CHECKING_CONNECTION,
        CONNECTION_SUCCESSFUL,
        CONNECTION_FAILED,
    };

    Connection_Lora currentState;

    //////////////////////////////
    // E1 - CHECKING CONNECTION //
    //////////////////////////////
    switch (currentState)
    {
    case CHECKING_CONNECTION:

        if (flag_B1 == 1){
            currentState = CONNECTION_SUCCESSFUL;
            count_E1 = 0;
            E_1 = 0;
        }
        else{
            currentState = COUNT;
        }
        break;

    //////////////////
    //  E2 - COUNT  //
    //////////////////
    case COUNT:
        count_t1 ++;
        count_E1 ++;
        if ((count_t1 > 1000) && (count_E1 = 10)){
            currentState = CONNECTION_FAILED;
            count_t1 = 0;
            count_E1 = 0;
            E_1 = 1;
        }

        else if ((count_t1 > 1000) && (E_1 != 10)){
            currentState = CHECKING_CONNECTION;
            count_t1 = 0;
        }

        else{
            currentState = COUNT;
        }

        break;

    //////////////////////
    //  E2 - SUCCESFUL  //
    //////////////////////
    case CONNECTION_SUCCESSFUL:
        count_t1 = 0;
        count_E1 = 0;
        E_1 = 0;
        break;
    }
}