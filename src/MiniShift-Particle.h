#ifndef MINISHIFT_H
#define MINISHIFT_H

class Minishift
{
  private:
  	int data_pin;
  	int clock_pin;
  	int latch_pin;
  	int latch_state;

  	void startTransaction();
  public:
  	Minishift(int data_pin, int clock_pin, int latch_pin);
  	void writeColumns(const unsigned char *buf, int len);
  	void writeColumns(const unsigned char *buf, int len, int ms);
  	void writeString(const unsigned char *str);
  	void writeString(const unsigned char *str, int ms);
  	void writeString(const unsigned char *str, int ms, int trailing);
  	void update();
};

#endif
