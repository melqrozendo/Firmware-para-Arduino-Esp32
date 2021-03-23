/*
Projeto Sistemas Microcontrolados
Microcontrolador ESP32
Sensor de Fluxo
Display LCD 16x2
*/


//definicao do pino do sensor e de interrupcao
const int INTERRUPCAO_SENSOR = 35; //interrupt = 0 equivale ao pino digital 2

const int PINO_SENSOR = 35;

//definicao da variavel de contagem de voltas
unsigned long contador = 0;

//definicao do fator de calibracao para conversao do valor lido
const float FATOR_CALIBRACAO = 4.5;

//definicao das variaveis de fluxo e volume
float fluxo = 0;
float volume = 0;
float volume_total = 0;

//definicao da variavel de intervalo de tempo
unsigned long tempo_antes = 0;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>display lcd1
//Programa: Display LCD 16x2 e modulo I2C
//Autor: Arduino e Cia

//#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x27,16,2);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>botão1
//Pinos ligado no botão
int btn1 = 18;
int btn2 = 19;
int btn3 = 17;

//////////////////////////////////////////////////////////////////////////////////// void setup [inicio]
void setup(){
  
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>sensor de fluxo2
  //inicializacao do monitor serial
 
  Serial.begin(115200);//modificar para 115200

  //mensagem de inicializacao
  //Serial.println("Medidor de Fluxo e Volume de Liquidos\n");

  //configuracao do pino do sensor como entrada em nivel logico alto
  pinMode(PINO_SENSOR, INPUT_PULLUP);
  
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>display lcd2
  lcd.init();
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>botão2
//Seta os pinos dos botões como entrada
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
  //:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
    Serial.println("-------------------------------------------------------------------");
    Serial.println("Para realizar o MONITORAMENTO DE VAZÃO,");//link com o delay final
    Serial.println("siga as INSTRUÇOES:");
    Serial.println("1 - Para [INICIAR] ----> pressione o [Botão1]");
    Serial.println("2 - Para [FINALIZAR SEM IMPRIMIR] ----> pressione o [Botão2]");
    Serial.println("3 - Para [IMPRIMIR E FINALIZAR] ----> pressione o [Botão3]");
    Serial.println("-------------------------------------------------------------------");
}
//////////////////////////////////////////////////////////////////////////////////// void setup [final]
float vazao_final;
float consumo;
//////////////////////////////////////////////////////////////////////////////////// void loop [inicio]
void loop() {

//:
if (digitalRead(btn1) == HIGH) //Caso o botão 1 foi pressionado ou o fluxo for maior que zero

  {
    lcd.setBacklight(HIGH);
    
    Serial.println("-------------------------------------------------------------------");
    Serial.println("Para realizar o MONITORAMENTO DE VAZÃO,");//link com o delay final
    Serial.println("siga as INSTRUÇOES:");
    Serial.println("1 - Para [INICIAR] ----> pressione o [Botão1]");
    Serial.println("2 - Para [FINALIZAR SEM IMPRIMIR] ----> pressione o [Botão2]");
    Serial.println("3 - Para [IMPRIMIR E FINALIZAR] ----> pressione o [Botão3]");
    Serial.println("-------------------------------------------------------------------");
    Serial.println("<INICIALIZANDO>");
    Serial.println("------------------------------------");
    volume_total = 0;
    fluxo= 0;
    //delay(1000);
    lcd.clear();//tela branca
    delay(500);//passa 0.5 seg
      lcd.setCursor(0,0); // tela amostra START
      lcd.print("<INICIALIZANDO>");
      lcd.setCursor(0,1);
      lcd.print(" ");
      delay(2000);//passa 1 seg
      //:
      Serial.println("<INICIALIZE OPERAÇÃO>");
      lcd.clear();//tela branca
      lcd.setCursor(0,0);
      lcd.print("<INICIALIZE>");
      lcd.setCursor(0,1);
      lcd.print("<OPERACAO>");
      delay(1000);
      Serial.println("------------------------------------");
      lcd.clear();
      //:
      delay(1000);//delay final
    
}//final da condição IF do botão1
//:

 //<< 

  lcd.setCursor(0,0);
  lcd.print("Fluxo de:");
  lcd.print(fluxo);//////////////////////imprimindo no display lcd linha 1

  lcd.setCursor(0,1);
  lcd.print("Volume:");
  lcd.print(volume_total);///////////////imprimindo no display lcd linha 2
 
 //<< 

//::
if (digitalRead(btn2) == HIGH) //Caso o botão 2 foi pressionado ou o volume foi igual a 5 L faça:

  {
   
   Serial.println("------------------------------------");
    volume_total = 0;
    fluxo= 0;
    //delay(1000);
    lcd.clear();
    delay(1000);
      lcd.setCursor(0,0);
      lcd.print("<OPERACAO> ");
      lcd.setCursor(0,1);
      lcd.print("<FINALIZADA> ");
   delay(1000);
    lcd.clear();
    delay(1000);
    lcd.setBacklight(LOW);
     Serial.println("<OPERAÇÃO FINALIZADA>");
     Serial.println("------------------------------------");
     Serial.println();
}//final da condição IF do botão2
//::

//:::
if(digitalRead(btn3) == HIGH){

  Serial.println("------------------------------------");
  Serial.println("IMPRIMINDO DADOS...");
  //:
  lcd.clear();
    //delay(1000);
      lcd.setCursor(0,0);
      lcd.print("IMPRIMINDO DADOS");
      lcd.setCursor(0,1);
      lcd.print(" ");
   delay(1000);
    lcd.clear();
    //:
  delay(2000);//passa 1 seg e exibe valores de vazao, volume e consumo
if (fluxo>=0){
  vazao_final = fluxo;

  Serial.println("------------------------------------");
  Serial.print("Última Vazão lida: ");//ultimo fluxo ou vazão lida
  Serial.print( vazao_final);
    Serial.println(" L/min");
  Serial.println("------------------------------------");
  //:
  lcd.clear();
    //delay(1000);
      lcd.setCursor(0,0);
      lcd.print("VAZAO FINAL:");
      lcd.print(vazao_final);
      lcd.setCursor(0,1);
      lcd.print("(L/min)");
   delay(1000);
    lcd.clear();
    //:
 delay(1000);//passa 1 seg
  
  } 

if (volume_total>=0){

  
  Serial.println("------------------------------------");
  Serial.print("Volume Máx: ");
  Serial.print( volume_total);
    Serial.println(" L");
  Serial.println("------------------------------------");
  //:
  lcd.clear();
    //delay(1000);
      lcd.setCursor(0,0);
      lcd.print("VOLUME: ");
      lcd.print(volume_total);
      lcd.setCursor(0,1);
      lcd.print("(Litros)");
   delay(1000);
    lcd.clear();
    //:
 delay(1000);//passa 0.5 seg
  
  } 

if (volume_total>=0){
  consumo = volume_total*0.4;//o custo de 1Litro de agua consumida vale R$0,40
  
  Serial.println("------------------------------------");
  Serial.print("Consumo:");
  Serial.print(" R$");
  Serial.print( consumo);
    Serial.println(" ");
  Serial.println("------------------------------------");
  //:
  lcd.clear();
    //delay(1000);
      lcd.setCursor(0,0);
      lcd.print("CONSUMO (R$) ");
      lcd.setCursor(0,1);
      lcd.print(consumo);
      lcd.print(" ");
   delay(1000);
    lcd.clear();
    //:
 delay(1000);//passa 0.5 seg
  
  } 

  Serial.println("DADOS IMPRIMIDOS...");
  Serial.println("------------------------------------");
    volume_total = 0;
    fluxo= 0;
    //delay(1000);
    lcd.clear();
    delay(1000);
      lcd.setCursor(0,0);
      lcd.print("<OPERACAO> ");
      lcd.setCursor(0,1);
      lcd.print("<FINALIZADA> ");
   delay(1000);
    lcd.clear();
    delay(1000);
    lcd.setBacklight(LOW);
     Serial.println("<OPERAÇÃO FINALIZADA>");
     Serial.println("------------------------------------");
     Serial.println();
}//final do IF do botão3
//:::

//::sensor de fluxo3
  //executa a contagem de pulsos uma vez por segundo
  if((millis() - tempo_antes) > 1000){

    //desabilita a interrupcao para realizar a conversao do valor de pulsos
    detachInterrupt(INTERRUPCAO_SENSOR);

    //conversao do valor de pulsos para L/min
    fluxo = ((1000.0 / (millis() - tempo_antes)) * contador) / FATOR_CALIBRACAO;

    if (fluxo > 0) {//quando o fluxo for maior que zero começa a mostrar no monitor serial
    
    //exibicao do valor de fluxo
    Serial.print("Fluxo de: ");
    Serial.print(fluxo);
    Serial.println(" L/min");

    //calculo do volume em L passado pelo sensor
    volume = fluxo / 60;

    //armazenamento do volume
    volume_total += volume;

    //exibicao do valor de volume
    Serial.print("Volume: ");
    Serial.print(volume_total);
    Serial.println(" L");
    Serial.println();
    }
   
    //reinicializacao do contador de pulsos
    contador = 0;

    //atualizacao da variavel tempo_antes
    tempo_antes = millis();

    //contagem de pulsos do sensor
    attachInterrupt(INTERRUPCAO_SENSOR, contador_pulso, FALLING);
    }
   

}//final do void loop
//:: void loop [final]

///:: void contador de pulsos [inicio]
//funcao chamada pela interrupcao para contagem de pulsos
void contador_pulso() {
  
  contador++; 
}
///:: void contador de pulsos [final]
