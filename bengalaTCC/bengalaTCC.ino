#include <Ultrasonic.h>

 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic1(4, 5); //Ultrasonic ultrasonic(pino_trigger, pino_echo)
Ultrasonic ultrasonic2(6, 7);

//Variaveis globais das funções
int count, buzzer=8, vibracal1=9; //porta 9. 
float distance1, distance2, distance3, distance4, distance5, distance6;
float v = analogRead(A0);

void setup()
{
  pinMode(buzzer,OUTPUT);//pino 9 saida
  pinMode(vibracal1,OUTPUT); //vibracall, pino 13, saida
 
  
  Serial.begin(9600);
  //5 beep - bengala ligada.
  tone(buzzer,240);
  delay(500);
  tone(buzzer,240);
  delay(500);
  tone(buzzer,240);
  tone(buzzer,240);
  delay(500);
  tone(buzzer,240);
  delay(500);
  
}
 
void loop(){

if(v > 615){ //(615 * 0.0048875855327468)*2 = 6V //615 leitura da porta analógica. //se a bateria estiver com mais de 6V, bengala funcionando.  
//lendo 3 distância sensor de cima.
   distance1 = ultrasonic1.read();//cima
   distance3 = ultrasonic1.read();
   distance4 = ultrasonic1.read();

//lendo 3 distância sensor de baixo.     
   distance2 = ultrasonic2.read();//baixo
   distance5 = ultrasonic2.read();
   distance6 = ultrasonic2.read();

/*45-59*/
    if((distance1 > 59.00) && (distance1 < 70.00)){
      if((distance3 > 59.00) && (distance3 < 70.00)){
        if((distance4 > 59.00) && (distance4 < 70.00)){    
      tone(buzzer,440);//liga sirene. tone(pino, frequencia).
      digitalWrite(vibracal1, HIGH);
      delay(200);
        }
      }
    }
    if((distance2 > 25.00) && (distance2 < 45.00)){
      if((distance5 > 25.00) && (distance5 < 45.00)){
        if((distance6 > 25.00) && (distance6 < 45.00)){    
      tone(buzzer,1440);//liga sirene. tone(pino, frequencia).
      digitalWrite(vibracal1, HIGH);
      delay(200);
        }
      }
    }else{
      digitalWrite(vibracal1, LOW);
      noTone(buzzer);//desliga sirene
      }      
}else{//Bateria com menos de 4V, 3bips! Recarregar.
  tone(buzzer,1999);
  delay(300);
  tone(buzzer,1999);
  delay(300);
  tone(buzzer,1999);
  delay(300);
  }
}


 
