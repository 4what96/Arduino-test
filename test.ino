//////// includes ///////

//#include <Controllino.h>


//////// defines  ///////

//////// declaration ////////

const byte PinA = 2;
const byte PinB = 3;

int menuItem = 0;
int tempItem = 0;

int selectedItem = 0;

String menu[] = {
  "Pump speed",
  "Injector",
  "LED"
};

void setup() {
  Serial.begin(9600);
  
  attachInterrupt(digitalPinToInterrupt(PinA), blink, RISING);


  printMenu();
}

void loop() {
  if(menuItem != tempItem){
    Serial.println(menuItem);
    printMenu();

    tempItem = menuItem;
  }
  
}


void blink(){
  if(digitalRead(PinB)){
    menuItem++;
  }else{
    menuItem--;
  }
}



///////////// printMenu //////////////

void printMenu(){
  Serial.println("PUMP CONTROL");
  for(int i = 0; i < sizeof(menu) / sizeof(menu[0]) ; i++){
    if(i == menuItem)
      Serial.print("(x)");
    else Serial.print("( )");
    Serial.println(menu[i]);
  }

  for(int x = 0; x < 10; x++){
    Serial.println("");
  }
}
