#include "mbed.h"
Serial bt(D10,D2);
Serial pc(USBTX,USBRX);
DigitalOut myled(LED1);

AnalogIn analog_value(A0);


int get_voltage()
{
	return analog_value.read() * 0.004882814;

}

int main() 
{
	bt.buad(9600);
	bt.printf("Connection Established");
	pc.printf("Connection Established");
	float voltage, temp_c, temp_f;

	while(1)
	{
		if(bt.readble())
		{
			char input_key = bt.putc("%c",bt.getc());
			if(input_key == 'y'){
				myled = 1;
				bt.printf("Led is on");
				pc.printf("Test y");
			}
			if(input_key == 'n'){
				myled = 0;
				bt.printf("Led is off");
				pc.printf("Test n");
			}

		}
		if(pc.readble())
		{
			char input_key = pc.putc("%c",bt.getc());
			if(input_key == 'y'){
				myled = 1;
				pc.printf("Led is on");
				bt.printf("Test y");
			}
			if(input_key == 'n'){
				myled = 0;
				pc.printf("Led is off");
				bt.printf("Test n");
			}
			
			if(input_key == 'r'){
				voltage = get_voltage();
				temp_c = (voltage - 0.5) * 100.0;
				temp_f = temp_c * (9.0/ 5.0) + 32.0;
				pc.printf("Temp F: %d Temp C:%d\n\n",temp_f,temp_c);
			}
		}
	}
}




