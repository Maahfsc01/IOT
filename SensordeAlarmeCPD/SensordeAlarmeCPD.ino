// && = E/AND
// || = OU/OR
//Sensor temperetura

const int sensor_temperatura = A0;
const int botao1_liga = 6;
const int botao2_desliga = 5;

int leitura_sensor;
float temperatura;
int vermelho = 8;
int amarelo = 9;
int verde = 10;
int buzina = 7;
int estadodobotao1_liga = LOW;
int estadodobotao2_desliga = LOW;

void setup() {
  analogReference (INTERNAL);
  Serial.begin(9600);

  pinMode (verde, OUTPUT);
  pinMode (amarelo, OUTPUT);
  pinMode (vermelho, OUTPUT);
  pinMode (buzina, OUTPUT);
  pinMode (botao1_liga, INPUT);
  pinMode (botao2_desliga, OUTPUT);
}
// RESUMIR CÓDIGO 
void liga_alarme()
{
    digitalWrite (verde, LOW);
    digitalWrite (amarelo, LOW);
    digitalWrite (vermelho, HIGH);
    tone (buzina, 500);
    
}

void desliga_alarme_amarelo()
{
    digitalWrite (verde, LOW);
    digitalWrite (amarelo, HIGH);
    digitalWrite (vermelho, LOW);
  noTone (buzina);
    
}

void desliga_alarme_verde()
{
digitalWrite (verde, HIGH);
digitalWrite (amarelo, LOW);
digitalWrite (vermelho, LOW);
noTone (buzina);
    
}


void loop() {
  leitura_sensor = analogRead(sensor_temperatura);
  temperatura = leitura_sensor * 0.1075268817204301;
  Serial.print("Temperatura: ");
  Serial.println(temperatura);
  delay(1000);
  
  estadodobotao1_liga = digitalRead(botao1_liga);
  estadodobotao2_desliga = digitalRead(botao2_desliga);

  if (( temperatura <= 28 )){
    
    desliga_alarme_verde();
   
  }

  if (( temperatura > 28 && temperatura < 30 )){
    

    desliga_alarme_amarelo();
  }

  if ( temperatura >= 30 ){
    

    liga_alarme();
  }

 if (estadodobotao2_desliga == HIGH){
  
  desliga_alarme_verde();
  
}

    if (estadodobotao1_liga == HIGH)
    {
      while (estadodobotao2_desliga == LOW) {
        digitalWrite (vermelho, HIGH);
        digitalWrite (verde, LOW);
        digitalWrite (amarelo, LOW);
        tone (buzina, 900);
        estadodobotao2_desliga = digitalRead(botao2_desliga);

      }
    }
  }

  



