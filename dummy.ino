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
  


/*
    if (checkR1) {
      digitalWrite(Col1, LOW);
      if (analogRead(Row1) >= 900) {Keyboard.release('1'); NumCount1 = 0;}
      else{FuncPress(0,0,0,0,0);    Keyboard.press('1'); NumCount1++;}
      digitalWrite(Col1, HIGH);
    }
    if (checkR2) {
      digitalWrite(Col1, LOW);
      if (analogRead(Row2) >= 900) Keyboard.release('2');
      else{FuncPress(0,0,0,0,0);   Keyboard.press('2');}
      digitalWrite(Col1, HIGH);
    }
    if (checkR3) {
      digitalWrite(Col1, LOW);
      if (analogRead(Row3) >= 900) Keyboard.release('3');
      else{FuncPress(0,0,0,0,0);   Keyboard.press('3');}
      digitalWrite(Col1, HIGH);
    }
    if (checkR4) {
      digitalWrite(Col1, LOW);
      if (analogRead(Row4) >= 900) {Keyboard.release('4'); NumCount2 = 0;}
      else{FuncPress(0,0,0,0,0);    Keyboard.press('4'); NumCount2++;}
      digitalWrite(Col1, HIGH);
    }

    
    if (checkR1) {  //1st row
      input(Col2, Row1, mat[1][0], 0, 0, 0, 0, 0);   input(Col3, Row1, mat[2][0], 0, 0, 0, 0, 0);   input(Col4, Row1, mat[3][0], 0, 0, 0, 0, 0);}

    if (checkR2) {  //2nd row
      input(Col2, Row2, mat[1][1], 0, 0, 0, 0, 0);   input(Col3, Row2, mat[2][1], 0, 0, 0, 0, 0);   input(Col4, Row2, mat[3][1], 0, 0, 0, 0, 0);}
    
    if (checkR3) {  //3rd row
      input(Col2, Row3, mat[1][2], 0, 0, 0, 0, 0);   input(Col3, Row3, mat[2][2], 0, 0, 0, 0, 0);   input(Col4, Row3, mat[3][2], 0, 0, 0, 0, 0);}

    if (checkR4) {  //4th row
      input(Col2, Row4, mat[1][3], 0, 0, 0, 0, 0);   input(Col3, Row4, mat[2][3], 0, 0, 0, 0, 0);   input(Col4, Row4, mat[3][3], 0, 0, 0, 0, 0);}
*/

  
  //////////encoder//////////

  
  /*
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
    */
 


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