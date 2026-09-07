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
  medidor(faixa);
  Serial.print("Tensao: ");
  Serial.print(tensao, 2);
  Serial.print(" | Faixa: ");
  Serial.println(faixa);
  delay(1000);
}
void medidor(int faixa){
  switch (faixa) {
  case 0:
      digitalWrite(ledVerdeI, HIGH);
      digitalWrite(ledVerdeII, LOW);
      digitalWrite(ledAmareloI, LOW);
      digitalWrite(ledAmareloII, LOW);
      digitalWrite(ledVermelhoI, LOW);
      digitalWrite(ledVermelhoII, LOW);
      noTone(buzzer);
    break;
  case 1:
      digitalWrite(ledVerdeI, HIGH);
      digitalWrite(ledVerdeII, HIGH);
      digitalWrite(ledAmareloI, LOW);
      digitalWrite(ledAmareloII, LOW);
      digitalWrite(ledVermelhoI, LOW);
      digitalWrite(ledVermelhoII, LOW);
      tone(buzzer, 262);
    break;
  case 2:
      digitalWrite(ledVerdeI, HIGH);
      digitalWrite(ledVerdeII, HIGH);
      digitalWrite(ledAmareloI, HIGH);
      digitalWrite(ledAmareloII, LOW);
      digitalWrite(ledVermelhoI, LOW);
      digitalWrite(ledVermelhoII, LOW);
      tone(buzzer, 330);
    break;
  case 3:
      digitalWrite(ledVerdeI, HIGH);
      digitalWrite(ledVerdeII, HIGH);
      digitalWrite(ledAmareloI, HIGH);
      digitalWrite(ledAmareloII, HIGH);
      digitalWrite(ledVermelhoI, LOW);
      digitalWrite(ledVermelhoII, LOW);
      tone(buzzer, 392);
    break;
  case 4:
      digitalWrite(ledVerdeI, HIGH);
      digitalWrite(ledVerdeII, HIGH);
      digitalWrite(ledAmareloI, HIGH);
      digitalWrite(ledAmareloII, HIGH);
      digitalWrite(ledVermelhoI, HIGH);
      digitalWrite(ledVermelhoII, LOW);
      tone(buzzer, 523);
    break;
  case 5:
      digitalWrite(ledVerdeI, HIGH);
      digitalWrite(ledVerdeII, HIGH);
      digitalWrite(ledAmareloI, HIGH);
      digitalWrite(ledAmareloII, HIGH);
      digitalWrite(ledVermelhoI, HIGH);
      digitalWrite(ledVermelhoII, HIGH);
      tone(buzzer, 659);
    break;
}
}
