// 3,4,5
//   6,
// 7,8,9

int numeros[6][7] = { 
	{0,0,0,255,0,0,0},
	{255,0,0,0,0,0,255},
	{255,0,0,255,0,0,255},
	{255,0,255,0,255,0,255},
	{255,0,255,255,255,0,255},
	{255,255,255,0,255,255,255} 
};

void setup() {
	for(int i=3;i<10;i++) {
		pinMode(i, OUTPUT);
	}
}

void loop() {
  	int rand = random(0,6);

	for(int x=3;x<10;x++) {
		digitalWrite(x, numeros[rand][x-3]);
	}
	delay(1000);
}
