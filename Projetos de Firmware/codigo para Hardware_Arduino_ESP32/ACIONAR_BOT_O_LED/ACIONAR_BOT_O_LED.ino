int bot1=7;//determina o botão a uma entrada do arduino

int led1=8;//determina a LED a uma entrada do arduino
 
  
void setup()
{
  pinMode(bot1, INPUT);//determina que o botão é a entrada
  
  pinMode(led1, OUTPUT);//determina que a LED é a saida 
  
}

void loop()
{

 
  if(7==1){digitalWrite(led1, 1);} //se a entrada 7 receber sinal alto, então acenda a LED 
 

  else{digitalWrite (led1,0);}// se não receber, então ñ acenda a LEDint bot1=8;
   
}
