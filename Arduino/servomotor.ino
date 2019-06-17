#include <Servo.h> // Incluímos la libreria externa para poder utilizarla

Servo servo; // Variable servo motor

void setup()
{
  servo.attach(2);
}

void loop() 
{
  //map(value, fromLow, fromHigh, toLow, toHigh)
  int valorBoton = analogRead(A0); // Valor boton

  //servo.write(posicion);

  if(valorBoton <100 && valorBoton >= 0) // VALORES DE DERECHA
  { 
    servo.write(map(180, 0, 255, 0, 180));
  } 
  else if(valorBoton<620 && valorBoton >450) // VALORES DE IZQUIERDA
  {
    servo.write(map(0, 0, 255, 0, 180));
  }
  
}
