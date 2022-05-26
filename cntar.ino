#include <Keyboard.h>
#include <Encoder.h>

#define Row1 A0
#define Row2 A1
#define Row3 A2
#define Row4 A3         

#define Col1 9
#define Col2 14
#define Col3 15
#define Col4 16

//////////keyboard declare//////////
int checkR1, checkR2, checkR3, checkR4;
unsigned int pushMillis=0;

char FuncKey[] = {(char) 0x83, (char) 0x82, (char) 0x81, (char) 0x80, (char) 0x20};// cmd, opt, shift, ctrl, spacebar
int FuncVal[] = {0, 0, 0, 0, 0};

int NumCount1 = 0, NumCount2 = 0, NumCount = 0;
int i = 0;


//////////encoder declare//////////
Encoder myEncA(3, 8);
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
  
/*  if(digitalRead(EncP1) == LOW && digitalRead(EncP4) == LOW){
    if((millis()-pushMillis)>250){
      ProgramSel++;
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press((char) 0x20);
      Keyboard.releaseAll();
      delay(100);
      ProgramShow(ProgramSel);
      pushMillis=millis();
      delay(2000);
    }
  }
  */
  
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
    if (checkR1) {  //1st row
      digitalWrite(Col1, LOW);
      if (analogRead(Row1) >= 900) {Keyboard.release('a'); NumCount1 = 0;}
      else{FuncPress(0,0,0,0,0);    Keyboard.press('a'); NumCount1++;}
      digitalWrite(Col1, HIGH);

      digitalWrite(Col2, LOW);
      if (analogRead(Row1) >= 900) Keyboard.release('b');
      else{FuncPress(0,0,0,0,0);   Keyboard.press('b');}
      digitalWrite(Col2, HIGH);

      digitalWrite(Col3, LOW);
      if (analogRead(Row1) >= 900) Keyboard.release('c');
      else{FuncPress(0,0,0,0,0);   Keyboard.press('c');}
      digitalWrite(Col3, HIGH);

      digitalWrite(Col4, LOW);
      if (analogRead(Row1) >= 900) {Keyboard.release('d'); NumCount2 = 0;}
      else{FuncPress(0,0,0,0,0);   Keyboard.press('d'); NumCount2++;}
      digitalWrite(Col4, HIGH);
    }

    
    if (checkR2) {  //2nd row
      digitalWrite(Col1, LOW);
      if (analogRead(Row2) >= 900) Keyboard.release('e');
      else{FuncPress(0,0,0,0,0);   Keyboard.press('e');}
      digitalWrite(Col1, HIGH);

      digitalWrite(Col2, LOW);
      if (analogRead(Row2) >= 900) Keyboard.release('f');
      else{FuncPress(0,0,0,0,0);   Keyboard.press('f');}
      digitalWrite(Col2, HIGH);

      digitalWrite(Col3, LOW);
      if (analogRead(Row2) >= 900) Keyboard.release('g');
      else{FuncPress(0,0,0,0,0);   Keyboard.press('g');}
      digitalWrite(Col3, HIGH);

      digitalWrite(Col4, LOW);
      if (analogRead(Row2) >= 900) Keyboard.release('h');
      else{FuncPress(0,0,0,0,0);   Keyboard.press('h');}
      digitalWrite(Col4, HIGH);
    }
    
  
    if (checkR3) {  //3rd row
      digitalWrite(Col1, LOW);
      if (analogRead(Row3) >= 900) Keyboard.release('i');
      else{FuncPress(0,0,0,0,0);   Keyboard.press('i');}
      digitalWrite(Col1, HIGH);

      digitalWrite(Col2, LOW);
      if (analogRead(Row3) >= 900) Keyboard.release('j');
      else{FuncPress(0,0,0,0,0);   Keyboard.press('j');}
      digitalWrite(Col2, HIGH);

      digitalWrite(Col3, LOW);
      if (analogRead(Row3) >= 900) Keyboard.release('k');
      else{FuncPress(0,0,0,0,0);   Keyboard.press('k');}
      digitalWrite(Col3, HIGH);

      digitalWrite(Col4, LOW);
      if (analogRead(Row3) >= 900) Keyboard.release('l');
      else{FuncPress(0,0,0,0,0);   Keyboard.press('l');}
      digitalWrite(Col4, HIGH);
    }


  
    if (checkR4) {  //3rd row
      digitalWrite(Col1, LOW);
      if (analogRead(Row4) >= 900) Keyboard.release('m');
      else{FuncPress(0,0,0,0,0);   Keyboard.press('m');}
      digitalWrite(Col1, HIGH);

      digitalWrite(Col2, LOW);
      if (analogRead(Row4) >= 900) Keyboard.release('n');
      else{FuncPress(0,0,0,0,0);   Keyboard.press('n');}
      digitalWrite(Col2, HIGH);

      digitalWrite(Col3, LOW);
      if (analogRead(Row4) >= 900) Keyboard.release('o');
      else{FuncPress(0,0,0,0,0);   Keyboard.press('o');}
      digitalWrite(Col3, HIGH);

      digitalWrite(Col4, LOW);
      if (analogRead(Row4) >= 900) Keyboard.release('p');
      else{FuncPress(0,0,0,0,0);   Keyboard.press('p');}
      digitalWrite(Col4, HIGH);
    }
  
  //////////encoder//////////





  }

  if(x%ProgramNum == 1){
  }


  
  if(x%ProgramNum == 2){
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
    if (checkR1) {
      digitalWrite(Col1, LOW);
      if (analogRead(Row1) >= 900) {Keyboard.release('1'); NumCount1 = 0;}
      else{FuncPress(0,0,0,0,0);    Keyboard.press('1'); NumCount1++;}
      digitalWrite(Col1, HIGH);

      digitalWrite(Col2, LOW);
      if (analogRead(Row1) >= 900) Keyboard.release('2');
      else{FuncPress(0,0,0,0,0);   Keyboard.press('2');}
      digitalWrite(Col2, HIGH);

      digitalWrite(Col3, LOW);
      if (analogRead(Row1) >= 900) Keyboard.release('3');
      else{FuncPress(0,0,0,0,0);   Keyboard.press('3');}
      digitalWrite(Col3, HIGH);

      digitalWrite(Col4, LOW);
      if (analogRead(Row1) >= 900) {Keyboard.release('0'); NumCount2 = 0;}
      else{FuncPress(0,0,0,0,0);   Keyboard.press('0'); NumCount2++;}
      digitalWrite(Col4, HIGH);
    }
    if (checkR2) {
      digitalWrite(Col1, LOW);
      if (analogRead(Row2) >= 900) Keyboard.release('4');
      else{FuncPress(0,0,0,0,0);   Keyboard.press('4');}
      digitalWrite(Col1, HIGH);

      digitalWrite(Col2, LOW);
      if (analogRead(Row2) >= 900) Keyboard.release('5');
      else{FuncPress(0,0,0,0,0);   Keyboard.press('5');}
      digitalWrite(Col2, HIGH);

      digitalWrite(Col3, LOW);
      if (analogRead(Row2) >= 900) Keyboard.release('6');
      else{FuncPress(0,0,0,0,0);   Keyboard.press('6');}
      digitalWrite(Col3, HIGH);

      digitalWrite(Col4, LOW);
      if (analogRead(Row2) >= 900)Keyboard.release('.');
      else{FuncPress(0,0,0,0,0);   Keyboard.press('.');}
      digitalWrite(Col4, HIGH);
    }
    if (checkR3) {
      digitalWrite(Col1, LOW);
      if (analogRead(Row3) >= 900) Keyboard.release('7');
      else{FuncPress(0,0,0,0,0);   Keyboard.press('7');}
      digitalWrite(Col1, HIGH);

      digitalWrite(Col2, LOW);
      if (analogRead(Row3) >= 900) Keyboard.release('8');
      else{FuncPress(0,0,0,0,0);   Keyboard.press('8');}
      digitalWrite(Col2, HIGH);

      digitalWrite(Col3, LOW);
      if (analogRead(Row3) >= 900) Keyboard.release('9');
      else{FuncPress(0,0,0,0,0);   Keyboard.press('9');}
      digitalWrite(Col3, HIGH);

      digitalWrite(Col4, LOW);
      if (analogRead(Row3) >= 900) Keyboard.release(KEY_RETURN);
      else{FuncPress(0,0,0,0,0);   Keyboard.press(KEY_RETURN);}
      digitalWrite(Col4, HIGH);
    }
 }


/*////////////////////////////////Reference////////////////////////




///////////////////////////updated 22.01.07


      if(x%ProgramNum == 0){
    if (checkR1) {  //1st row
      digitalWrite(Col1, LOW);
      if (analogRead(Row1) >= 900) {Keyboard.release('q'); NumCount1 = 0;}
      else{FuncPress(1,1,0,0,0);    Keyboard.press('q'); NumCount1++;}
      digitalWrite(Col1, HIGH);

      digitalWrite(Col2, LOW);
      if (analogRead(Row1) >= 900) Keyboard.release('1');
      else{FuncPress(1,1,0,0,0);   Keyboard.press('1');}
      digitalWrite(Col2, HIGH);

      digitalWrite(Col3, LOW);
      if (analogRead(Row1) >= 900) Keyboard.release('i');
      else{FuncPress(1,0,0,0,0);   Keyboard.press('i');}
      digitalWrite(Col3, HIGH);

      digitalWrite(Col4, LOW);
      if (analogRead(Row1) >= 900) {Keyboard.release('x'); NumCount2 = 0;}
      else{FuncPress(1,0,1,0,0);   Keyboard.press('x'); NumCount2++;}
      digitalWrite(Col4, HIGH);
    }

    
    if (checkR2) {  //2nd row
      digitalWrite(Col1, LOW);
      if (analogRead(Row2) >= 900) Keyboard.release('t');
      else{FuncPress(1,0,0,0,0);   Keyboard.press('t');}
      digitalWrite(Col1, HIGH);

      digitalWrite(Col2, LOW);
      if (analogRead(Row2) >= 900) Keyboard.release('j');
      else{FuncPress(1,0,0,0,0);   Keyboard.press('j');}
      digitalWrite(Col2, HIGH);

      digitalWrite(Col3, LOW);
      if (analogRead(Row2) >= 900) Keyboard.release('d');
      else{FuncPress(1,0,0,0,0);   Keyboard.press('d');}
      digitalWrite(Col3, HIGH);

      digitalWrite(Col4, LOW);
      if (analogRead(Row2) >= 900) Keyboard.release('x');
      else{FuncPress(1,1,0,0,0);   Keyboard.press('x');}
      digitalWrite(Col4, HIGH);
    }
    
  
    if (checkR3) {  //3rd row
      digitalWrite(Col1, LOW);
      if (analogRead(Row3) >= 900) i = i; 
      else{FuncPress(0,0,1,0,0);   }
      digitalWrite(Col1, HIGH);

      digitalWrite(Col2, LOW);
      if (analogRead(Row3) >= 900) i = i; 
      else{FuncPress(0,1,0,0,0);   }
      digitalWrite(Col2, HIGH);

      digitalWrite(Col3, LOW);
      if (analogRead(Row3) >= 900) i = i;  
      else{FuncPress(1,0,0,0,0);   }
      digitalWrite(Col3, HIGH);

      digitalWrite(Col4, LOW);
      if (analogRead(Row3) >= 900) i = i;
      else{FuncPress(0,0,0,0,1);  }
      digitalWrite(Col4, HIGH);
    }

  
  //////////encoder//////////
    enc1->tick();
    enc2->tick();
    enc3->tick();
    enc4->tick();

    int newPos1 = enc1->getPosition();  //Tool Selector
    if(pos1 != newPos1){
      if(EncP1 == LOW){
        if((int)(enc1->getDirection()) == true){
          if(ToolNum > 0){
            ToolNum--; Keyboard.write(ToolVal[ToolNum]);
          }
        }
        else{
          if(ToolNum < sizeof(ToolVal)){
            ToolNum++; Keyboard.write(ToolVal[ToolNum]);
          }
        }
      }
      else{
        if((int)(enc1->getDirection()) == true){
          FuncPress(0,0,1,0,0); Keyboard.write(ToolVal[ToolNum]);
        }
      }
      pos1 = newPos1;
    }
  
    int newPos2 = enc2->getPosition();  //History & Layer Select
    if(pos2 != newPos2){
      if(EncP2 == LOW){
        if((int)(enc2->getDirection()) == true){
          FuncPress(1,0,0,0,0); Keyboard.press('z');
        }
        else{
          FuncPress(1,0,1,0,0); Keyboard.press('z');
        }
      }
      else{
        if((int)(enc2->getDirection()) == true){
          FuncPress(0,1,0,0,0); Keyboard.press('[');
        }
        else{
          FuncPress(0,1,0,0,0); Keyboard.press(']');
        }
      }
      Keyboard.release('z');
      Keyboard.release('[');
      Keyboard.release(']');
      pos2 = newPos2;
    }
  
    int newPos3 = enc3->getPosition(); //Brush size & Opacity
    if(pos3 != newPos3){
      if(EncP3 == LOW){
        if((int)(enc3->getDirection()) == true){
          Keyboard.press('[');
        }
        else{
          Keyboard.press(']');
        }
      }
      else{
        if((int)(enc3->getDirection()) == true){
          if(OpVal>1){OpVal--; Keyboard.print(OpVal*5);}
        }
        else{
          if(OpVal<20){OpVal++; Keyboard.print(OpVal*5);}
        }
      }
      Keyboard.release('[');
      Keyboard.release(']');
      pos3 = newPos3;
    }
  
    int newPos4 = enc4->getPosition();  //Zoom
    if(pos4 != newPos4){
      if(EncP4 == LOW){
        if((int)(enc4->getDirection()) == true){
          FuncPress(1,0,0,0,0); Keyboard.press('-');
        }
        else{
          FuncPress(1,0,0,0,0); Keyboard.press('+');
        }
      }
      else{
        if((int)(enc4->getDirection()) == true){
          Keyboard.write('1');
        }
        else{
          Keyboard.write('2');
        }
      }
      Keyboard.release('-');
      Keyboard.release('+');
      pos4 = newPos4;
    }
  }
*/
