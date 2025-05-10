#pragma once

class Observer {
public:
	virtual ~Observer() {}
	virtual void update(double grade) = 0;
};

class Averager : public Observer {
private:
	int count = 0;
	double total = 0;
public:
	void update(double grade) override;

};

class Notifier : public Observer {
private:
	double threshold;
public:
	Notifier(double t) : threshold(t) {}
	void update(double grade) override;

};