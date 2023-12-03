int Serial_print(int x1, int y1, int z1, int x2, int y2, int z2){
  
  Serial.println("**********right**********");
  Serial.print("right_X = "); // on the serial monitor, print out right_X = 
  Serial.print(x1 ,DEC); // print out the value of right X and line wrap
  Serial.print("  ");
  Serial.print("right_Y = ");
  Serial.print(y1 ,DEC);
  Serial.print("  ");
  Serial.print("right_key = ");
  Serial.print(z1 ,DEC);
  Serial.print(" ||| ");
  Serial.println("*********left***********");
  Serial.print("left_X = ");
  Serial.print(x2 ,DEC);
  Serial.print("  ");
  Serial.print("left_Y = ");
  Serial.print(y2 ,DEC);
  Serial.print("  ");
  Serial.print("left_key = ");
  Serial.println(z2 ,DEC);
}