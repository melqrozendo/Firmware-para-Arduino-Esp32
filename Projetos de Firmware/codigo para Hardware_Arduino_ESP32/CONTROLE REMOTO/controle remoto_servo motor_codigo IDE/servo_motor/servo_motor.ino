//
//projeto: de controlar servo motor por meio do controle remoto 
//ao acender e desligar a led



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>servo1
#include <Servo.h>
 
#define SERVO 6 // Porta Digital 6 PWM
 
Servo s; // Variável Servo
int pos; // Posição Servo
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>controle1
#include <IRremote.h> //INCLUSÃO DE BIBLIOTECA

int RECV_PIN = 2; //PINO DIGITAL UTILIZADO PELO FOTORRECEPTOR KY-022 (ARDUINO 2_ESP32_34)

IRrecv irrecv(RECV_PIN); //PASSA O PARÂMETRO PARA A FUNÇÃO irrecv

const int ledVerde = 8; //PINO DIGITAL UTILIZADO PELO LED AZUL (ARDUINO 8_ESP32_39)


long int codTecla1 = 16724175; //CÓDIGO DA TECLA 1 (ALTERE PARA O CÓDIGO DECIMAL QUE VOCÊ CAPTUROU)
//long int codTecla2 = 16718055; //CÓDIGO DA TECLA 2 (ALTERE PARA O CÓDIGO DECIMAL QUE VOCÊ CAPTUROU)



int stLedVerde = 0; //VARIÁVEL QUE CONTROLA O ESTADO DO LED VERDE (LIGADO / DESLIGADO)


decode_results results; //VARIÁVEL QUE ARMAZENA OS RESULTADOS (SINAL IR RECEBIDO)

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>void setup [inicio] 
void setup ()
{
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>servo2  
  s.attach(SERVO);
  Serial.begin(9600);
  s.write(0); // Inicia motor posição zero
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>controle2
 irrecv.enableIRIn(); //INICIALIZA A RECEPÇÃO DE SINAIS IR
  pinMode(ledVerde, OUTPUT); //DEFINE O PINO COMO SAÍDA 
}//final do void setup
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>void setup [final]  
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>void loop [inicio] 
void loop()
{
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>servo3  
  //for(pos = 0; pos < 180; pos++)
  //{
    //s.write(pos);
  //delay(15);
  //}
//delay(1000);
  //for(pos = 180; pos >= 0; pos--)
  //{
    //s.write(pos);
   // delay(15);
 // }
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>controle3
//CAPTURA O SINAL IR
  if (irrecv.decode(&results)) {
    if((results.value == codTecla1) && (stLedVerde == 0)){ //SE O CÓDIGO IR CAPTURADO FOR IGUAL A codTecla1 E A
    //VARIÁVEL stLedVerde FOR IGUAL A 0, FAZ
        digitalWrite(ledVerde, HIGH); //LIGA O LED VERDE
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>obs1[inicio]: colocar componente que será contolado[servo]
for(pos = 0; pos < 180; pos++)
  {
    s.write(pos);
  delay(15);
  }
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>obs1[final]
      stLedVerde = 1; //VARIÁVEL RECEBE O VALOR 1
       
}//final da condição IF

   else{//SENÃO, FAZ
      if((results.value == codTecla1) && (stLedVerde == 1)){ ///SE O CÓDIGO IR CAPTURADO FOR IGUAL A codTecla1 E A
    //VARIÁVEL stLedVerde FOR IGUAL A 1, FAZ
            digitalWrite(ledVerde, LOW); //DESLIGA O LED VERDE
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>obs2 [inicio]: colocar componente que será contolado [servo]
for(pos = 180; pos >= 0; pos--)
  {
    s.write(pos);
    delay(15);
  }
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>obs2 [final]:
       stLedVerde = 0; //VARIÁVEL RECEBE O VALOR 0
            }//final do 2° IF
         }//final da condição ELSE
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>1°parte final [fechamento da condicional IF]
    irrecv.resume(); //AGUARDA O RECEBIMENTO DE UM NOVO SINAL IR
     }//final de toda a CONDICIONAL IF
 
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>2°parte final [delay]
  delay(10); //INTERVALO DE 10 MILISSEGUNDOS
    
}//final do void loop
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>void loop [final]
