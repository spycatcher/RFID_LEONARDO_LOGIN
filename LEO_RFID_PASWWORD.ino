String CardID;
char inChar;
int x;
int mode=1;
void setup()
{
  Serial1.begin(9600);
  Keyboard.begin();
}

void loop()
{
  while (inChar = Serial1.read() != 2)
  {}                                        // Stand and do nothing until 2 (the Header) is received.

  int valid=0;
  CardID = "";
  for (x = 0; x < 12; x++)
  {
    delay(5);  
    inChar = Serial1.read();
    CardID += inChar;
  }
  if (CardID=="2xxxxxxxxxx")        // Replace this with your RFID Serial in HEX - E.G. 28009EDA115C
  {
    if(mode==1)
    {
      Keyboard.println("PASSWORD"); // Replace this with your login password
      mode=2;
      valid=1;
    }

    else
    {
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('l');
      Keyboard.releaseAll();
      mode=1;
      valid=1;
    }
  }
  

  if (valid==0)
  {
    Keyboard.print("Unauthorized Card : Access Denied - Card Serial Number : ");
    Keyboard.println(CardID);
  }

}
