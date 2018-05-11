#define trigPin 13    //Definišemo promenljive za pinove i dodeljujemo im iste
#define echoPin 12

int counter = 0;  //Definišemo promenljivu za pamćenje, da li je nešto detektovano ili ne

void setup(){
  Serial.begin(9600);  //Otvaramo serijsku komunikaciju i podešavamo brzinu iste
  pinMode(trigPin, OUTPUT);  //Podešavamo pinove, da li će biti ulazi ili izlazi
  pinMode(echoPin, INPUT);
}

void loop(){
  long duration, distance;  //Definišemo promenljive za merenje rastojanja

  digitalWrite(trigPin, LOW);  //Naredbe za slanje
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  //povorke signala na senzor

  duration = pulseIn(echoPin, HIGH);  //pulseIn naredba koja služi kao tajmer i smešta podarke u promenljivu duration
  distance = (duration/2) / 29.1;  //Formula za proračunavanje razdaljine, iz koje se posle podaci smeštaju u promenljivu distance

  if(distance < 16){  //if petlja za detektovanje osobe
    counter = 1;
    Serial.println("Osoba je detektovana! Prank je uspeo!");
    }else{}

    switch(counter){  //switch petlja, koja ako je osoba detektovana, prebaci se u case 1, i uključi sirenu dok se ne resetuje arduino
      case 1: 
      for(int freq = 500; freq < 1500; freq++){
        tone(8, freq, 7000);
        delayMicroseconds(700);
        }

        for(int freq = 1500; freq > 500; freq--){
        tone(8, freq, 7000);
        delayMicroseconds(300);
        }
        break;
        default: counter = 0;
        Serial.println("Osoba nije detektovana! Prank nije uspeo!");
        break;
      }
}
