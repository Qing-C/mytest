#include <Morse.h>

Morse mor(13);
char incomingByte;
String strMorse;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  if(Serial.available() > 0)
  incomingByte = Serial.read();
  Serial.print(incomingByte);
  if (isLowerCase(incomingByte))
  {
    switch(incomingByte){
      case 'a' : strMorse = String("*-"); break;
      case 'b' : strMorse = String("-***"); break;
      case 'c' : strMorse = String("-*-*"); break;
      case 'd' : strMorse = String("-**"); break;
      case 'e' : strMorse = String("*"); break;
      case 'f' : strMorse = String("**-*"); break;
      case 'g' : strMorse = String("--*"); break;
      case 'h' : strMorse = String("****"); break;
      case 'i' : strMorse = String("**"); break;
      case 'j' : strMorse = String("*---"); break;
      case 'k' : strMorse = String("-*-"); break;
      case 'l' : strMorse = String("*-**"); break;
      case 'm' : strMorse = String("--"); break;
      case 'n' : strMorse = String("-*"); break;
      case 'o' : strMorse = String("---"); break;
      case 'p' : strMorse = String("*--*"); break;
      case 'q' : strMorse = String("--*-"); break;
      case 'r' : strMorse = String("*-*"); break;
      case 's' : strMorse = String("***"); break;
      case 't' : strMorse = String("-"); break;
      case 'u' : strMorse = String("**-"); break;
      case 'v' : strMorse = String("***-"); break;
      case 'w' : strMorse = String("*--"); break;
      case 'x' : strMorse = String("-**-"); break;
      case 'y' : strMorse = String("-*--"); break;
      case 'z' : strMorse = String("--**"); break;
      }
      int i = 0;
      while(strMorse[i])
      {
        if (strMorse[i] == '*')
        {
          mor.dot();
        }
        if (strMorse[i] == '-')
        {
          mor.dash();
        }
        i++;
      }
      mor.c_space();
    }
    if(isWhitespace(incomingByte))
    {
      mor.w_space();
    }
    if(incomingByte == '\n')
    {
      delay(3000);
    }
}
