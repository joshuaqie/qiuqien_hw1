/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-05-05 22:50:53
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-05-18 17:44:45
 * @FilePath: \firsth:\Documents\PlatformIO\Projects\second\src\main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <Arduino.h>
String mystring = "";
String keystring[] = {"AA", "BB", "CC", "DD"};
int i = 0;
void setup()
{
  Serial.begin(9600);
}
void loop()
{

  if (Serial.available() > 0)
  {
    mystring = Serial.readStringUntil('\r');
    if (mystring.compareTo("") == 0)
    {
    }
    else if (mystring.compareTo(keystring[i]) == 0)
    {
      i++;
    }
    else
    {

      Serial.println("Wrong");
      i = 0;
    }
  }
  if (i == 4)
  {
    Serial.println("Correct");
    i = 0;
  }
}
