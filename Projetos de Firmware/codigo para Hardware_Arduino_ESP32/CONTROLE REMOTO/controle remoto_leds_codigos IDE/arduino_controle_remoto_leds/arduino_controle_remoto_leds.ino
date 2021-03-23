//projeto de como acender 3 leds usando o controle remoto
//
//
//
#include <IRremote.h> //INCLUSÃO DE BIBLIOTECA

int RECV_PIN = 2; //PINO DIGITAL UTILIZADO PELO FOTORRECEPTOR KY-022

IRrecv irrecv(RECV_PIN); //PASSA O PARÂMETRO PARA A FUNÇÃO irrecv

const int ledVerde = 8; //PINO DIGITAL UTILIZADO PELO LED VERMELHO
const int ledAmarelo = 9; //PINO DIGITAL UTILIZADO PELO LED VERDE
const int ledVermelho = 10; //PINO DIGITAL UTILIZADO PELO LED AMARELO

long int codTecla1 = 16724175; //CÓDIGO DA TECLA 1 (ALTERE PARA O CÓDIGO DECIMAL QUE VOCÊ CAPTUROU)
long int codTecla2 = 16718055; //CÓDIGO DA TECLA 2 (ALTERE PARA O CÓDIGO DECIMAL QUE VOCÊ CAPTUROU)
long int codTecla3 = 16743045; //CÓDIGO DA TECLA 3 (ALTERE PARA O CÓDIGO DECIMAL QUE VOCÊ CAPTUROU)

int stLedVermelho = 0; //VARIÁVEL QUE CONTROLA O ESTADO DO LED VERMELHO (LIGADO / DESLIGADO)
int stLedVerde = 0; //VARIÁVEL QUE CONTROLA O ESTADO DO LED VERDE (LIGADO / DESLIGADO)
int stLedAmarelo = 0; //VARIÁVEL QUE CONTROLA O ESTADO DO LED AMARELO (LIGADO / DESLIGADO)

decode_results results; //VARIÁVEL QUE ARMAZENA OS RESULTADOS (SINAL IR RECEBIDO)

void setup(){
  irrecv.enableIRIn(); //INICIALIZA A RECEPÇÃO DE SINAIS IR
  pinMode(ledVermelho, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(ledVerde, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(ledAmarelo, OUTPUT); //DEFINE O PINO COMO SAÍDA
}

void loop() {
  //CAPTURA O SINAL IR
  if (irrecv.decode(&results)) {
    if((results.value == codTecla1) && (stLedVerde == 0)){ //SE O CÓDIGO IR CAPTURADO FOR IGUAL A codTecla1 E A
    //VARIÁVEL stLedVerde FOR IGUAL A 0, FAZ
        digitalWrite(ledVerde, HIGH); //LIGA O LED VERDE
        stLedVerde = 1; //VARIÁVEL RECEBE O VALOR 1
    }else{//SENÃO, FAZ
      if((results.value == codTecla1) && (stLedVerde == 1)){ ///SE O CÓDIGO IR CAPTURADO FOR IGUAL A codTecla1 E A
    //VARIÁVEL stLedVerde FOR IGUAL A 1, FAZ
            digitalWrite(ledVerde, LOW); //DESLIGA O LED VERDE
            stLedVerde = 0; //VARIÁVEL RECEBE O VALOR 0
      }
    }

    if((results.value == codTecla2) && (stLedAmarelo == 0)){ //SE O CÓDIGO IR CAPTURADO FOR IGUAL A codTecla2 E A
    //VARIÁVEL stLedAmarelo FOR IGUAL A 0, FAZ
        digitalWrite(ledAmarelo, HIGH); //LIGA O LED AMARELO
        stLedAmarelo = 1; //VARIÁVEL RECEBE O VALOR 1
    }else{//SENÃO, FAZ
      if((results.value == codTecla2) && (stLedAmarelo == 1)){ ///SE O CÓDIGO IR CAPTURADO FOR IGUAL A codTecla2 E A
    //VARIÁVEL stLedAmarelo FOR IGUAL A 1, FAZ
            digitalWrite(ledAmarelo, LOW); //DESLIGA O LED AMARELO
            stLedAmarelo = 0; //VARIÁVEL RECEBE O VALOR 0
      }
    }

    if((results.value == codTecla3) && (stLedVermelho == 0)){ //SE O CÓDIGO IR CAPTURADO FOR IGUAL A codTecla3 E A
    //VARIÁVEL stLedVermelho FOR IGUAL A 0, FAZ
        digitalWrite(ledVermelho, HIGH); //LIGA O LED VERMELHO
        stLedVermelho = 1; //VARIÁVEL RECEBE O VALOR 1
    }else{//SENÃO, FAZ
      if((results.value == codTecla3) && (stLedVermelho == 1)){ ///SE O CÓDIGO IR CAPTURADO FOR IGUAL A codTecla3 E A
    //VARIÁVEL stLedVermelho FOR IGUAL A 1, FAZ
            digitalWrite(ledVermelho, LOW); //DESLIGA O LED VERMELHO
            stLedVermelho = 0; //VARIÁVEL RECEBE O VALOR 0
      }
    }
    irrecv.resume(); //AGUARDA O RECEBIMENTO DE UM NOVO SINAL IR
  }//fecha a captura de sinal
  delay(10); //INTERVALO DE 10 MILISSEGUNDOS
}
