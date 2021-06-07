//////// includes ///////

//#include <Controllino.h>


//////// defines  ///////

//////// declaration ////////

const byte PinA = 2;
const byte PinB = 3;

int menuItem = 0;
int tempItem = 0;

int selectedItem = 0;
int firstLineDisplayed = 0;

bool turned = false;
bool turnedRight = false;

String menu[] = {
  "Pump speed",
  "Injector 1",
  "Injector 2",
  "Injector 3",
  "Injector 4",
  "Injector 5"
};



/////// SETUP ////////

void setup() {
  Serial.begin(9600);
  
  attachInterrupt(digitalPinToInterrupt(PinA), rotary, RISING);


  printMenu();
}


////// LOOP ////////

void loop() {
  if(turned){
    if(turnedRight){
      //menuItem++;
      move_down();
    }else{
      //menuItem--;
      move_up();
    }
    turned = false;
  }

  /*
  if(menuItem != tempItem){
    Serial.println(menuItem);
    printMenu();

    tempItem = menuItem;
  }
  */
  
}





void rotary(){
  turnedRight = digitalRead(PinB);
  turned = true;
}



///////////// printMenu //////////////

void printMenu(){
  Serial.println(firstLineDisplayed);
  Serial.println(selectedItem);
  Serial.println(sizeof(menu) / sizeof(menu[0]));
  Serial.println("PUMP CONTROL");
  for(int i = 0; i <= 2; i++){ 
    if(i == selectedItem - firstLineDisplayed)
      Serial.print("(x)");
    else Serial.print("( )");
    Serial.println(menu[i + firstLineDisplayed]);
  }


  ////// print some lines 
  for(int x = 0; x < 20; x++){
    Serial.println("");
  }
}


void move_down(){
  
  if(selectedItem == sizeof(menu) / sizeof(menu[0]) - 1){
    //firstLineDisplayed = 0;
    //selectedItem = 0;
  }else if(selectedItem == firstLineDisplayed + 2){
    firstLineDisplayed++;
  }if(selectedItem == sizeof(menu) / sizeof(menu[0]) - 1){
    
  }else{
    selectedItem++;
  }
  printMenu();
}

void move_up(){
  
  if ((firstLineDisplayed == 0) & (selectedItem == 0)) {
    //firstLineDisplayed = selectedItem-4;   
  } 
  
  else if (firstLineDisplayed == selectedItem) {
    firstLineDisplayed--;
  }
  if (selectedItem == 0) {
    //selectedItem = sizeof(menu) / sizeof(menu[0]) - 1;
  }
  else {
    selectedItem--;
  }
  printMenu();
}
