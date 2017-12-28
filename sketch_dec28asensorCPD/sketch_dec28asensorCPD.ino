// && = E/AND
// || = OU/OR
//Sensor temperetura

const int sensor_temperatura = A0;
const int botao1 = 6;
const int botao2 = 5;

int leitura_sensor;
float temperatura;
int vermelho = 8;
int amarelo = 9;
int verde = 10;
int buzina = 7;
int estadodobotao1 = LOW;
int estadodobotao2 = LOW;

void setup() {
  analogReference (INTERNAL);
  Serial.begin(9600);

  pinMode (verde, OUTPUT);
  pinMode  (amarelo, OUTPUT);
  pinMode (vermelho, OUTPUT);
  pinMode (buzina, OUTPUT);
  pinMode (botao1, INPUT);
  pinMode (botao2, OUTPUT);
}

void loop() {
  leitura_sensor = analogRead(sensor_temperatura);
  temperatura = leitura_sensor * 0.1075268817204301;
  Serial.print("Temperatura: ");
  Serial.println(temperatura);
  delay(1000);
  
  estadodobotao1 = digitalRead(botao1);
  estadodobotao2 = digitalRead(botao2);

  if (( temperatura < 28 )){
    

    digitalWrite (verde, HIGH);
    digitalWrite (amarelo, LOW);
    digitalWrite (vermelho, LOW);
    noTone (buzina);
  }

  if (( temperatura > 28 && temperatura < 30 )){
    

    digitalWrite (amarelo, HIGH);
    digitalWrite (vermelho, LOW);
    digitalWrite (verde, LOW);
    noTone (buzina);
  }

  if ( temperatura > 30 ){
    

    digitalWrite (vermelho, HIGH);
    digitalWrite (amarelo, LOW);
    digitalWrite (verde, LOW);
    tone (buzina, 1000);
  }

 if (estadodobotao2 == HIGH){
  
  digitalWrite (verde, HIGH); 
  digitalWrite (amarelo, LOW);
  digitalWrite (vermelho, LOW);
  noTone (buzina);
  
}

    if (estadodobotao1 == HIGH)
    {
      while (estadodobotao2 == LOW) {
        digitalWrite (vermelho, HIGH);
        digitalWrite (verde, LOW);
        digitalWrite (amarelo, LOW);
        tone (buzina, 900);
        estadodobotao2 = digitalRead(botao2);

      }
    }
  }

  



