#include "application.h"
#include "MiniShift-Particle.h"
#include "glcdfont.h"


Minishift::Minishift(int data_pin, int clock_pin, int latch_pin) {
	this->data_pin = data_pin;
	this->clock_pin = clock_pin;
	this->latch_pin = latch_pin;
	this->latch_state = HIGH;

	pinMode(data_pin, OUTPUT);
	pinMode(clock_pin, OUTPUT);
	digitalWrite(latch_pin, HIGH);
	pinMode(latch_pin, OUTPUT);
}

void Minishift::startTransaction() {
	if(this->latch_state != LOW) {
		this->latch_state = LOW;
		digitalWrite(this->latch_pin, this->latch_state);
	}
}

void Minishift::writeColumns(const unsigned char *buf, int len) {
	this->writeColumns(buf, len, -1);
}

void Minishift::writeColumns(const unsigned char *buf, int len, int ms) {
	for(int i = 0; i < len; i++) {
		this->startTransaction();
		shiftOut(this->data_pin, this->clock_pin, LSBFIRST, buf[i]);
		this->update();
		if(ms != -1) {
			delay(ms);
		}
	}
}

void Minishift::writeString(const unsigned char *str) {
	this->writeString(str, -1);
}

void Minishift::writeString(const unsigned char *str, int ms) {
	this->writeString(str, ms, 0);
}

void Minishift::writeString(const unsigned char *str, int ms, int trailing) {
	for(const unsigned char *c = str; *c != '\0'; c++) {
		for(int col = 0; col < 5; col++) {
			this->startTransaction();
			shiftOut(this->data_pin, this->clock_pin, LSBFIRST, pgm_read_byte(font + (*c * 5) + col));
			this->update();
			if(ms != -1) {
				delay(ms);
			}
		}
		for(int col = 0; col < trailing; col++) {
			this->startTransaction();
			shiftOut(this->data_pin, this->clock_pin, LSBFIRST, 0);
			this->update();
			if(ms != -1) {
				delay(ms);
			}
		}
	}
}

void Minishift::update() {
	if(this->latch_state != HIGH) {
		this->latch_state = HIGH;
		digitalWrite(this->latch_pin, this->latch_state);
	}
}
