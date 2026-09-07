const int ledVerdeI = 13;
const int ledVerdeII = 12;
const int ledAmareloI = 11;
const int ledAmareloII = 10;
const int ledVermelhoI = 9;
const int ledVermelhoII = 8;
const int pot = A0;
const int buzzer = 2;
void setup() {
  pinMode(ledVerdeI, OUTPUT);
  pinMode(ledVerdeII, OUTPUT);
  pinMode(ledAmareloI, OUTPUT);
  pinMode(ledAmareloII, OUTPUT);
  pinMode(ledVermelhoI, OUTPUT);
  pinMode(ledVermelhoII, OUTPUT);
  pinMode(pot, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int valorRecebido = analogRead(pot);
  float tensao = valorRecebido * (5.0 / 1023.0);
  int faixa = map(valorRecebido, 0, 1024, 0, 6);
  ligarLeds(faixa, buzzer);
  tocarBuzzer(faixa);
  Serial.print("Tensao: ");
  Serial.println(tensao, 2);
  delay(1000);
}
void ligarLeds(int faixa, int buzzer){
  if(faixa == 0){
      digitalWrite(ledVerdeI, HIGH);
      digitalWrite(ledVerdeII, LOW);
      digitalWrite(ledAmareloI, LOW);
      digitalWrite(ledAmareloII, LOW);
      digitalWrite(ledVermelhoI, LOW);
      digitalWrite(ledVermelhoII, LOW);
  }
  else if(faixa == 1){
      digitalWrite(ledVerdeI, HIGH);
      digitalWrite(ledVerdeII, HIGH);
      digitalWrite(ledAmareloI, LOW);
      digitalWrite(ledAmareloII, LOW);
      digitalWrite(ledVermelhoI, LOW);
      digitalWrite(ledVermelhoII, LOW);
  }
  else if(faixa == 2){
      digitalWrite(ledVerdeI, HIGH);
      digitalWrite(ledVerdeII, HIGH);
      digitalWrite(ledAmareloI, HIGH);
      digitalWrite(ledAmareloII, LOW);
      digitalWrite(ledVermelhoI, LOW);
      digitalWrite(ledVermelhoII, LOW);
  }
  else if(faixa == 3){
      digitalWrite(ledVerdeI, HIGH);
      digitalWrite(ledVerdeII, HIGH);
      digitalWrite(ledAmareloI, HIGH);
      digitalWrite(ledAmareloII, HIGH);
      digitalWrite(ledVermelhoI, LOW);
      digitalWrite(ledVermelhoII, LOW);
  }
  else if(faixa == 4){
      digitalWrite(ledVerdeI, HIGH);
      digitalWrite(ledVerdeII, HIGH);
      digitalWrite(ledAmareloI, HIGH);
      digitalWrite(ledAmareloII, HIGH);
      digitalWrite(ledVermelhoI, HIGH);
      digitalWrite(ledVermelhoII, LOW);
  }
  else if(faixa == 5){
      digitalWrite(ledVerdeI, HIGH);
      digitalWrite(ledVerdeII, HIGH);
      digitalWrite(ledAmareloI, HIGH);
      digitalWrite(ledAmareloII, HIGH);
      digitalWrite(ledVermelhoI, HIGH);
      digitalWrite(ledVermelhoII, HIGH);
  }
}
void tocarBuzzer(int faixa){
  switch (faixa) {
  case 0:
    noTone(buzzer);
    break;
  case 1:
    tone(buzzer, 262); // Nota Dó
    break;
  case 2:
    tone(buzzer, 330); // Nota Mi
    break;
  case 3:
    tone(buzzer, 392); // Nota Sol
    break;
  case 4:
    tone(buzzer, 523); // Nota Dó (oitava acima)
    break;
  case 5:
    tone(buzzer, 659);
    break;
  case 6:
    tone(buzzer, 784);
    break;
}
}
