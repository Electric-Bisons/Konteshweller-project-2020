


#ifndef I2C_H_
#define I2C_H_

#define I2C_READ 1
#define I2C_WRITE 0
void i2c_Init(void)
{	
	//Set PD0(SCL) & PD1(SDA) input
	DDRD = 0x00;	
	//set SCL at 400kHz (fScl=fcpu/(16+2*TWBR*PRESCALER))
	TWSR = 0x00;
	TWBR = 0x0C;
}

void i2c_Start(void)
{	
	//enable i2c and set interrupt bit to 1
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	//wait for interrupt bit to reset to 0
	while((TWCR &(1<<TWINT))==0);
}
void i2c_Stop(void)
{	
	//stop i2c transmitting 
	TWCR =(1<<TWINT) |(1<<TWSTO) | (1<<TWEN);
}

void i2c_Write(uint8_t u8data)
{	
	// Write a data byte to TWDR register wich is shifted to SDA line
	TWDR = u8data;
	TWCR =(1<<TWINT) | (1<<TWEN);
	// Waiting for transmission to complete
	while((TWCR & (1<<TWINT))==0);
}

uint8_t i2c_readACK(void)
{	
	// Set acknowledge bit to 1 
	TWCR =(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
}

uint8_t i2c_readNACK(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);
	return TWDR;
}

uint8_t i2c_GetStatus(void)
{
	uint8_t u8status;
	//mask prescaler bits 
	u8status = TWSR & 0xF8;
	return u8status;
}





#endif 