#include <Keyboard.h>
#include <Encoder.h>

#define Row1 A3
#define Row2 A2
#define Row3 A1
#define Row4 A0         

#define Col1 16
#define Col2 9
#define Col3 14
#define Col4 15


//////////keyboard declare//////////
int checkR1, checkR2, checkR3, checkR4;
unsigned int pushMillis=0;

char FuncKey[] = {(char) 0x83, (char) 0x82, (char) 0x81, (char) 0x80, (char) 0x20};// cmd, opt, shift, ctrl, spacebar
int FuncVal[] = {0, 0, 0, 0, 0};

int NumCount1 = 0, NumCount2 = 0,  NumCount3 = 0,  NumCount4 = 0, NumCount = 0;
int i = 0;


//////////encoder declare//////////
Encoder myEncA(8, 3);
Encoder myEncB(2, 6);
Encoder myEncC(0, 5);
Encoder myEncD(1, 4);
long EncAold  = -999;
long EncBold  = -999;
long EncCold  = -999;
long EncDold  = -999;
long EncAvar = 0;
long EncBvar = 0;
long EncCvar = 0;
long EncDvar = 0;

int EncP1 = 0;
int EncP2 = 0;
int EncP3 = 0;
int EncP4 = 0;

int ProgramSel = 0;
int ProgramNum = 3;


/////////photoshop variables//////////
int OpVal = 5;
int ToolNum = 0;
char ToolVal[] = {'v','m','l','w','c','i','j','b','s','e','g','o','t','p','a','h','z'};

void FuncPress(boolean val1, boolean val2, boolean val3, boolean val4, boolean val5){
  boolean func[] = {val1, val2, val3, val4, val5};
  for(int i = 0; i < 5; i++){
    if(func[i] == 1) {Keyboard.press(FuncKey[i]);FuncVal[i] = 2;}
  }
}


void setup() {
  /////////keyboard setup//////////
  Serial.begin(115200);
  Keyboard.begin();
  
  pinMode(Row1, INPUT_PULLUP);
  pinMode(Row2, INPUT_PULLUP);
  pinMode(Row3, INPUT_PULLUP);
  pinMode(Row4, INPUT_PULLUP);
  pinMode(Col1, OUTPUT);
  pinMode(Col2, OUTPUT);
  pinMode(Col3, OUTPUT);
  pinMode(Col4, OUTPUT);

  pushMillis=millis();
}


void loop() {
  
  digitalWrite(Col1, LOW); digitalWrite(Col2, LOW); digitalWrite(Col3, LOW); digitalWrite(Col4, LOW);
  if(analogRead(Row1) <= 900) checkR1 = 2;
  else{if(checkR1) checkR1--;}    
  if(analogRead(Row2) <= 900) checkR2 = 2;
  else{if(checkR2) checkR2--;}
  if(analogRead(Row3) <= 900) checkR3 = 2;
  else{if(checkR3) checkR3--;}
  if(analogRead(Row4) <= 900) checkR4 = 2;
  else{if(checkR4) checkR4--;}
  digitalWrite(Col1, HIGH) ;digitalWrite(Col2, HIGH); digitalWrite(Col3, HIGH); digitalWrite(Col4, HIGH);

  if(NumCount1 > 10 && NumCount2 > 10){
    delay(30); 
    NumCount1 = 0; 
    NumCount2 = 0; 
    NumCount++; 
    Keyboard.releaseAll(); 
    delay(1000);
  }
  
  if(NumCount%2 == 0) {ProgramSelect(ProgramSel);}
  else Numpad();
  
  for(int i = 0; i < 5; i++){
    if(FuncVal[i] == 0) Keyboard.release(FuncKey[i]);
    else{FuncVal[i]--;}
  }
}

void ProgramSelect(int x){
  
  if(x%ProgramNum == 0){  //Photoshop
    
    char mat[4][4] = 
    {{' ', ' ', ' ', ' '},
     {'a', 'd', 'g', 'j'},
     {'b', 'e', 'h', 'k'},
     {'c', 'f', 'i', 'l'}};

     int bmat[4][4] =                   // cmd, opt, shift, ctrl, spacebar
    {{0b00000, 0b00000, 0b00000, 0b00000},
     {0b00000, 0b00000, 0b00000, 0b00000},
     {0b00000, 0b00000, 0b00000, 0b00000},
     {0b00000, 0b00000, 0b00000, 0b00000}};

    if (checkR1) {  //1st row
      input1(Col1, Row1, mat[0][0], bmat[0][0]);  input(Col2, Row1, mat[1][0], bmat[1][0]);   input(Col3, Row1, mat[2][0], bmat[2][0]);   input(Col4, Row1, mat[3][0], bmat[3][0]);}

    if (checkR2) {  //2nd row
      input2(Col1, Row2, mat[0][1], bmat[0][1]);   input(Col2, Row2, mat[1][1], bmat[1][1]);   input(Col3, Row2, mat[2][1], bmat[2][1]);   input(Col4, Row2, mat[3][1], bmat[3][1]);}
    
    if (checkR3) {  //3rd row
      input3(Col1, Row3, mat[0][2], bmat[0][2]);   input(Col2, Row3, mat[1][2], bmat[1][2]);   input(Col3, Row3, mat[2][2], bmat[2][2]);   input(Col4, Row3, mat[3][2], bmat[3][2]);}

    if (checkR4) {  //4th row
      input4(Col1, Row4, mat[0][3], bmat[0][3]);  input(Col2, Row4, mat[1][3], bmat[1][3]);   input(Col3, Row4, mat[2][3], bmat[2][3]);   input(Col4, Row4, mat[3][3], bmat[3][3]);}



  long EncAnew = myEncA.read();
  long EncBnew = myEncB.read();
  long EncCnew = myEncC.read() / 4;
  long EncDnew = myEncD.read() / 4;
//////////1st encoder//////////Tool Selector
   if (EncAnew/2 != EncAold/2) {          
      if (EncP1 == 0) {      //if you rotate encoder
        if(EncAnew/2 > EncAold/2){
          if(ToolNum > 0){
            ToolNum--;
            Keyboard.press(ToolVal[ToolNum]);   //when you are rotate CCW
          }
        }
        else{
          if(ToolNum < sizeof(ToolVal)){
            ToolNum++;
            Keyboard.press(ToolVal[ToolNum]);   //when you are rotate CW
            }
        }
      }
      else{                               //if you push and rotate encoder
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.press(ToolVal[ToolNum]);
          }
    Keyboard.releaseAll();
    EncAold = EncAnew;
    EncAvar = EncAnew/2;
   }

//////////2nd encoder//////////opacity
  if (EncBnew/2 != EncBold/2) {
    if(EncBnew/2 > EncBold/2){
      if(OpVal>1){
        OpVal--;
        Keyboard.print(OpVal*5);
      }
    }
    else{
      if(OpVal<20){
        OpVal++;
        Keyboard.print(OpVal*5);
      }
    }
    Keyboard.releaseAll();
    EncBold = EncBnew;
    EncBvar = EncBnew/2;
  }

//////////3rd encoder//////////brush size & hardness
  if (EncCnew/2 != EncCold/2) {
    if(EncP3 == 1){
      Keyboard.press(KEY_LEFT_SHIFT);
    }
    if(EncCnew/2 > EncCold/2){
      Keyboard.press('[');
    }
    else{
      Keyboard.press(']');
    }
    Keyboard.releaseAll();
    EncCold = EncCnew;
    EncCvar = EncCnew/2;
  }

//////////4th encoder//////////history & zoom
   if (EncDnew/2 != EncDold/2) {          
      if (EncP4 == 0) {      //if you rotate encoder
        if(EncDnew/2 > EncDold/2){
          Keyboard.press(KEY_LEFT_GUI);   //when you are rotate CCW
          Keyboard.press('-');
        }
        else{
          Keyboard.press(KEY_LEFT_GUI);   //when you are rotate CW
          Keyboard.press('+');
          }
      }
      else{                               //if you push and rotate encoder
        if(EncDnew/2 > EncDold/2){
          Keyboard.press(KEY_LEFT_GUI);   //when you are rotate encoder CCW
          Keyboard.press('z');
        }
        else{
          Keyboard.press(KEY_LEFT_GUI);   //when you are rotate encoder CW
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.press('z');
          }        
      }
    Keyboard.releaseAll();
    EncDold = EncDnew;
    EncDvar = EncDnew/2;
   }
    
  }

  if(x%ProgramNum == 1){
  }

  if(x%ProgramNum == 2){
  }
}


void input(int col, int row, char input, int bin){
  
  int a = bin >> 4;
  int b = (bin - (a << 4)) >> 3;
  int c = (bin - (a << 4) - (b << 3)) >> 2;
  int d = (bin - (a << 4) - (b << 3) - (c << 2)) >> 1;
  int e = (bin - (a << 4) - (b << 3) - (c << 2) - (d << 1));

  if(input == ' '){
    digitalWrite(col, LOW);
    if (analogRead(row) >= 900){}
    else FuncPress(a,b,c,d,e);
    digitalWrite(col, HIGH);
  }
  else{ 
    digitalWrite(col, LOW);
    if (analogRead(row) >= 900) Keyboard.release(input);
    else{FuncPress(a,b,c,d,e);  Keyboard.press(input);}
    digitalWrite(col, HIGH);
  }
}

void input1(int col, int row, char input, int bin){
  int a = bin >> 4;
  int b = (bin - (a << 4)) >> 3;
  int c = (bin - (a << 4) - (b << 3)) >> 2;
  int d = (bin - (a << 4) - (b << 3) - (c << 2)) >> 1;
  int e = (bin - (a << 4) - (b << 3) - (c << 2) - (d << 1));
  if(input == ' '){
    digitalWrite(col, LOW);
    if (analogRead(row) >= 900){  NumCount1 = 0; EncP1 = 0;}
    else {FuncPress(a,b,c,d,e);   NumCount1++;   EncP1 = 1;}
    digitalWrite(col, HIGH);
  }
  else{
    digitalWrite(col, LOW);
    if (analogRead(row) >= 900){Keyboard.release(input); NumCount1 = 0; EncP1 = 0;}
    else{FuncPress(a,b,c,d,e);  Keyboard.press(input);   NumCount1++; EncP1 = 1;}
    digitalWrite(col, HIGH);
  }
}

void input2(int col, int row, char input, int bin){
  int a = bin >> 4;
  int b = (bin - (a << 4)) >> 3;
  int c = (bin - (a << 4) - (b << 3)) >> 2;
  int d = (bin - (a << 4) - (b << 3) - (c << 2)) >> 1;
  int e = (bin - (a << 4) - (b << 3) - (c << 2) - (d << 1));
  if(input == ' '){
    digitalWrite(col, LOW);
    if (analogRead(row) >= 900){  NumCount2 = 0; EncP2 = 0;}
    else {FuncPress(a,b,c,d,e);   NumCount2++;   EncP2 = 1;}
    digitalWrite(col, HIGH);
  }
  else{
    digitalWrite(col, LOW);
    if (analogRead(row) >= 900){Keyboard.release(input); NumCount2 = 0; EncP2 = 0;}
    else{FuncPress(a,b,c,d,e);  Keyboard.press(input);   NumCount2++;   EncP2 = 1;}
    digitalWrite(col, HIGH);
  }
}

void input3(int col, int row, char input, int bin){
  int a = bin >> 4;
  int b = (bin - (a << 4)) >> 3;
  int c = (bin - (a << 4) - (b << 3)) >> 2;
  int d = (bin - (a << 4) - (b << 3) - (c << 2)) >> 1;
  int e = (bin - (a << 4) - (b << 3) - (c << 2) - (d << 1));
  if(input == ' '){
    digitalWrite(col, LOW);
    if (analogRead(row) >= 900){   NumCount3 = 0; EncP3 = 0;}
    else {FuncPress(a,b,c,d,e);   NumCount3++;    EncP3 = 1;}
    digitalWrite(col, HIGH);
  }
  else{
    digitalWrite(col, LOW);
    if (analogRead(row) >= 900){Keyboard.release(input); NumCount3 = 0; EncP3 = 0;}
    else{FuncPress(a,b,c,d,e);  Keyboard.press(input);   NumCount3++;   EncP3 = 1;}
    digitalWrite(col, HIGH);
  }
}

void input4(int col, int row, char input, int bin){
  int a = bin >> 4;
  int b = (bin - (a << 4)) >> 3;
  int c = (bin - (a << 4) - (b << 3)) >> 2;
  int d = (bin - (a << 4) - (b << 3) - (c << 2)) >> 1;
  int e = (bin - (a << 4) - (b << 3) - (c << 2) - (d << 1));
  if(input == ' '){
    digitalWrite(col, LOW);
    if (analogRead(row) >= 900){  NumCount4 = 0; EncP4 = 0;}
    else {FuncPress(a,b,c,d,e);   NumCount4++;   EncP4 = 1;}
    digitalWrite(col, HIGH);
  }
  else{
    digitalWrite(col, LOW);
    if (analogRead(row) >= 900){Keyboard.release(input); NumCount4 = 0; EncP4 = 0;}
    else{FuncPress(a,b,c,d,e);  Keyboard.press(input);   NumCount4++;   EncP4 = 1;}
    digitalWrite(col, HIGH);
  }
}

void inpute(int col, int row, char input, int bin){
  
  int a = bin >> 4;
  int b = (bin - (a << 4)) >> 3;
  int c = (bin - (a << 4) - (b << 3)) >> 2;
  int d = (bin - (a << 4) - (b << 3) - (c << 2)) >> 1;
  int e = (bin - (a << 4) - (b << 3) - (c << 2) - (d << 1));

  if(input == ' '){
    digitalWrite(col, LOW);
    if (analogRead(row) >= 900){}
    else FuncPress(a,b,c,d,e);
    digitalWrite(col, HIGH);
  }
  else{ 
    digitalWrite(col, LOW);
    if (analogRead(row) >= 900) Keyboard.release(0xB0);
    else{FuncPress(a,b,c,d,e);  Keyboard.press(0xB0);}
    digitalWrite(col, HIGH);
  }
}

void ProgramShow(int x){
  if(x%ProgramNum == 0){
    Keyboard.print("PHOTOSHOP");
  }
  
  if(x%ProgramNum == 1){
    Keyboard.print("CAPTURE ONE");
  }
  
  if(x%ProgramNum == 2){
    Keyboard.print("RHINO");
  }    
}

void Numpad(){
    char mat[4][4] = 
    {{' ', ' ', ' ', ' '},
     {'1', '2', '3', '.'},
     {'4', '5', '6', '0'},
     {'7', '8', '9', 'p'}};

     int bmat[4][4] =
    {{0b00000, 0b00000, 0b00000, 0b00000},
     {0b00000, 0b00000, 0b00000, 0b00000},
     {0b00000, 0b00000, 0b00000, 0b00000},
     {0b00000, 0b00000, 0b00000, 0b00000}};

    if (checkR1) {  //1st row
      input1(Col1, Row1, mat[0][0], bmat[0][0]);  input(Col2, Row1, mat[1][0], bmat[1][0]);   input(Col3, Row1, mat[2][0], bmat[2][0]);   input(Col4, Row1, mat[3][0], bmat[3][0]);}

    if (checkR2) {  //2nd row
      input2(Col1, Row2, mat[0][1], bmat[0][1]);   input(Col2, Row2, mat[1][1], bmat[1][1]);   input(Col3, Row2, mat[2][1], bmat[2][1]);   input(Col4, Row2, mat[3][1], bmat[3][1]);}
    
    if (checkR3) {  //3rd row
      input3(Col1, Row3, mat[0][2], bmat[0][2]);   input(Col2, Row3, mat[1][2], bmat[1][2]);   input(Col3, Row3, mat[2][2], bmat[2][2]);   input(Col4, Row3, mat[3][2], bmat[3][2]);}

    if (checkR4) {  //4th row
      input4(Col1, Row4, mat[0][3], bmat[0][3]);  input(Col2, Row4, mat[1][3], bmat[1][3]);   input(Col3, Row4, mat[2][3], bmat[2][3]);   inpute(Col4, Row4, mat[3][3], bmat[3][3]);}
  
}