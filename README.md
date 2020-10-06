# Dado Electrónico Sin Botón

## ¿A que pines se conecta?

Este diseño solo funciona si conectas los LEDs a los pines 3,4,5,6,7,8 y 9 de esta manera:
```
3-4-5
  6
7-8-9
```
Es decir, asegurate de que el pin de arriba a la izquierda esta conectado al pin 3, y así con todos.

## ¿Cómo funciona?

Primero creamos un Array 2D (de Dos Dimensiones) llamada "numeros" para almacenar la cantidad de voltaje que recibirá cada LED para formar cada número del dado.
```c
int numeros[6][7] = { 
	{0,0,0,255,0,0,0},          // Esto forma el número 1
	{255,0,0,0,0,0,255},        // Esto el 2  
	{255,0,0,255,0,0,255},      // Esto el 3...
	{255,0,255,0,255,0,255},
	{255,0,255,255,255,0,255},
	{255,255,255,0,255,255,255} 
};
``` 

Después debemos poner los pines que usaremos como salida en la función ```setup()```. Aquí usaremos un bucle ```for``` que va desde el número 3 hasta el 10. Es importante no usar los pines 1 y 2 ya que tienen propiedades especiales, por eso empezamos en el 3 y acabamos en el 10 (3-10 = 7) y 7 es el número de LEDs que estamos utilizando.
```c
void setup() {
	for(int i=3;i<10;i++) {
		pinMode(i, OUTPUT);
	}
}
```

Ya solo queda la función ```loop()```.
```c
void loop() {
  	int rand = random(0,6);

	for(int x=3;x<10;x++) {
		digitalWrite(x, numeros[rand][x-3]);
	}
	delay(1000);
}
```

Primero crearemos una variable entera llamada "rand". El valor de esta variable debe ser aleatorio por lo que usaremos la función ```random()``` que nos ofrece arduino. Y de parámetros pondremos el 0 y el 6 porque es el abanico de números que usaremos para acceder/conseguir los valores que pusimos en el Array 2D de antes.
```c
int rand = random(0,6);
```
Este bucle ```for``` hace varias cosas. Empieza en el 3 y acaba en el 10 (como en el bucle del ```setup()```). Necestiamos "actualizar" el estado de los LEDs cada vez que cambiamos de número, es por eso que ejecutamos un ```digitalWrite``` 7 veces. Sobre los parámetros que hemos usado en el ```digitalWrite``` x es el pin del LED que vamos a cambiar, la x es la variable del bucle ```for``` por lo que irá aumentando (3,4,5,6...) para cambiar cada LED, ```numeros[rand][x-3]``` es el valor que estamos sacando del Array 2D para decidir si es ENCENDIDO o APAGADO, rand es la variable aleatoria que creamos antes, y x es de nuevo la variable del bucle, le restamos 3 porque siempre hay que empezar a contar por el 0 en programación y la x se creo con un valor de 3 (```for(int x=3;x<10;x++)```)
```c
for(int x=3;x<10;x++) {
		digitalWrite(x, numeros[rand][x-3]);
	}
```
Finalmente, ponemos un delay de 1000ms (1s) para poder distinguir el cambio de los LEDs.
```c
delay(1000);
```
